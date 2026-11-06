"""
Random Program Generator V5: High-Scale, Ultra-Diverse C Benchmarks with High-Range Information Leakage.
Restores the 10 Canonical Security Families with deeply propagated leakage mechanisms:
  1. zero_leakage             - Zero leakage baseline via identity nullifiers
  2. direct_leakage           - Multi-secret direct accumulation into pipeline
  3. multi_step_explicit      - Deep multi-step assignment and helper function chains
  4. arithmetic_flow          - Cascading arithmetic pipelines across stages
  5. bitwise_flow             - Dense bitwise manipulation and struct buffer cascades
  6. implicit_flow            - Secret-controlled branch conditions (culprit blocks)
  7. nested_implicit_flow     - Multi-level nested culprit branches modifying internal state
  8. secret_dependent_loops   - Loop bounds and iterations controlled by secrets
  9. secret_dependent_array   - Secret-indexed lookup tables and array mutation
  10. mixed_control_data      - Heavy composite entanglement of dataflow and control flow

Constraints:
  - Strict 2000 <= LOC <= 2500
  - High inputs: num_high_inputs > 15 (16 to 24) and num_low_inputs > 15 (16 to 24)
  - High variables: 350 to 600+ variables
  - High range of information leak (from 0 up to 250+ leaked variables across families)
  - 100% mathematical invariant compliance
"""

import random
import sys
from pathlib import Path
from typing import Dict, Any, List, Tuple, Optional, Set
import hashlib
import json
import csv
import concurrent.futures
import threading
import time

WORKSPACE = Path(__file__).resolve().parent.parent.parent
sys.path.insert(0, str(WORKSPACE))

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

STRUCT_THEMES = [
    ("SensorNode", ["reading", "calib", "status", "gain", "threshold", "offset"]),
    ("MatrixBlock", ["dim", "stride", "determinant", "scale", "trace", "density"]),
    ("CipherContext", ["round_key", "nonce", "counter", "tag", "flags", "iv"]),
    ("Transaction", ["account_id", "balance", "fee", "rate", "auth_code", "status"]),
    ("StreamBuffer", ["head", "tail", "capacity", "watermark", "checksum", "state"]),
    ("Vector3D", ["coord_x", "coord_y", "coord_z", "norm_sq", "heading", "pitch"]),
    ("EventLog", ["timestamp", "severity", "code", "facility", "signature", "seq"]),
    ("AudioFrame", ["sample_rate", "channels", "peak", "envelope", "rms", "gain"]),
    ("FilterState", ["cutoff", "damping", "prev_in", "prev_out", "gain_db", "mode"]),
    ("DeviceConfig", ["baud_rate", "parity", "stop_bits", "timeout", "port", "id"])
]

UNION_THEMES = [
    ("PacketPayload", ["word", "raw", "halves"]),
    ("RegisterBank", ["reg_val", "bytes", "shorts"]),
    ("TelemetryField", ["metric_int", "octets", "flags"]),
    ("ColorPixel", ["rgba", "channels", "intensity"])
]

VAR_NAMES_POOL = [
    "pivot", "stride", "weight", "delta", "mask", "parity", "residue",
    "scale", "offset", "factor", "quotient", "accumulator", "cursor",
    "checksum", "metric", "threshold", "damping", "tally", "bound",
    "margin", "quantum", "vector", "index_reg", "phase", "coefficient",
    "sample", "window", "segment", "anchor", "tracker"
]

def _generate_types_v5(rng: random.Random, prefix: str) -> Tuple[List[str], List[str], List[str]]:
    """Generates unique struct/union definitions."""
    lines = []
    struct_names = []
    union_names = []

    chosen_structs = rng.sample(STRUCT_THEMES, rng.randint(2, 4))
    for idx, (base_name, field_pool) in enumerate(chosen_structs):
        sname = f"{base_name}_{prefix}_{idx}"
        struct_names.append(sname)
        lines.append(f"struct {sname} {{")
        fields = rng.sample(field_pool, rng.randint(3, len(field_pool)))
        for fld in fields:
            ftype = rng.choice(["int", "short", "int", "unsigned char"])
            lines.append(f"    {ftype} {fld};")
        lines.append("    int buffer[3];")
        lines.append("};")
        lines.append("")

    num_unions = rng.choice([1, 2])
    chosen_unions = rng.sample(UNION_THEMES, num_unions)
    for idx, (base_u, _) in enumerate(chosen_unions):
        uname = f"{base_u}_{prefix}_{idx}"
        union_names.append(uname)
        lines.append(f"union {uname} {{")
        lines.append("    int word;")
        lines.append("    unsigned char raw[4];")
        lines.append("    short pairs[2];")
        lines.append("};")
        lines.append("")

    return lines, struct_names, union_names

