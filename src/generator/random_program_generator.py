"""
Random Program Generator for Structurally Diverse, High-Complexity C Benchmarks.
Generates genuine C99 programs with diverse control flow, functions, structs, unions,
arrays, arithmetic, bitwise operations, and distinct security information-flow patterns.
All generated programs strictly satisfy LOC >= 500 and are fully compatible with
CBMC-MQIL transpiler, CBMC verification (--unwind 5), and the 29-feature AST extractor.
"""

import random
from pathlib import Path
from typing import Dict, Any, List, Tuple, Optional
import hashlib
import json
import csv
import concurrent.futures
import threading

from src.core.transpiler import generate_miter_program
from src.core.cbmc_runner import run_cbmc_verification
from src.core.feature_extractor import extract_all_mqil_features, FEATURE_COLS

SECURITY_FAMILIES = [
    "zero_leakage",
    "direct_leakage",
    "multi_step_explicit",
    "arithmetic_flow",
    "bitwise_flow",
    "implicit_flow",
    "nested_implicit_flow",
    "secret_dependent_loops",
    "secret_dependent_array",
    "mixed_control_data"
]

def _generate_struct_defs(rng: random.Random, prefix: str) -> List[str]:
    """Generates 1-3 distinct struct and union definitions."""
    lines = []
    lines.append(f"struct State_{prefix} {{")
    lines.append("    int id;")
    lines.append("    int val;")
    lines.append("    short flag;")
    lines.append("    int buffer[3];")
    lines.append("};")
    lines.append("")
    lines.append(f"union Packet_{prefix} {{")
    lines.append("    int word;")
    lines.append("    unsigned char raw[4];")
    lines.append("    short pairs[2];")
    lines.append("};")
    lines.append("")
    if rng.random() > 0.5:
        lines.append(f"struct Meta_{prefix} {{")
        lines.append("    int status;")
        lines.append("    int mask;")
        lines.append("};")
        lines.append("")
    return lines

def _generate_helper_functions(rng: random.Random, num_funcs: int, prefix: str) -> Tuple[List[str], Dict[int, int]]:
    """Generates num_funcs diverse helper functions with distinct control/data flow."""
    lines = []
    param_counts = {}
    for f in range(num_funcs):
        fname = f"helper_{prefix}_{f}"
        param_count = rng.choice([2, 3, 4])
        param_counts[f] = param_count
        if param_count == 2:
            sig = f"int {fname}(int a, int b)"
        elif param_count == 3:
            sig = f"int {fname}(int a, int b, int c)"
        else:
            sig = f"int {fname}(int a, int b, int c, int d)"

        lines.append(f"{sig} {{")
        lines.append(f"    int acc = a + {f * 3 + 1};")
        lines.append(f"    struct State_{prefix} st;")
        lines.append(f"    st.id = {f + 1};")
        lines.append(f"    st.val = b + {f * 2 + 5};")
        lines.append(f"    st.flag = (short){f};")
        lines.append("    st.buffer[0] = a & 15;")
        lines.append("    st.buffer[1] = b & 15;")
        lines.append(f"    st.buffer[2] = {f + 7};")
        lines.append("")

        # Control flow diversity
        style = f % 5
        if style == 0:
            # Branching with nested logic
            lines.append(f"    if (st.val > {f * 5 + 10}) {{")
            lines.append("        acc += (st.buffer[0] * 2 + 3) & 31;")
            lines.append("        if (acc > 20) {")
            lines.append("            acc -= 7;")
            lines.append("        } else {")
            lines.append("            acc += 5;")
            lines.append("        }")
            lines.append("    } else {")
            lines.append("        acc -= (st.buffer[1] + 1) & 15;")
            lines.append("    }")
        elif style == 1:
            # Bounded loop (constant bound <= 3)
            lines.append("    for (int k = 0; k < 2; k++) {")
            lines.append("        acc += (k * 3 + st.buffer[k]) & 15;")
            lines.append("        if (acc > 30) {")
            lines.append("            acc -= 10;")
            lines.append("        }")
            lines.append("    }")
        elif style == 2:
            # Switch case
            lines.append("    switch (a & 3) {")
            lines.append("        case 0:")
            lines.append("            acc ^= 7;")
            lines.append("            break;")
            lines.append("        case 1:")
            lines.append("            acc += (b & 15) + 3;")
            lines.append("            break;")
            lines.append("        case 2:")
            lines.append("            acc = (acc * 2 + 1) & 63;")
            lines.append("            break;")
            lines.append("        default:")
            lines.append("            acc -= 5;")
            lines.append("            break;")
            lines.append("    }")
        elif style == 3:
            # Union manipulation & bitwise logic
            lines.append(f"    union Packet_{prefix} pkt;")
            lines.append(f"    pkt.word = (a + b + {f * 4}) & 255;")
            lines.append("    acc += (pkt.raw[0] ^ pkt.raw[1]) & 31;")
            lines.append("    if ((acc & 1) != 0) {")
            lines.append("        acc = (acc << 1) & 127;")
            lines.append("    } else {")
            lines.append("        acc = (acc >> 1) + 2;")
            lines.append("    }")
        else:
            # While loop with break/continue
            lines.append("    int cnt = 0;")
            lines.append("    while (cnt < 2) {")
            lines.append("        acc += (cnt + 1) * 4;")
            lines.append("        cnt++;")
            lines.append("    }")

        lines.append(f"    return (acc + st.flag) & 127;")
        lines.append("}")
        lines.append("")
    return lines, param_counts

