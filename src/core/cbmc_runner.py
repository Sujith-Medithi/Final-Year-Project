"""
CBMC Execution Runner.
Invokes CBMC (via native binary or Ubuntu WSL) on synthesized whole-program miters
and parses verification assertion outcomes to determine ground-truth information leakage (#leak).
"""

from pathlib import Path
import re
import subprocess
import shutil
from typing import Dict, Any

def to_wsl_path(win_path: Path) -> str:
    """Converts a Windows Path to a WSL path (/mnt/c/...)."""
    resolved = win_path.resolve()
    drive = resolved.drive.replace(":", "").lower()
    posix_path = resolved.as_posix()
    path_without_drive = posix_path[2:]
    return f"/mnt/{drive}{path_without_drive}"

def parse_cbmc_output(output: str, exit_code: int = 0, program_name: str = "") -> Dict[str, Any]:
    """
    Parses raw CBMC output, distinguishing between user/MQIL equivalence assertions
    ([*.assertion.N]), incomplete unwinding failures ([*unwind*]), and CBMC safety checks (e.g. [*.overflow.*]).
    """
    has_result_line = ("VERIFICATION SUCCESSFUL" in output) or ("VERIFICATION FAILED" in output)

    # Match all property outcome lines, greedily capturing description up to final ': SUCCESS', ': FAILURE', or ': UNKNOWN'
    prop_pattern = re.compile(
        r"^\[(?P<prop>[^\]]+)\](?:\s+line\s+\d+)?\s+(?P<desc>.*):\s+(?P<status>SUCCESS|FAILURE|UNKNOWN|DISABLED)\s*$",
        re.MULTILINE
    )

    actual_mqil_assertions_total = 0
    actual_mqil_leakage = 0
    failed_details = []
    total_safety_checks = 0
    safety_failures = []
    total_unwinding_checks = 0
    unwinding_failures = []

    for match in prop_pattern.finditer(output):
        prop_id = match.group("prop").strip()
        desc = match.group("desc").strip()
        status = match.group("status").strip()

        # 1. MQIL assertions match pattern: *.assertion.N
        if re.search(r"(?:^|\.)assertion\.\d+$", prop_id):
            actual_mqil_assertions_total += 1
            if status == "FAILURE":
                # TODO: Confirm whether MQIL defines #leak as:
                # 1. the number of failed equivalence assertions,
                # 2. the number of distinct leaked low-security output variables, or
                # 3. a binary leakage indicator.
                # This must be validated using a direct-leakage benchmark before bulk dataset generation.
                actual_mqil_leakage += 1
                expr = re.sub(r"^assertion\s+", "", desc).strip()
                failed_details.append({
                    "property": prop_id,
                    "assertion": expr
                })
        # 2. Incomplete unwinding assertions: property ID contains unwind
        elif "unwind" in prop_id:
            total_unwinding_checks += 1
            if status == "FAILURE":
                unwinding_failures.append(prop_id)
        # 3. CBMC safety properties (e.g., overflow, bounds, pointer, memory, division)
        else:
            total_safety_checks += 1
            if status == "FAILURE":
                safety_failures.append(prop_id)

    # Summary line consistency check: ** X of Y failed
    summary_match = re.search(r"\*\*\s+(\d+)\s+of\s+(\d+)\s+failed", output)
    if summary_match:
        summary_failed = int(summary_match.group(1))
        summary_total = int(summary_match.group(2))
        total_parsed = actual_mqil_assertions_total + total_unwinding_checks + total_safety_checks
        total_failed_parsed = actual_mqil_leakage + len(unwinding_failures) + len(safety_failures)
        if total_parsed != summary_total or total_failed_parsed != summary_failed:
            tail_2000 = output[-2000:]
            raise RuntimeError(
                f"CBMC summary consistency check failed for {program_name}:\n"
                f"Regex counts: parsed_total={total_parsed}, parsed_failed={total_failed_parsed}\n"
                f"Summary counts: summary_total={summary_total}, summary_failed={summary_failed}\n"
                f"CBMC output tail (last 2000 characters):\n{tail_2000}"
            )

    overall_cbmc_status = "SUCCESSFUL" if exit_code == 0 else "FAILED"

    if len(unwinding_failures) > 0:
        dataset_status = "INCOMPLETE_UNWINDING"
        leakage_result = "UNKNOWN"
        safety_result = "UNKNOWN"
        actual_mqil_leakage_val = None
        error_msg = None
    elif actual_mqil_assertions_total == 0 or not has_result_line:
        dataset_status = "INVALID"
        leakage_result = "FAILED"
        safety_result = "SUCCESSFUL" if len(safety_failures) == 0 else "FAILED"
        actual_mqil_leakage_val = actual_mqil_leakage if actual_mqil_assertions_total > 0 else None
        error_msg = "No leakage assertions parsed or missing verification result line"
    elif len(safety_failures) > 0:
        dataset_status = "INVALID_UNSAFE_PROGRAM"
        leakage_result = "SUCCESSFUL" if actual_mqil_leakage == 0 else "FAILED"
        safety_result = "FAILED"
        actual_mqil_leakage_val = actual_mqil_leakage
        error_msg = None
    elif actual_mqil_leakage > 0:
        dataset_status = "LEAKAGE_DETECTED"
        leakage_result = "FAILED"
        safety_result = "SUCCESSFUL"
        actual_mqil_leakage_val = actual_mqil_leakage
        error_msg = None
    else:
        dataset_status = "VALID"
        leakage_result = "SUCCESSFUL"
        safety_result = "SUCCESSFUL"
        actual_mqil_leakage_val = actual_mqil_leakage
        error_msg = None

    mqil_leak_ratio = round(actual_mqil_leakage / actual_mqil_assertions_total, 4) if (actual_mqil_assertions_total > 0 and actual_mqil_leakage_val is not None) else 0.0

    return {
        "program": program_name,
        "actual_mqil_leakage": actual_mqil_leakage_val,
        "actual_mqil_assertions_total": actual_mqil_assertions_total,
        "mqil_leak_ratio": mqil_leak_ratio,
        "leakage_result": leakage_result,
        "safety_failures": safety_failures,
        "safety_result": safety_result,
        "unwinding_failures": unwinding_failures,
        "overall_cbmc_status": overall_cbmc_status,
        "dataset_status": dataset_status,
        "cbmc_exit_code": exit_code,
        "failed_details": failed_details,
        "error": error_msg,
        # Backward compatibility keys
        "cbmc_verified": (actual_mqil_assertions_total > 0 and has_result_line),
        "cbmc_status": overall_cbmc_status
    }