def _generate_single_helper_v5(
    rng: random.Random,
    fname: str,
    struct_names: List[str],
    union_names: List[str],
    prefix: str
) -> Tuple[List[str], int]:
    """Generates a helper function performing arithmetic, bitwise, struct, and conditional logic."""
    param_count = rng.choice([2, 3, 4, 5])
    param_names = [f"p{i}" for i in range(param_count)]
    params_str = ", ".join(f"int {p}" for p in param_names)

    lines = []
    lines.append(f"int {fname}({params_str}) {{")

    p0 = param_names[0]
    p1 = param_names[1]
    const_init = rng.randint(1, 50)
    lines.append(f"    int acc = ({p0} + {const_init}) & 127;")
    lines.append(f"    int aux = ({p1} ^ 0x3C) & 63;")

    sname = rng.choice(struct_names)
    lines.append(f"    struct {sname} st = {{0}};")
    lines.append(f"    st.buffer[0] = ({p0} + 3) & 15;")
    lines.append(f"    st.buffer[1] = ({p1} + 7) & 15;")
    lines.append(f"    st.buffer[2] = {rng.randint(5, 30)};")

    block_archetypes = rng.sample([
        "branch_math", "bounded_for", "switch_cases",
        "array_transform", "bitwise_mix", "struct_mutation"
    ], rng.randint(2, 4))

    for arch in block_archetypes:
        v1 = rng.choice(VAR_NAMES_POOL) + f"_{rng.randint(10, 99)}"
        if arch == "branch_math":
            thresh = rng.randint(10, 50)
            lines.append(f"    int {v1} = (st.buffer[0] * 3 + aux) & 63;")
            lines.append(f"    if ({v1} > {thresh}) {{")
            lines.append(f"        acc = (acc + {v1} * 2 + 5) & 127;")
            lines.append(f"        aux ^= ({v1} & 15);")
            lines.append("    } else {")
            lines.append(f"        acc = (acc - {v1} + 11) & 127;")
            lines.append(f"        aux += 3;")
            lines.append("    }")

        elif arch == "bounded_for":
            bound = rng.choice([2, 3])
            lines.append(f"    int {v1} = 0;")
            lines.append(f"    for (int k = 0; k < {bound}; k++) {{")
            lines.append(f"        {v1} = ({v1} + k * 4 + st.buffer[k % 3]) & 31;")
            lines.append(f"        acc = (acc + {v1}) & 127;")
            lines.append("    }")

        elif arch == "switch_cases":
            lines.append(f"    int {v1} = (aux + st.buffer[1]) & 3;")
            lines.append(f"    switch ({v1}) {{")
            lines.append(f"        case 0: acc = (acc + {rng.randint(1, 9)}) & 127; break;")
            lines.append(f"        case 1: aux ^= 0x1F; break;")
            lines.append(f"        case 2: acc = (acc ^ 0x2A) & 127; break;")
            lines.append("        default: acc = (acc + 7) & 127; break;")
            lines.append("    }")

        elif arch == "array_transform":
            lines.append("    int local_arr[3] = {4, 9, 15};")
            lines.append(f"    int {v1} = local_arr[aux % 3];")
            lines.append(f"    acc = (acc + {v1} * 2) & 127;")

        elif arch == "bitwise_mix":
            lines.append(f"    int {v1} = ((acc << 1) ^ (aux >> 1)) & 63;")
            lines.append(f"    aux = (aux + {v1}) & 63;")
            lines.append("    acc ^= aux;")

        elif arch == "struct_mutation":
            lines.append(f"    st.buffer[1] = (st.buffer[1] + {rng.randint(1, 9)}) & 15;")
            lines.append(f"    acc = (acc + st.buffer[1]) & 127;")

    lines.append("    return (acc + aux) & 255;")
    lines.append("}")
    lines.append("")
    return lines, param_count