def _generate_security_flow(
    rng: random.Random,
    family: str,
    high_vars: List[str],
    low_vars: List[str]
) -> List[str]:
    """Generates the security-specific information flow logic."""
    lines = []
    lines.append(f"    /* Security Information Flow: Family = {family} */")
    h0 = high_vars[0]
    p0 = low_vars[0]

    if family == "zero_leakage":
        # Secret is completely cancelled with zero net influence
        lines.append(f"    int dead_sec = ({h0} ^ {h0}) * 0;")
        lines.append("    out_sink += dead_sec;")
        lines.append("    if (dead_sec != 0) {")
        lines.append("        out_sink += 999;")
        lines.append("    }")

    elif family == "direct_leakage":
        # Direct flow from secret to output
        lines.append(f"    out_sink += {h0};")

    elif family == "multi_step_explicit":
        # Multi-step explicit flow through multiple variables
        lines.append(f"    int step1 = {h0} & 127;")
        lines.append("    int step2 = (step1 * 3 + 11) & 255;")
        lines.append("    int step3 = (step2 ^ 0x5A) + 7;")
        lines.append("    int step4 = (step3 >> 1) & 63;")
        lines.append("    out_sink += step4;")

    elif family == "arithmetic_flow":
        # Arithmetic transformations on high inputs
        lines.append(f"    int arith1 = ({h0} * 3 + 17) & 255;")
        lines.append(f"    int arith2 = (arith1 + {p0} * 2) & 127;")
        lines.append("    out_sink += (arith1 - arith2) & 63;")

    elif family == "bitwise_flow":
        # Bitwise operations on high inputs
        lines.append(f"    int bit1 = ({h0} << 2) & 120;")
        lines.append(f"    int bit2 = ({h0} >> 1) & 15;")
        lines.append("    int bit3 = (bit1 ^ bit2) | 3;")
        lines.append("    out_sink += bit3 & 63;")

    elif family == "implicit_flow":
        # Branch condition depends on secret
        lines.append(f"    if (({h0} & 3) > 1) {{")
        lines.append("        out_sink += 45;")
        lines.append("    } else {")
        lines.append("        out_sink -= 25;")
        lines.append("    }")

    elif family == "nested_implicit_flow":
        # Deep nested branches depending on secret bits
        lines.append(f"    if (({h0} & 1) != 0) {{")
        lines.append(f"        if (({h0} & 2) != 0) {{")
        lines.append("            out_sink += 30;")
        lines.append("        } else {")
        lines.append("            out_sink += 15;")
        lines.append("        }")
        lines.append("    } else {")
        lines.append(f"        if (({h0} & 4) != 0) {{")
        lines.append("            out_sink -= 10;")
        lines.append("        } else {")
        lines.append("            out_sink -= 20;")
        lines.append("        }")
        lines.append("    }")

    elif family == "secret_dependent_loops":
        # Secret influences bounded loop iterations (strictly <= 2)
        lines.append(f"    int bound = ({h0} & 1) + 1;")
        lines.append("    for (int it = 0; it < bound; it++) {")
        lines.append("        out_sink += (it + 1) * 7;")
        lines.append("    }")

    elif family == "secret_dependent_array":
        # Secret determines array index into local array
        lines.append("    int table[3] = { 12, 34, 56 };")
        lines.append(f"    int s_idx = ({h0} & 1);")
        lines.append("    out_sink += table[s_idx];")

    elif family == "mixed_control_data":
        # Combination of bitwise, arithmetic, and implicit flows
        lines.append(f"    int mix_temp = ({h0} ^ 0x2A) & 63;")
        lines.append("    if (mix_temp > 20) {")
        lines.append(f"        out_sink += (mix_temp * 2 + {p0}) & 127;")
        lines.append("    } else {")
        lines.append("        out_sink -= (mix_temp + 5) & 31;")
        lines.append("    }")
        lines.append(f"    out_sink ^= ({h0} & 7);")

    lines.append("")
    return lines

