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

def run_cbmc_verification(miter_file_path: Path, unwind: int = 5, timeout: int = 45) -> Dict[str, Any]:
    """
    Executes CBMC on miter C file and extracts user-specified equivalence assertion outcomes.
    Filters specifically for equivalence assertions: [*.assertion.*].
    """
    assert miter_file_path.exists(), f"Miter file {miter_file_path} does not exist"
    
    has_native_cbmc = shutil.which("cbmc") is not None

    if has_native_cbmc:
        cmd = ["cbmc", str(miter_file_path.resolve()), "--unwind", str(unwind)]
    else:
        wsl_path = to_wsl_path(miter_file_path)
        cmd = ["wsl", "-d", "Ubuntu", "cbmc", wsl_path, "--unwind", str(unwind)]

    try:
        proc = subprocess.run(cmd, capture_output=True, text=True, timeout=timeout)
        output = proc.stdout + "\n" + proc.stderr
    except subprocess.TimeoutExpired:
        raise TimeoutError(f"CBMC verification timed out after {timeout}s for {miter_file_path}")

    output_lines = [line.strip() for line in output.splitlines() if line.strip()]
    tail = "\n".join(output_lines[-15:]) if output_lines else "<no output>"

    # Accept only exit codes meaning "verification completed":
    # 0 = verification successful (all assertions hold)
    # 10 = verification failed (at least one assertion violated)
    if proc.returncode not in (0, 10):
        raise RuntimeError(
            f"CBMC verification failed for {miter_file_path.name} with exit code {proc.returncode} "
            f"(expected 0 or 10). Output tail:\n{tail}"
        )

    has_result_line = ("VERIFICATION SUCCESSFUL" in output) or ("VERIFICATION FAILED" in output)
    if not has_result_line:
        raise RuntimeError(
            f"CBMC verification for {miter_file_path.name} ended with exit code {proc.returncode} "
            f"but output lacks a verification result line. Output tail:\n{tail}"
        )

    # Match equivalence assertions, e.g.:
    # [main.assertion.1] line 41 assertion v_1 == v_2: FAILURE
    assertion_pattern = re.compile(r"\[([^\]]*\.assertion\.\d+)\]\s+line\s+\d+\s+assertion\s+([^:]+):\s+(SUCCESS|FAILURE)")
    
    total_assertions = 0
    failed_assertions = 0
    failed_details = []

    for match in assertion_pattern.finditer(output):
        prop_id, expr, status = match.groups()
        total_assertions += 1
        if status.strip() == "FAILURE":
            failed_assertions += 1
            failed_details.append({
                "property": prop_id.strip(),
                "assertion": expr.strip()
            })

    # Fallback to summary line if regex matches fewer than summary
    summary_match = re.search(r"\*\*\s+(\d+)\s+of\s+(\d+)\s+failed", output)
    if summary_match and total_assertions == 0:
        f_cnt, t_cnt = int(summary_match.group(1)), int(summary_match.group(2))
        failed_assertions = f_cnt
        total_assertions = t_cnt

    if total_assertions < 1:
        raise RuntimeError(
            f"CBMC verification for {miter_file_path.name} parsed 0 assertions (expected >= 1). "
            f"Output tail:\n{tail}"
        )

    status_str = "SUCCESSFUL" if proc.returncode == 0 else "FAILED"
    return {
        "actual_mqil_leakage": failed_assertions,
        "actual_mqil_assertions_total": total_assertions,
        "mqil_leak_ratio": round(failed_assertions / total_assertions, 4),
        "failed_details": failed_details,
        "cbmc_verified": True,
        "cbmc_exit_code": proc.returncode,
        "cbmc_status": status_str
    }