def generate_diverse_c_program_v5(
    prog_id: str,
    family: str,
    seed: int,
    min_loc: int = 2000,
    max_loc: int = 2500
) -> Tuple[str, Dict[str, Any]]:
    """
    Generates a unique, structurally rich C program for random_5 belonging to one of the 10 canonical families.
    """
    rng = random.Random(seed)

    num_high = rng.randint(16, 24)
    num_low = rng.randint(16, 24)
    high_vars = [f"sec_{prog_id.lower()}_{i}" for i in range(num_high)]
    low_vars = [f"pub_{prog_id.lower()}_{i}" for i in range(num_low)]
    input_vars = high_vars + low_vars

    prefix = f"{prog_id}_{seed % 10000}"

    lines = []
    lines.append("/*")
    lines.append(f" * Benchmark Program: {prog_id}")
    lines.append(f" * Security Family: {family}")
    lines.append(f" * Generator Seed: {seed}")
    lines.append(f" * High Inputs: {num_high} | Low Inputs: {num_low}")
    lines.append(" */")
    lines.append("#include <stdio.h>")
    lines.append("#include <stdlib.h>")
    lines.append("#include <stdbool.h>")
    lines.append("#include <string.h>")
    lines.append("")

    # Types (Structs & Unions)
    type_lines, struct_names, union_names = _generate_types_v5(rng, prefix)
    lines.extend(type_lines)

    # Globals
    lines.append("int g_out = 0;")
    lines.append("int g_chk = 0;")
    lines.append("int g_telemetry = 0;")
    lines.append("")

    # Generate 14 to 24 diverse helper functions
    num_helpers = rng.randint(14, 24)
    helper_names = []
    helper_param_counts = []
    for f in range(num_helpers):
        fname = f"fn_{prefix}_{f}"
        helper_names.append(fname)
        hlines, pcount = _generate_single_helper_v5(rng, fname, struct_names, union_names, prefix)
        helper_param_counts.append(pcount)
        lines.extend(hlines)

    target_loc = rng.randint(min_loc + 50, max_loc - 50)

    # Configure secret injection probability based on family
    if family == "zero_leakage":
        leak_prob = 0.0
        num_leak_helpers = 0
    elif family in ("direct_leakage", "secret_dependent_array"):
        leak_prob = 0.35
        num_leak_helpers = rng.randint(3, 6)
    elif family in ("multi_step_explicit", "arithmetic_flow", "bitwise_flow"):
        leak_prob = 0.55
        num_leak_helpers = rng.randint(5, 9)
    elif family in ("implicit_flow", "nested_implicit_flow", "secret_dependent_loops"):
        leak_prob = 0.65
        num_leak_helpers = rng.randint(7, 11)
    else:  # mixed_control_data
        leak_prob = 0.75
        num_leak_helpers = rng.randint(9, min(14, num_helpers))

    # Build main()
    lines.append("int main() {")
    for var in input_vars:
        lines.append(f"    int {var};")
    lines.append("    int out_sink = 0;")
    lines.append("    int chk_sum = 0;")
    lines.append("    int sec_accum = 0;")
    lines.append("")

    # Relational assumptions
    for var in low_vars:
        lines.append(f"    __CPROVER_assume({var} >= -100 && {var} <= 100);")
    for var in high_vars:
        lines.append(f"    __CPROVER_assume({var} >= 0 && {var} <= 255);")
    lines.append("")

    # Instances of structs & unions
    p0 = low_vars[0]
    for idx, sname in enumerate(struct_names):
        lines.append(f"    struct {sname} st_var_{idx} = {{0}};")
        lines.append(f"    st_var_{idx}.buffer[0] = ({p0} + {idx * 3 + 1}) & 15;")
        lines.append(f"    st_var_{idx}.buffer[1] = ({p0} + {idx * 5 + 4}) & 15;")
        lines.append(f"    st_var_{idx}.buffer[2] = ({p0} + {idx * 2 + 7}) & 15;")
    lines.append("")

    u_name = union_names[0]
    lines.append(f"    union {u_name} u_var;")
    lines.append("    u_var.word = 0;")
    lines.append("    int table[4] = { 11, 23, 47, 89 };")
    lines.append("")

    # Interprocedural calls
    lines.append("    /* Interprocedural Flow Pipeline */")
    inter_vars = []
    for h_idx in range(min(num_leak_helpers, len(helper_names))):
        hname = helper_names[h_idx]
        pcount = helper_param_counts[h_idx]
        call_args = []
        for p in range(pcount):
            if family != "zero_leakage" and p == 0:
                call_args.append(high_vars[h_idx % len(high_vars)])
            elif family != "zero_leakage" and p == 1 and rng.random() < 0.5:
                call_args.append(high_vars[(h_idx + 1) % len(high_vars)])
            else:
                call_args.append(low_vars[(h_idx + p) % len(low_vars)])
        iv_name = f"helper_flow_{h_idx}"
        inter_vars.append(iv_name)
        lines.append(f"    int {iv_name} = {hname}({', '.join(call_args)});")
    lines.append("")

    # Pipeline stages
    stage = 0
    active_secret_vars = list(high_vars) + list(inter_vars) if family != "zero_leakage" else []

    while True:
        current_loc = len([ln for ln in lines if ln.strip()])
        est_remaining = 35
        if current_loc + est_remaining >= target_loc:
            break

        is_leak_stage = (family != "zero_leakage") and (rng.random() < leak_prob) and len(active_secret_vars) > 0
        var_name = f"stage_v_{stage}"
        s_idx = stage % len(struct_names)
        h_pick = rng.choice(active_secret_vars) if is_leak_stage else None
        p_pick = rng.choice(low_vars)

        lines.append(f"    /* Execution Pipeline Stage {stage} */")

        if is_leak_stage and family == "implicit_flow":
            thresh = rng.randint(15, 60)
            lines.append(f"    int {var_name} = ({h_pick} + {p_pick} * 2 + {stage * 3 + 5}) & 127;")
            active_secret_vars.append(var_name)
            lines.append(f"    if ({var_name} > {thresh}) {{")
            lines.append(f"        out_sink = (out_sink + {var_name} * 2 + 7) & 255;")
            lines.append(f"        sec_accum ^= ({var_name} & 31);")
            lines.append("    } else {")
            lines.append(f"        out_sink = (out_sink - {var_name} + 13) & 255;")
            lines.append(f"        sec_accum += 5;")
            lines.append("    }")

        elif is_leak_stage and family == "nested_implicit_flow":
            h_alt = rng.choice(active_secret_vars)
            lines.append(f"    int {var_name} = ({h_pick} ^ {p_pick}) & 63;")
            active_secret_vars.append(var_name)
            lines.append(f"    if (({var_name} & 1) != 0) {{")
            lines.append(f"        if (({h_alt} & 2) != 0) {{")
            lines.append(f"            out_sink = (out_sink + {var_name} * 3 + 1) & 255;")
            lines.append("        } else {")
            lines.append(f"            out_sink = (out_sink - {var_name} + 9) & 255;")
            lines.append("        }")
            lines.append("    } else {")
            lines.append(f"        sec_accum = (sec_accum + {var_name} * 2) & 255;")
            lines.append("    }")

        elif is_leak_stage and family == "secret_dependent_loops":
            lines.append(f"    int {var_name} = 0;")
            active_secret_vars.append(var_name)
            lines.append(f"    for (int it = 0; it < 2; it++) {{")
            lines.append(f"        {var_name} = ({var_name} + it * 3 + ({h_pick} & 15)) & 63;")
            lines.append(f"        if (({h_pick} & 1) != 0) {{")
            lines.append(f"            sec_accum = (sec_accum + {var_name} + 3) & 255;")
            lines.append("        } else {")
            lines.append(f"            sec_accum = (sec_accum - {var_name} + 7) & 255;")
            lines.append("        }")
            lines.append("    }")

        elif is_leak_stage and family == "secret_dependent_array":
            lines.append(f"    int {var_name} = table[{stage % 4}] + ({h_pick} & 7);")
            active_secret_vars.append(var_name)
            lines.append(f"    table[{stage % 4}] = ({var_name} + {p_pick}) & 63;")
            lines.append(f"    out_sink ^= ({var_name} & 127);")

        elif is_leak_stage and family == "bitwise_flow":
            lines.append(f"    int {var_name} = (({h_pick} << 1) ^ ({p_pick} >> 1)) & 127;")
            active_secret_vars.append(var_name)
            lines.append(f"    st_var_{s_idx}.buffer[{stage % 3}] = ({var_name} + 1) & 15;")
            lines.append(f"    out_sink ^= ({var_name} & 63);")

        elif is_leak_stage and family in ("arithmetic_flow", "multi_step_explicit", "direct_leakage"):
            c1 = rng.randint(3, 45)
            lines.append(f"    int {var_name} = (({h_pick} * 3) + {p_pick} + {c1}) & 127;")
            active_secret_vars.append(var_name)
            lines.append(f"    sec_accum = (sec_accum + {var_name}) & 255;")
            lines.append(f"    out_sink = (out_sink + {var_name} * 2) & 255;")

        elif is_leak_stage and family == "mixed_control_data":
            thresh = rng.randint(20, 50)
            lines.append(f"    int {var_name} = (({h_pick} ^ 0x2A) * 2 + {p_pick}) & 127;")
            active_secret_vars.append(var_name)
            lines.append(f"    if ({var_name} > {thresh}) {{")
            lines.append(f"        out_sink = (out_sink + {var_name} * 2 + 7) & 255;")
            lines.append("    } else {")
            lines.append(f"        out_sink = (out_sink - {var_name} + 13) & 255;")
            lines.append("    }")
            lines.append(f"    sec_accum = (sec_accum + {var_name}) & 255;")

        else:  # Clean standard stage (for zero_leakage or non-leak stages)
            c_val = rng.randint(5, 50)
            lines.append(f"    int {var_name} = ({p_pick} * 2 + {c_val}) & 63;")
            lines.append(f"    chk_sum = (chk_sum + {var_name}) & 127;")

        lines.append("")
        stage += 1

    # Security Flow Epilogue
    if family == "zero_leakage":
        lines.append("    /* Zero Leakage Neutralization */")
        num_dead = min(4, len(high_vars))
        dead_vars = []
        for d in range(num_dead):
            dv = f"dead_sec_{d}"
            dead_vars.append(dv)
            h = high_vars[d]
            lines.append(f"    int {dv} = ({h} ^ {h}) * 0;")
        sum_dead = " + ".join(dead_vars)
        lines.append(f"    out_sink = (out_sink + {sum_dead}) & 255;")
        lines.append("    g_out = out_sink;")
        lines.append("    g_chk = chk_sum;")
        lines.append("    g_telemetry = (chk_sum ^ 0x55) & 127;")
    else:
        lines.append("    /* Final Aggregate Output */")
        lines.append("    g_out = (out_sink + sec_accum) & 255;")
        lines.append("    g_chk = chk_sum;")
        lines.append("    g_telemetry = (sec_accum ^ chk_sum) & 127;")

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