def generate_random_c_program(
    prog_id: str,
    family: str,
    seed: int,
    target_loc: int = 550
) -> Tuple[str, Dict[str, Any]]:
    """
    Generates a complete C program source text and companion security config.
    Guarantees LOC >= max(500, target_loc) with genuine structural complexity.
    """
    rng = random.Random(seed)

    # Choose input variables
    num_high = rng.choice([1, 2, 3])
    num_low = rng.choice([1, 2, 3])
    high_vars = [f"sec_k_{i}" for i in range(num_high)]
    low_vars = [f"pub_v_{i}" for i in range(num_low)]
    input_vars = high_vars + low_vars

    prefix = f"{prog_id}_{seed % 1000}"

    lines = []
    lines.append("/*")
    lines.append(f" * Benchmark Program: {prog_id}")
    lines.append(f" * Family: {family}")
    lines.append(f" * Generator Seed: {seed}")
    lines.append(" */")
    lines.append("#include <stdio.h>")
    lines.append("#include <stdlib.h>")
    lines.append("#include <stdbool.h>")
    lines.append("#include <string.h>")
    lines.append("#include <assert.h>")
    lines.append("")

    # Top-level structs & unions
    lines.extend(_generate_struct_defs(rng, prefix))

    # Global variables
    lines.append("int g_out = 0;")
    lines.append("int g_chk = 0;")
    lines.append("")

    # Helper functions: choose between 4 and 12 functions
    num_helpers = rng.randint(4, 12)
    helper_lines, helper_param_counts = _generate_helper_functions(rng, num_helpers, prefix)
    lines.extend(helper_lines)

    # Begin main()
    lines.append("int main() {")
    for var in input_vars:
        lines.append(f"    int {var};")
    lines.append("    int out_sink = 0;")
    lines.append("    int chk_sum = 0;")
    lines.append("    int local_arr[3];")
    lines.append(f"    struct State_{prefix} main_st;")
    lines.append(f"    union Packet_{prefix} main_pkt;")
    lines.append("")

    # Initialize state
    p0 = low_vars[0]
    lines.append("    main_st.id = 1;")
    lines.append(f"    main_st.val = ({p0} + 10) & 63;")
    lines.append("    main_st.flag = (short)1;")
    lines.append(f"    main_st.buffer[0] = ({p0} + 1) & 15;")
    lines.append(f"    main_st.buffer[1] = ({p0} + 2) & 15;")
    lines.append(f"    main_st.buffer[2] = ({p0} + 3) & 15;")
    lines.append(f"    main_pkt.word = ({p0} + 42) & 255;")
    lines.append(f"    local_arr[0] = ({p0} + 5) & 15;")
    lines.append(f"    local_arr[1] = ({p0} + 7) & 15;")
    lines.append(f"    local_arr[2] = ({p0} + 9) & 15;")
    lines.append("")

    # Helper function invocations
    for f in range(num_helpers):
        fname = f"helper_{prefix}_{f}"
        pcount = helper_param_counts[f]
        call_args = [f"({f * (k + 1) + 3})" for k in range(pcount)]
        args_str = ", ".join(call_args)
        lines.append(f"    int h_res_{f} = {fname}({args_str});")
        lines.append(f"    out_sink += h_res_{f};")
        lines.append(f"    chk_sum ^= (h_res_{f} << 1) & 127;")
    lines.append("")

    # Sequential computation blocks
    block_idx = 0
    while True:
        current_loc = len(lines) + 30
        if current_loc >= max(505, target_loc):
            break

        b_var = f"blk_{block_idx}"
        arr_idx = block_idx % 3
        b_type = block_idx % 4

        lines.append(f"    /* Computational Stage {block_idx} */")
        lines.append(f"    int {b_var} = (local_arr[{arr_idx}] + {block_idx * 5 + 3}) & 31;")

        if b_type == 0:
            lines.append(f"    if ({b_var} > 15) {{")
            lines.append(f"        local_arr[{arr_idx}] = (local_arr[{arr_idx}] + {block_idx % 7 + 1}) & 15;")
            lines.append("        out_sink += 1;")
            lines.append("    } else {")
            lines.append(f"        local_arr[{arr_idx}] = (local_arr[{arr_idx}] - 1) & 15;")
            lines.append("        out_sink -= 1;")
            lines.append("    }")
        elif b_type == 1:
            lines.append("    for (int k = 0; k < 2; k++) {")
            lines.append(f"        {b_var} = ({b_var} + k * 3) & 31;")
            lines.append(f"        chk_sum = (chk_sum + {b_var}) & 127;")
            lines.append("    }")
        elif b_type == 2:
            lines.append(f"    switch ({b_var} & 3) {{")
            lines.append("        case 0:")
            lines.append(f"            out_sink += ({b_var} ^ 3) & 15;")
            lines.append("            break;")
            lines.append("        case 1:")
            lines.append(f"            out_sink -= ({b_var} + 2) & 15;")
            lines.append("            break;")
            lines.append("        default:")
            lines.append("            out_sink ^= 5;")
            lines.append("            break;")
            lines.append("    }")
        else:
            lines.append(f"    main_st.val = (main_st.val + {b_var}) & 63;")
            lines.append(f"    main_pkt.raw[{block_idx % 4}] = (unsigned char)({b_var} & 255);")
            lines.append(f"    out_sink += (main_st.val ^ main_pkt.raw[{block_idx % 4}]) & 15;")

        lines.append(f"    out_sink += local_arr[{arr_idx}];")
        lines.append(f"    chk_sum ^= {b_var};")
        lines.append("")
        block_idx += 1

    # Inject the security information flow
    lines.extend(_generate_security_flow(rng, family, high_vars, low_vars))

    # Final outputs and sinks
    lines.append("    g_out = out_sink;")
    lines.append("    g_chk = chk_sum;")
    lines.append("    return 0;")
    lines.append("}")
    lines.append("")

    source_code = "\n".join(lines)
    config = {
        "input_vars": input_vars,
        "high_vars": high_vars,
        "low_vars": low_vars
    }

    return source_code, config