def run_cbmc_verification(miter_file_path: Path, unwind: int = 5, timeout: int = 45) -> Dict[str, Any]:
    """
    Executes CBMC on miter C file and returns separate leakage, safety, and unwinding outcomes.
    Filters user/MQIL equivalence assertions [*.assertion.N] separately from CBMC safety and unwinding checks.
    """
    if not miter_file_path.exists():
        raise FileNotFoundError(
            f"Miter file does not exist: {miter_file_path}"
        )
    
    has_native_cbmc = shutil.which("cbmc") is not None

    if has_native_cbmc:
        cmd = [
            "cbmc",
            str(miter_file_path.resolve()),
            "--unwind", str(unwind),
            "--unwinding-assertions",
        ]
    else:
        wsl_path = to_wsl_path(miter_file_path)
        cmd = [
            "wsl", "-d", "Ubuntu",
            "cbmc",
            wsl_path,
            "--unwind", str(unwind),
            "--unwinding-assertions",
        ]

    cbmc_cmd_str = " ".join(cmd)
    log_file = miter_file_path.parent / f"{miter_file_path.name}.cbmc.log"

    try:
        proc = subprocess.run(
            cmd,
            capture_output=True,
            text=True,
            encoding="utf-8",
            errors="replace",
            timeout=timeout,
        )
        output = proc.stdout + "\n" + proc.stderr
    except subprocess.TimeoutExpired:
        # Return structured timeout result without crashing the pipeline
        try:
            log_file.write_text(f"TIMEOUT after {timeout}s\nCommand: {cbmc_cmd_str}\n", encoding="utf-8")
        except Exception:
            pass
        return {
            "program": str(miter_file_path),
            "actual_mqil_leakage": None,
            "actual_mqil_assertions_total": 0,
            "mqil_leak_ratio": 0.0,
            "leakage_result": "FAILED",
            "safety_failures": [],
            "safety_result": "FAILED",
            "unwinding_failures": [],
            "overall_cbmc_status": "TIMEOUT",
            "dataset_status": "INVALID",
            "cbmc_exit_code": -1,
            "cbmc_command": cbmc_cmd_str,
            "cbmc_log": str(log_file),
            "failed_details": [],
            "error": f"CBMC verification timed out after {timeout}s",
            "cbmc_verified": False,
            "cbmc_status": "TIMEOUT"
        }

    # Save raw stdout and stderr to .cbmc.log beside the miter
    try:
        log_file.write_text(output, encoding="utf-8")
    except Exception:
        pass

    output_lines = [line.strip() for line in output.splitlines() if line.strip()]
    tail = "\n".join(output_lines[-15:]) if output_lines else "<no output>"

    # Handle unexpected exit codes without crashing the pipeline
    if proc.returncode not in (0, 10):
        return {
            "program": str(miter_file_path),
            "actual_mqil_leakage": None,
            "actual_mqil_assertions_total": 0,
            "mqil_leak_ratio": 0.0,
            "leakage_result": "FAILED",
            "safety_failures": [],
            "safety_result": "FAILED",
            "unwinding_failures": [],
            "overall_cbmc_status": f"EXIT_{proc.returncode}",
            "dataset_status": "INVALID",
            "cbmc_exit_code": proc.returncode,
            "cbmc_command": cbmc_cmd_str,
            "cbmc_log": str(log_file),
            "failed_details": [],
            "error": f"CBMC verification ended with exit code {proc.returncode}. Output tail:\n{tail}",
            "cbmc_verified": False,
            "cbmc_status": f"EXIT_{proc.returncode}"
        }

    parsed = parse_cbmc_output(output, exit_code=proc.returncode, program_name=str(miter_file_path))
    parsed["cbmc_command"] = cbmc_cmd_str
    parsed["cbmc_log"] = str(log_file)
    if parsed["error"] is not None:
        parsed["error"] = f"{parsed['error']}. Output tail:\n{tail}"

    return parsed