def process_single_v5_program(
    prog_id: str,
    family_id: str,
    initial_seed: int,
    dest_dir: Path,
    seen_hashes: set,
    lock: threading.Lock,
    regeneration_log: List[Dict[str, Any]],
    seen_features: Optional[set] = None,
    min_loc: int = 2000,
    max_loc: int = 2500
) -> Dict[str, Any]:
    """Generates, miters, verifies with CBMC, and extracts features for a single V5 benchmark."""
    dest_programs = dest_dir / "programs"
    dest_configs = dest_dir / "configs"
    dest_miters = dest_dir / "miters"
    dest_cbmc = dest_dir / "cbmc"
    dest_features = dest_dir / "features"

    c_path = dest_programs / f"{prog_id}.c"
    cfg_path = dest_configs / f"{prog_id}.json"
    miter_path = dest_miters / f"{prog_id}_miter.c"
    cbmc_json_path = dest_cbmc / f"{prog_id}.json"
    feat_json_path = dest_features / f"{prog_id}.json"

    current_seed = initial_seed
    attempts = 0

    while True:
        attempts += 1
        source_code, config = generate_diverse_c_program_v5(
            prog_id, family_id, current_seed, min_loc=min_loc, max_loc=max_loc
        )

        loc = len([ln for ln in source_code.splitlines() if ln.strip()])
        if not (min_loc <= loc <= max_loc):
            current_seed += 31
            continue

        sha256 = hashlib.sha256(source_code.encode("utf-8")).hexdigest()

        with lock:
            if sha256 in seen_hashes:
                current_seed += 101
                continue
            seen_hashes.add(sha256)

        c_path.write_text(source_code, encoding="utf-8")
        cfg_path.write_text(json.dumps(config, indent=2), encoding="utf-8")

        # Generate miter
        try:
            generate_miter_program(c_path, cfg_path, miter_path)
        except Exception as e:
            with lock:
                seen_hashes.discard(sha256)
            current_seed += 1007
            continue

        # Run CBMC Verification
        try:
            cbmc_res = run_cbmc_verification(miter_path, unwind=5)
            cbmc_json_path.write_text(json.dumps(cbmc_res, indent=2), encoding="utf-8")
        except Exception as e:
            with lock:
                seen_hashes.discard(sha256)
            current_seed += 2011
            continue

        # Canonical Source-Centric Feature Extraction
        try:
            features = extract_all_mqil_features(c_path, cfg_path, architecture="source_centric")
            feat_json_path.write_text(json.dumps(features, indent=2), encoding="utf-8")
        except Exception as e:
            with lock:
                seen_hashes.discard(sha256)
            current_seed += 3037
            continue

        # Feature vector uniqueness
        feat_vector = tuple(features.get(col, 0) for col in FEATURE_COLS)
        with lock:
            if seen_features is not None:
                if feat_vector in seen_features:
                    seen_hashes.discard(sha256)
                    current_seed += 4049
                    continue
                seen_features.add(feat_vector)

        if attempts > 1:
            with lock:
                regeneration_log.append({
                    "program_id": prog_id,
                    "attempts": attempts,
                    "final_seed": current_seed
                })

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