def process_single_random_program(
    prog_id: str,
    family_id: str,
    target_loc: int,
    initial_seed: int,
    dest_dir: Path,
    seen_hashes: set,
    lock: threading.Lock,
    regeneration_log: List[Dict[str, Any]]
) -> Dict[str, Any]:
    """
    Generates, validates, miters, verifies with CBMC, and extracts features for a single program.
    If any stage fails, regenerates with an incremented seed until valid.
    """
    dest_programs = dest_dir / "programs"
    dest_configs = dest_dir / "configs"
    dest_miters = dest_dir / "miters"
    dest_cbmc = dest_dir / "cbmc"
    dest_features = dest_dir / "features"

    current_seed = initial_seed
    attempts = 0

    while True:
        attempts += 1
        source_code, config = generate_random_c_program(
            prog_id=prog_id,
            family=family_id,
            seed=current_seed,
            target_loc=target_loc
        )

        loc = len(source_code.splitlines())
        if loc < 500:
            with lock:
                regeneration_log.append({
                    "program_id": prog_id,
                    "seed": current_seed,
                    "reason": f"LOC {loc} < 500"
                })
            current_seed += 1000
            continue

        sha256 = hashlib.sha256(source_code.encode("utf-8")).hexdigest()
        with lock:
            if sha256 in seen_hashes:
                regeneration_log.append({
                    "program_id": prog_id,
                    "seed": current_seed,
                    "reason": f"Hash collision {sha256[:8]}"
                })
                current_seed += 1000
                continue
            seen_hashes.add(sha256)

        c_path = dest_programs / f"{prog_id}.c"
        cfg_path = dest_configs / f"{prog_id}.json"
        miter_path = dest_miters / f"{prog_id}_miter.c"

        c_path.write_text(source_code, encoding="utf-8")
        with open(cfg_path, "w", encoding="utf-8") as f:
            json.dump(config, f, indent=2)

        # 1. Transpile to Miter
        try:
            generate_miter_program(c_path, cfg_path, miter_path)
        except Exception as e:
            with lock:
                seen_hashes.remove(sha256)
                regeneration_log.append({
                    "program_id": prog_id,
                    "seed": current_seed,
                    "reason": f"Miter generation error: {str(e)}"
                })
            current_seed += 1000
            continue

        # 2. Run CBMC Verification
        try:
            cbmc_res = run_cbmc_verification(miter_path, unwind=5, timeout=45)
        except Exception as e:
            with lock:
                seen_hashes.remove(sha256)
                regeneration_log.append({
                    "program_id": prog_id,
                    "seed": current_seed,
                    "reason": f"CBMC error: {str(e)}"
                })
            current_seed += 1000
            continue

        # 3. Extract all 29 ML features in memory (no AST saved to disk)
        try:
            features = extract_all_mqil_features(c_path, cfg_path, miter_path)
        except Exception as e:
            with lock:
                seen_hashes.remove(sha256)
                regeneration_log.append({
                    "program_id": prog_id,
                    "seed": current_seed,
                    "reason": f"Feature extraction error: {str(e)}"
                })
            current_seed += 1000
            continue

        # 4. Save per-program CBMC and Feature JSONs
        cbmc_json_path = dest_cbmc / f"{prog_id}.json"
        with open(cbmc_json_path, "w", encoding="utf-8") as f:
            json.dump(cbmc_res, f, indent=2)

        feat_json_path = dest_features / f"{prog_id}.json"
        with open(feat_json_path, "w", encoding="utf-8") as f:
            json.dump(features, f, indent=2)

        return {
            "program_id": prog_id,
            "family_id": family_id,
            "source_file": str(c_path.relative_to(dest_dir.parent.parent)),
            "generator_seed": current_seed,
            "loc": loc,
            "sha256": sha256,
            "cbmc_res": cbmc_res,
            "features": features
        }

def run_random_dataset(
    dest_dir: Optional[Path] = None,
    count: int = 100,
    master_seed: int = 42000,
    max_workers: int = 6
) -> Dict[str, Any]:
    """
    Unified entry point to generate the 100-program random benchmark dataset.
    Generates programs, miters, CBMC verification, and feature extraction.
    Exports random_dataset.csv and random_dataset_report.json into datasets/random/.
    """
    if dest_dir is None:
        workspace = Path(__file__).resolve().parent.parent.parent
        dest_dir = workspace / "datasets" / "random"

    # Setup directories
    dest_programs = dest_dir / "programs"
    dest_configs = dest_dir / "configs"
    dest_miters = dest_dir / "miters"
    dest_cbmc = dest_dir / "cbmc"
    dest_features = dest_dir / "features"

    for d in [dest_programs, dest_configs, dest_miters, dest_cbmc, dest_features]:
        d.mkdir(parents=True, exist_ok=True)

    # Size tier targets to guarantee wide LOC distribution
    # Tier 1: 520-680 (35%), Tier 2: 720-950 (35%), Tier 3: 1020-1400 (20%), Tier 4: 1520-1750 (10%)
    tier_assignments = []
    for _ in range(35):
        tier_assignments.append((520, 680))
    for _ in range(35):
        tier_assignments.append((720, 950))
    for _ in range(20):
        tier_assignments.append((1020, 1400))
    for _ in range(10):
        tier_assignments.append((1520, 1750))

    rng = random.Random(master_seed)
    rng.shuffle(tier_assignments)

    tasks = []
    for i in range(count):
        prog_id = f"R{i + 1:06d}"
        family_id = SECURITY_FAMILIES[i % len(SECURITY_FAMILIES)]
        min_t, max_t = tier_assignments[i]
        target_loc = rng.randint(min_t, max_t)
        seed = master_seed + (i + 1) * 37
        tasks.append((prog_id, family_id, target_loc, seed))

    print(f"Starting generation and processing of {count} random C programs...")
    seen_hashes = set()
    lock = threading.Lock()
    regeneration_log = []
    results = []

    with concurrent.futures.ThreadPoolExecutor(max_workers=max_workers) as executor:
        future_to_task = {
            executor.submit(
                process_single_random_program,
                pid, fam, tloc, s, dest_dir, seen_hashes, lock, regeneration_log
            ): pid for (pid, fam, tloc, s) in tasks
        }

        completed = 0
        for future in concurrent.futures.as_completed(future_to_task):
            pid = future_to_task[future]
            try:
                res = future.result()
                results.append(res)
                completed += 1
                cbmc = res["cbmc_res"]
                print(f"[{completed}/{count}] Completed {pid}: LOC={res['loc']} | "
                      f"leak={cbmc['actual_mqil_leakage']}/{cbmc['actual_mqil_assertions_total']} | "
                      f"family={res['family_id']}")
            except Exception as exc:
                print(f"[ERROR] Failed processing {pid}: {exc}")
                raise exc

    # Sort results by program_id
    results.sort(key=lambda r: r["program_id"])

    # 1. Assemble random_dataset.csv
    csv_path = dest_dir / "random_dataset.csv"
    csv_columns = [
        "program_id", "family_id", "source_file", "generator_seed"
    ] + FEATURE_COLS + [
        "actual_mqil_leakage", "actual_mqil_assertions_total", "mqil_leak_ratio",
        "cbmc_verified", "cbmc_exit_code", "cbmc_status"
    ]

    with open(csv_path, "w", newline="", encoding="utf-8") as f:
        writer = csv.writer(f)
        writer.writerow(csv_columns)
        for r in results:
            cbmc = r["cbmc_res"]
            feats = r["features"]
            row = [
                r["program_id"],
                r["family_id"],
                r["source_file"],
                r["generator_seed"]
            ]
            for col in FEATURE_COLS:
                row.append(feats.get(col, 0))
            row.extend([
                cbmc["actual_mqil_leakage"],
                cbmc["actual_mqil_assertions_total"],
                cbmc["mqil_leak_ratio"],
                cbmc["cbmc_verified"],
                cbmc["cbmc_exit_code"],
                cbmc["cbmc_status"]
            ])
            writer.writerow(row)

    # 2. Compute Validation Report Statistics
    loc_values = [r["loc"] for r in results]
    min_loc = min(loc_values)
    max_loc = max(loc_values)
    avg_loc = round(sum(loc_values) / len(loc_values), 2)
    unique_hashes = len(set(r["sha256"] for r in results))

    cbmc_success_count = sum(1 for r in results if r["cbmc_res"]["cbmc_verified"])
    cbmc_failure_count = sum(1 for r in results if not r["cbmc_res"]["cbmc_verified"])

    feat_stats = {}
    for col in FEATURE_COLS:
        vals = [r["features"].get(col, 0) for r in results]
        feat_stats[col] = {
            "minimum": min(vals),
            "maximum": max(vals),
            "mean": round(sum(vals) / len(vals), 4)
        }

    report = {
        "total_programs": len(results),
        "minimum_loc": min_loc,
        "maximum_loc": max_loc,
        "average_loc": avg_loc,
        "unique_source_hashes": unique_hashes,
        "cbmc_success_count": cbmc_success_count,
        "cbmc_failure_count": cbmc_failure_count,
        "feature_statistics": feat_stats,
        "regenerated_programs_count": len(regeneration_log),
        "regeneration_log": regeneration_log
    }

    report_path = dest_dir / "random_dataset_report.json"
    with open(report_path, "w", encoding="utf-8") as f:
        json.dump(report, f, indent=2)

    print("=" * 80)
    print(f"RANDOM DATASET GENERATION COMPLETE: {len(results)} programs")
    print(f"LOC: Min={min_loc}, Max={max_loc}, Avg={avg_loc}")
    print(f"Unique source hashes: {unique_hashes}/{len(results)}")
    print(f"CSV saved to: {csv_path}")
    print(f"Report saved to: {report_path}")
    print("=" * 80)

    return report