def _save_dataset_csv_v5(dest_dir: Path, results: List[Dict[str, Any]]) -> None:
    """Writes to random_dataset.csv for random_5."""
    csv_path = dest_dir / "random_dataset.csv"
    csv_columns = [
        "program_id", "family_id", "source_file", "generator_seed"
    ] + FEATURE_COLS + [
        "actual_mqil_leakage", "actual_mqil_assertions_total", "mqil_leak_ratio",
        "cbmc_verified"
    ]

    all_rows = {}
    if csv_path.exists():
        with open(csv_path, "r", encoding="utf-8") as f:
            reader = csv.DictReader(f)
            for row in reader:
                all_rows[row["program_id"]] = [row.get(col, "") for col in csv_columns]

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
            cbmc["cbmc_verified"]
        ])
        all_rows[r["program_id"]] = row

    sorted_pids = sorted(all_rows.keys(), key=lambda p: int(p[1:]) if p[1:].isdigit() else p)

    with open(csv_path, "w", newline="", encoding="utf-8") as f:
        writer = csv.writer(f)
        writer.writerow(csv_columns)
        for pid in sorted_pids:
            writer.writerow(all_rows[pid])

def run_random_5_dataset(
    dest_dir: Optional[Path] = None,
    count: int = 1000,
    start_idx: Optional[int] = None,
    max_workers: Optional[int] = None
) -> None:
    """Entry point to generate random_5 dataset (2000 <= LOC <= 2500, 10 canonical families, high leakage range)."""
    workspace = Path(__file__).resolve().parent.parent.parent
    if dest_dir is None:
        dest_dir = workspace / "datasets" / "random_5"

    for sub in ["programs", "configs", "miters", "cbmc", "features"]:
        (dest_dir / sub).mkdir(parents=True, exist_ok=True)

    existing_c = list((dest_dir / "programs").glob("R*.c"))
    if start_idx is None:
        if existing_c:
            indices = [int(p.stem[1:]) for p in existing_c if p.stem[1:].isdigit()]
            start_idx = max(indices) if indices else 0
        else:
            start_idx = 0

    end_idx = count
    if start_idx >= end_idx:
        print(f"[OK] random_5 already has {start_idx} programs generated (Target: {end_idx}).")
        return

    print(f"Starting generation for random_5: {start_idx + 1} to {end_idx} ({count} total target)...")
    print(f"Canonical Security Families: {', '.join(SECURITY_FAMILIES)}")

    # Pre-populate seen_hashes across all random datasets
    seen_hashes: Set[str] = set()
    dirs_to_check = [
        workspace / "datasets" / "random" / "programs",
        workspace / "datasets" / "random_2" / "programs",
        workspace / "datasets" / "random_3" / "programs",
        workspace / "datasets" / "random_4" / "programs",
        workspace / "datasets" / "random_5" / "programs"
    ]
    for d in dirs_to_check:
        if d.exists():
            for f in d.glob("*.c"):
                seen_hashes.add(hashlib.sha256(f.read_bytes()).hexdigest())

    print(f"Pre-loaded {len(seen_hashes)} existing hashes across random, random_2, random_3, random_4, and random_5.")

    seen_features: Set[Tuple[Any, ...]] = set()
    feat_csv = dest_dir / "random_dataset.csv"
    if feat_csv.exists():
        with open(feat_csv, "r", encoding="utf-8") as f:
            reader = csv.DictReader(f)
            for row in reader:
                try:
                    feat_vector = tuple(float(row[c]) if "." in row.get(c, "0") else int(row.get(c, 0)) for c in FEATURE_COLS)
                    seen_features.add(feat_vector)
                except Exception:
                    pass

    lock = threading.Lock()
    regeneration_log: List[Dict[str, Any]] = []

    tasks = []
    for i in range(start_idx, end_idx):
        pid = f"R{i + 1:06d}"
        fam = SECURITY_FAMILIES[i % len(SECURITY_FAMILIES)]
        seed = 500000 + (i + 1) * 100 + 13
        tasks.append((pid, fam, seed))

    workers = max_workers or 10
    print(f"Running generation with {workers} parallel workers...")

    results = []
    completed = 0
    t0 = time.time()

    with concurrent.futures.ThreadPoolExecutor(max_workers=workers) as executor:
        future_map = {
            executor.submit(
                process_single_v5_program,
                t[0], t[1], t[2], dest_dir, seen_hashes, lock, regeneration_log, seen_features
            ): t[0] for t in tasks
        }

        for fut in concurrent.futures.as_completed(future_map):
            res = fut.result()
            completed += 1
            results.append(res)

            if completed % 10 == 0 or completed == len(tasks):
                elapsed = time.time() - t0
                rate = completed / elapsed if elapsed > 0 else 0
                cbmc = res["cbmc_res"]
                feats = res["features"]
                print(f"[{completed}/{len(tasks)}] {res['program_id']} ({res['family_id']}): "
                      f"LOC={res['loc']}, LeakedVars={feats['num_information_leak']}, "
                      f"CBMC_#leak={cbmc['actual_mqil_leakage']}/{cbmc['actual_mqil_assertions_total']} "
                      f"({rate:.1f} progs/sec)", flush=True)

                with lock:
                    _save_dataset_csv_v5(dest_dir, results)
                    results = []

    with lock:
        if results:
            _save_dataset_csv_v5(dest_dir, results)

    total_time = time.time() - t0
    print(f"\n[OK] Completed random_5 generation and verification in {total_time:.1f}s.")

if __name__ == "__main__":
    import argparse
    parser = argparse.ArgumentParser(description="Generate random_5 high-leakage dataset.")
    parser.add_argument("--count", type=int, default=1000, help="Number of programs to generate")
    parser.add_argument("--workers", type=int, default=10, help="Number of parallel workers")
    args = parser.parse_args()

    run_random_5_dataset(count=args.count, max_workers=args.workers)
