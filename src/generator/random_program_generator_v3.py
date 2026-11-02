"""
Random Program Generator V3: High-Diversity, Structurally Distinct C Benchmarks.
Generates genuine C99 programs with rich structural diversity, unique type definitions,
heterogeneous function bodies, multi-stage pipelines, and distinct security information flows.
Enforces:
  - Strict 2000 <= LOC <= 2500
  - CBMC-MQIL transpiler compatibility (tools/cbmc_mqil)
  - CBMC bounded model checking (--unwind 5, --unwinding-assertions, --no-standard-checks)
  - 28-feature AST extractor compatibility
  - Complete inter-file structural uniqueness
"""

import random
from pathlib import Path
from typing import Dict, Any, List, Tuple, Optional
import hashlib
import json
import csv
import concurrent.futures
import threading
import time

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
    ("SensorNode", ["reading", "calib", "status", "gain", "threshold"]),
    ("MatrixBlock", ["dim", "stride", "determinant", "scale", "trace"]),
    ("CipherContext", ["round_key", "nonce", "counter", "tag", "flags"]),
    ("Transaction", ["account_id", "balance", "fee", "rate", "auth_code"]),
    ("StreamBuffer", ["head", "tail", "capacity", "watermark", "checksum"]),
    ("Vector3D", ["coord_x", "coord_y", "coord_z", "norm_sq", "heading"]),
    ("EventLog", ["timestamp", "severity", "code", "facility", "signature"]),
    ("AudioFrame", ["sample_rate", "channels", "peak", "envelope", "rms"]),
    ("FilterState", ["cutoff", "damping", "prev_in", "prev_out", "gain_db"]),
    ("DeviceConfig", ["baud_rate", "parity", "stop_bits", "timeout", "port"])
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
    "margin", "quantum", "vector", "index_reg", "phase", "coefficient"
]

def _generate_types(rng: random.Random, prefix: str) -> Tuple[List[str], List[str], List[str]]:
    """Generates 2 to 4 unique struct/union definitions with diverse fields."""
    lines = []
    struct_names = []
    union_names = []

    # Pick 2-3 distinct struct themes
    chosen_structs = rng.sample(STRUCT_THEMES, rng.randint(2, 3))
    for base_name, field_pool in chosen_structs:
        sname = f"{base_name}_{prefix}"
        struct_names.append(sname)
        lines.append(f"struct {sname} {{")
        # 3 to 5 fields
        fields = rng.sample(field_pool, rng.randint(3, len(field_pool)))
        for fld in fields:
            ftype = rng.choice(["int", "int", "short", "int"])
            lines.append(f"    {ftype} {fld};")
        buf_size = 3
        lines.append(f"    int buffer[{buf_size}];")
        lines.append("};")
        lines.append("")

    # Pick 1 union theme
    base_u, ufields = rng.choice(UNION_THEMES)
    uname = f"{base_u}_{prefix}"
    union_names.append(uname)
    lines.append(f"union {uname} {{")
    lines.append("    int word;")
    lines.append("    unsigned char raw[4];")
    lines.append("    short pairs[2];")
    lines.append("};")
    lines.append("")

    return lines, struct_names, union_names

def _generate_single_helper(
    rng: random.Random,
    fname: str,
    struct_names: List[str],
    union_names: List[str],
    prefix: str,
    depth: int = 1
) -> Tuple[List[str], int]:
    """Generates a genuinely unique helper function with randomized logic."""
    param_count = rng.choice([2, 3, 4])
    param_names = [f"p{i}" for i in range(param_count)]
    params_str = ", ".join(f"int {p}" for p in param_names)

    lines = []
    lines.append(f"int {fname}({params_str}) {{")

    # Local accumulators
    p0 = param_names[0]
    p1 = param_names[1]
    const_init = rng.randint(1, 40)
    lines.append(f"    int acc = ({p0} + {const_init}) & 127;")
    lines.append(f"    int aux = ({p1} ^ 0x3C) & 63;")

    # Instantiate one of the structs
    sname = rng.choice(struct_names)
    lines.append(f"    struct {sname} st = {{0}};")
    lines.append(f"    st.buffer[0] = ({p0} + 3) & 15;")
    lines.append(f"    st.buffer[1] = ({p1} + 7) & 15;")
    lines.append(f"    st.buffer[2] = {rng.randint(5, 25)};")

    # Pick 2-4 algorithmic blocks for this function
    block_archetypes = rng.sample([
        "branch_math", "bounded_for", "bounded_while",
        "switch_cases", "array_transform", "bitwise_mix"
    ], rng.randint(2, 4))

    for arch in block_archetypes:
        v1 = rng.choice(VAR_NAMES_POOL)
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
            lines.append(f"    for (int k = 0; k < {bound}; k++) {{")
            lines.append(f"        aux = (aux + k * {rng.randint(2, 5)} + st.buffer[k % 3]) & 63;")
            lines.append(f"        acc = (acc ^ (aux + k)) & 127;")
            lines.append("    }")

        elif arch == "bounded_while":
            bound = rng.choice([2, 3])
            lines.append("    int loop_ctr = 0;")
            lines.append(f"    while (loop_ctr < {bound}) {{")
            lines.append(f"        acc = (acc + loop_ctr * 4 + 7) & 127;")
            lines.append("        loop_ctr++;")
            lines.append("    }")

        elif arch == "switch_cases":
            cases = rng.sample(range(4), 3)
            lines.append(f"    switch (({p0} + aux) & 3) {{")
            for c in cases:
                lines.append(f"        case {c}:")
                lines.append(f"            acc = (acc + {rng.randint(3, 17)}) & 127;")
                lines.append("            break;")
            lines.append("        default:")
            lines.append("            acc ^= 0x1F;")
            lines.append("            break;")
            lines.append("    }")

        elif arch == "array_transform":
            lines.append("    int loc_tab[3];")
            lines.append(f"    loc_tab[0] = ({p0} & 15) + 2;")
            lines.append(f"    loc_tab[1] = ({p1} & 15) + 4;")
            lines.append(f"    loc_tab[2] = (aux & 15) + 6;")
            lines.append(f"    acc = (acc + loc_tab[aux % 3]) & 127;")

        elif arch == "bitwise_mix":
            lines.append(f"    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;")
            lines.append(f"    acc = (acc + b_step * 3) & 127;")

    lines.append("    return (acc + aux) & 127;")
    lines.append("}")
    lines.append("")
    return lines, param_count

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
        # Secret undergoes complex calculation but mathematically cancels to 0
        lines.append(f"    int dead_sec = ({h0} ^ {h0}) * 0;")
        lines.append("    out_sink += dead_sec;")
        lines.append("    if (dead_sec != 0) {")
        lines.append("        out_sink += 1000;")
        lines.append("    }")

    elif family == "direct_leakage":
        lines.append(f"    out_sink += {h0};")

    elif family == "multi_step_explicit":
        lines.append(f"    int s_st1 = ({h0} ^ 0x4B) & 127;")
        lines.append(f"    int s_st2 = (s_st1 * 3 + 19) & 255;")
        lines.append(f"    int s_st3 = (s_st2 >> 1) + (s_st1 & 15);")
        lines.append(f"    int s_st4 = (s_st3 ^ 0x33) & 63;")
        lines.append(f"    out_sink += s_st4;")

    elif family == "arithmetic_flow":
        lines.append(f"    int a_term1 = ({h0} * 5 + 23) & 255;")
        lines.append(f"    int a_term2 = (a_term1 + {p0} * 3) & 127;")
        lines.append(f"    out_sink += (a_term1 - a_term2) & 63;")

    elif family == "bitwise_flow":
        lines.append(f"    int b_w1 = ({h0} << 2) & 124;")
        lines.append(f"    int b_w2 = ({h0} >> 2) & 31;")
        lines.append(f"    int b_w3 = (b_w1 ^ b_w2) | 5;")
        lines.append(f"    out_sink += b_w3 & 63;")

    elif family == "implicit_flow":
        lines.append(f"    if (({h0} & 7) > 3) {{")
        lines.append("        out_sink += 77;")
        lines.append("    } else {")
        lines.append("        out_sink -= 33;")
        lines.append("    }")

    elif family == "nested_implicit_flow":
        lines.append(f"    if (({h0} & 1) != 0) {{")
        lines.append(f"        if (({h0} & 2) != 0) {{")
        lines.append("            out_sink += 50;")
        lines.append("        } else {")
        lines.append("            out_sink += 25;")
        lines.append("        }")
        lines.append("    } else {")
        lines.append(f"        if (({h0} & 4) != 0) {{")
        lines.append("            out_sink -= 15;")
        lines.append("        } else {")
        lines.append("            out_sink -= 35;")
        lines.append("        }")
        lines.append("    }")

    elif family == "secret_dependent_loops":
        lines.append(f"    int l_bound = ({h0} & 1) + 1;")
        lines.append("    for (int it = 0; it < l_bound; it++) {")
        lines.append("        out_sink += (it * 3 + 4);")
        lines.append("    }")

    elif family == "secret_dependent_array":
        lines.append("    int s_lut[4] = { 19, 43, 71, 97 };")
        lines.append(f"    int s_idx = ({h0} & 3);")
        lines.append("    out_sink += s_lut[s_idx];")

    elif family == "mixed_control_data":
        lines.append(f"    int m_var = ({h0} ^ 0x55) & 63;")
        lines.append("    if (m_var > 30) {")
        lines.append(f"        out_sink += (m_var * 2 + {p0}) & 127;")
        lines.append("    } else {")
        lines.append("        out_sink -= (m_var + 9) & 31;")
        lines.append("    }")
        lines.append(f"    out_sink ^= ({h0} & 15);")

    lines.append("")
    return lines

def generate_diverse_c_program(
    prog_id: str,
    family: str,
    seed: int,
    min_loc: int = 2000,
    max_loc: int = 2500
) -> Tuple[str, Dict[str, Any]]:
    """
    Generates a genuinely unique, structurally distinct C program.
    Guarantees min_loc <= LOC <= max_loc.
    """
    rng = random.Random(seed)

    # 1. Inputs
    num_high = rng.choice([1, 2, 3])
    num_low = rng.choice([1, 2, 3])
    high_vars = [f"sec_{prog_id.lower()}_{i}" for i in range(num_high)]
    low_vars = [f"pub_{prog_id.lower()}_{i}" for i in range(num_low)]
    input_vars = high_vars + low_vars

    prefix = f"{prog_id}_{seed % 10000}"

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
    lines.append("")

    # 2. Types (Structs & Unions)
    type_lines, struct_names, union_names = _generate_types(rng, prefix)
    lines.extend(type_lines)

    # 3. Globals
    lines.append("int g_out = 0;")
    lines.append("int g_chk = 0;")
    lines.append("")

    # 4. Generate 12 to 24 diverse helper functions
    num_helpers = rng.randint(14, 22)
    helper_names = []
    helper_param_counts = []
    for f in range(num_helpers):
        fname = f"fn_{prefix}_{f}"
        helper_names.append(fname)
        hlines, pcount = _generate_single_helper(rng, fname, struct_names, union_names, prefix)
        helper_param_counts.append(pcount)
        lines.extend(hlines)

    # Target LOC chosen in range
    target_loc = rng.randint(min_loc + 50, max_loc - 50)

    # 5. Build main()
    lines.append("int main() {")
    for var in input_vars:
        lines.append(f"    int {var};")
    lines.append("    int out_sink = 0;")
    lines.append("    int chk_sum = 0;")
    lines.append("")

    # Allocate instances of generated structs & unions
    p0 = low_vars[0]
    for idx, sname in enumerate(struct_names):
        lines.append(f"    struct {sname} st_var_{idx} = {{0}};")
        lines.append(f"    st_var_{idx}.buffer[0] = ({p0} + {idx * 3 + 1}) & 15;")
        lines.append(f"    st_var_{idx}.buffer[1] = ({p0} + {idx * 5 + 4}) & 15;")
        lines.append(f"    st_var_{idx}.buffer[2] = {idx + 7};")

    uname = union_names[0]
    lines.append(f"    union {uname} u_var = {{0}};")
    lines.append(f"    u_var.word = ({p0} + 0x42) & 255;")
    lines.append("    int table[4] = { 7, 13, 29, 41 };")
    lines.append("")

    # Helper function call dispatch (constant deterministic arguments ensure helper invariants hold)
    for f_idx, fname in enumerate(helper_names):
        pcount = helper_param_counts[f_idx]
        call_args = [f"({(f_idx + 1) * (k + 2) + 5})" for k in range(pcount)]
        args_str = ", ".join(call_args)
        lines.append(f"    int res_{f_idx} = {fname}({args_str});")
        lines.append(f"    out_sink = (out_sink + res_{f_idx}) & 255;")
        lines.append(f"    chk_sum ^= (res_{f_idx} << 1) & 127;")
    lines.append("")

    # Diverse Multi-Stage Computational Logic
    stage = 0
    # Available stage block generators
    stage_templates = [
        "nested_branch_stage",
        "bounded_loop_stage",
        "switch_stage",
        "struct_mutation_stage",
        "array_sifting_stage",
        "bitwise_cascade_stage",
        "ternary_chain_stage"
    ]

    while True:
        # Check current line count
        est_remaining = 35  # security flow + closing
        if len(lines) + est_remaining >= target_loc:
            break

        stype = rng.choice(stage_templates)
        var_name = f"stage_v_{stage}"
        s_idx = stage % len(struct_names)

        lines.append(f"    /* Execution Pipeline Stage {stage} */")

        if stype == "nested_branch_stage":
            c1 = rng.randint(10, 40)
            lines.append(f"    int {var_name} = (st_var_{s_idx}.buffer[{stage % 3}] * 2 + {stage * 3 + 7}) & 63;")
            lines.append(f"    if ({var_name} > {c1}) {{")
            lines.append(f"        out_sink = (out_sink + {var_name} - 5) & 255;")
            lines.append(f"        if ({var_name} > {c1 + 15}) {{")
            lines.append(f"            chk_sum ^= ({var_name} & 31);")
            lines.append("        } else {")
            lines.append(f"            chk_sum = (chk_sum + 3) & 127;")
            lines.append("        }")
            lines.append("    } else {")
            lines.append(f"        out_sink = (out_sink - {var_name} + 9) & 255;")
            lines.append(f"        chk_sum ^= 0x1A;")
            lines.append("    }")

        elif stype == "bounded_loop_stage":
            bound = rng.choice([2, 3])
            lines.append(f"    int {var_name} = 0;")
            lines.append(f"    for (int step = 0; step < {bound}; step++) {{")
            lines.append(f"        {var_name} = ({var_name} + step * 5 + table[step]) & 63;")
            lines.append(f"        chk_sum = (chk_sum + {var_name}) & 127;")
            lines.append("    }")
            lines.append(f"    out_sink = (out_sink + {var_name}) & 255;")

        elif stype == "switch_stage":
            lines.append(f"    int {var_name} = (st_var_{s_idx}.buffer[0] ^ {stage + 3}) & 3;")
            lines.append(f"    switch ({var_name}) {{")
            lines.append("        case 0:")
            lines.append(f"            out_sink = (out_sink + {rng.randint(2, 9)}) & 255;")
            lines.append("            break;")
            lines.append("        case 1:")
            lines.append(f"            chk_sum ^= 0x3F;")
            lines.append("            break;")
            lines.append("        case 2:")
            lines.append(f"            out_sink = (out_sink ^ 0x2A) & 255;")
            lines.append("            break;")
            lines.append("        default:")
            lines.append(f"            chk_sum = (chk_sum + 7) & 127;")
            lines.append("            break;")
            lines.append("    }")

        elif stype == "struct_mutation_stage":
            lines.append(f"    st_var_{s_idx}.buffer[{stage % 3}] = (st_var_{s_idx}.buffer[{stage % 3}] + {stage + 1}) & 15;")
            lines.append(f"    int {var_name} = (st_var_{s_idx}.buffer[{stage % 3}] * 3) & 63;")
            lines.append(f"    out_sink = (out_sink + {var_name}) & 255;")
            lines.append(f"    chk_sum ^= {var_name};")

        elif stype == "array_sifting_stage":
            lines.append(f"    int {var_name} = table[{stage % 4}];")
            lines.append(f"    table[{stage % 4}] = (table[{(stage + 1) % 4}] + {stage * 2 + 1}) & 63;")
            lines.append(f"    out_sink = (out_sink + {var_name}) & 255;")

        elif stype == "bitwise_cascade_stage":
            lines.append(f"    int {var_name} = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;")
            lines.append(f"    u_var.raw[{stage % 4}] = (unsigned char)({var_name} & 255);")
            lines.append(f"    chk_sum = (chk_sum ^ u_var.raw[{stage % 4}]) & 127;")

        elif stype == "ternary_chain_stage":
            lines.append(f"    int {var_name} = (out_sink > 100) ? (chk_sum & 31) : ({stage + 5} & 31);")
            lines.append(f"    out_sink = (out_sink + {var_name}) & 255;")
            lines.append(f"    chk_sum ^= ({var_name} << 1) & 127;")

        lines.append("")
        stage += 1

    # Inject Security Information Flow
    lines.extend(_generate_security_flow(rng, family, high_vars, low_vars))

    # Sinks and Return
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

def process_single_v3_program(
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
    """
    Generates, miters, verifies with CBMC, and extracts features for a single V3 benchmark.
    Guarantees 2000 <= LOC <= 2500, distinct SHA-256, and unique feature vector.
    """
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
        source_code, config = generate_diverse_c_program(
            prog_id=prog_id,
            family=family_id,
            seed=current_seed,
            min_loc=min_loc,
            max_loc=max_loc
        )

        loc = len(source_code.splitlines())
        if loc < min_loc or loc > max_loc:
            with lock:
                regeneration_log.append({
                    "program_id": prog_id,
                    "seed": current_seed,
                    "reason": f"LOC {loc} outside [{min_loc}, {max_loc}]"
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
            cbmc_res = run_cbmc_verification(miter_path, unwind=5, timeout=60)
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

        if not cbmc_res.get("cbmc_verified"):
            with lock:
                seen_hashes.remove(sha256)
                regeneration_log.append({
                    "program_id": prog_id,
                    "seed": current_seed,
                    "reason": f"CBMC unverified: {cbmc_res.get('dataset_status', 'UNKNOWN')}"
                })
            current_seed += 1000
            continue

        # 3. Extract all 28 ML features
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

        feat_vector = tuple(float(features.get(col, 0)) for col in FEATURE_COLS)
        if seen_features is not None:
            with lock:
                if feat_vector in seen_features:
                    seen_hashes.remove(sha256)
                    regeneration_log.append({
                        "program_id": prog_id,
                        "seed": current_seed,
                        "reason": "Feature vector collision"
                    })
                    current_seed += 1000
                    continue
                seen_features.add(feat_vector)

        # 4. Save per-program CBMC and Feature JSONs
        with open(cbmc_json_path, "w", encoding="utf-8") as f:
            json.dump(cbmc_res, f, indent=2)

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

def _save_dataset_csv_v3(dest_dir: Path, results: List[Dict[str, Any]]) -> None:
    """Writes or appends to random_dataset.csv for random_3."""
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

def run_random_3_dataset(
    dest_dir: Optional[Path] = None,
    count: int = 100,
    start_idx: Optional[int] = None,
    min_loc: int = 2000,
    max_loc: int = 2500,
    master_seed: int = 199000,
    max_workers: int = 8
) -> Dict[str, Any]:
    """
    Entry point to generate random_3 dataset (2000 <= LOC <= 2500).
    Can append to existing dataset automatically.
    """
    if dest_dir is None:
        workspace = Path(__file__).resolve().parent.parent.parent
        dest_dir = workspace / "datasets" / "random_3"

    dest_programs = dest_dir / "programs"
    dest_configs = dest_dir / "configs"
    dest_miters = dest_dir / "miters"
    dest_cbmc = dest_dir / "cbmc"
    dest_features = dest_dir / "features"

    for d in [dest_programs, dest_configs, dest_miters, dest_cbmc, dest_features]:
        d.mkdir(parents=True, exist_ok=True)

    # Determine start_idx if None
    if start_idx is None:
        existing_c = list(dest_programs.glob("R*.c"))
        if existing_c:
            existing_nums = [int(p.stem[1:]) for p in existing_c if p.stem[1:].isdigit()]
            start_idx = max(existing_nums) if existing_nums else 0
        else:
            start_idx = 0

    print(f"Starting generation from program index {start_idx + 1} (R{start_idx + 1:06d})...")

    # Pre-populate seen_hashes with all programs from random, random_2, and random_3
    workspace = dest_dir.parent.parent
    c_files_to_hash = []
    for prev_dir in [
        workspace / "datasets" / "random" / "programs",
        workspace / "datasets" / "random_2" / "programs",
        workspace / "datasets" / "random_3" / "programs"
    ]:
        if prev_dir.exists():
            c_files_to_hash.extend(list(prev_dir.glob("*.c")))

    with concurrent.futures.ThreadPoolExecutor(max_workers=16) as pool:
        seen_hashes = set(pool.map(lambda p: hashlib.sha256(p.read_bytes()).hexdigest(), c_files_to_hash))
    print(f"Pre-loaded {len(seen_hashes)} existing hashes across random, random_2, and random_3.")

    # Pre-populate seen_features from existing random_dataset.csv
    seen_features = set()
    csv_path = dest_dir / "random_dataset.csv"
    if csv_path.exists():
        with open(csv_path, "r", encoding="utf-8") as f:
            reader = csv.DictReader(f)
            for row in reader:
                feat_tuple = tuple(float(row.get(col, 0)) for col in FEATURE_COLS)
                seen_features.add(feat_tuple)
    print(f"Pre-loaded {len(seen_features)} existing feature vectors.")

    # Assign families evenly: 10 programs per family
    family_distribution = []
    progs_per_family = count // len(SECURITY_FAMILIES)
    remainder = count % len(SECURITY_FAMILIES)
    for idx, fam in enumerate(SECURITY_FAMILIES):
        alloc = progs_per_family + (1 if idx < remainder else 0)
        family_distribution.extend([fam] * alloc)

    print(f"Generating {count} distinct programs (2000 <= LOC <= 2500) across 10 families...")

    lock = threading.Lock()
    regeneration_log = []
    results = [None] * count
    t0 = time.time()

    def worker_task(i: int) -> Tuple[int, Dict[str, Any]]:
        prog_num = start_idx + i + 1
        prog_id = f"R{prog_num:06d}"
        family_id = family_distribution[i]
        initial_seed = master_seed + prog_num * 100 + 7
        res = process_single_v3_program(
            prog_id=prog_id,
            family_id=family_id,
            initial_seed=initial_seed,
            dest_dir=dest_dir,
            seen_hashes=seen_hashes,
            lock=lock,
            regeneration_log=regeneration_log,
            seen_features=seen_features,
            min_loc=min_loc,
            max_loc=max_loc
        )
        return i, res

    completed_count = 0
    with concurrent.futures.ThreadPoolExecutor(max_workers=max_workers) as executor:
        futures = {executor.submit(worker_task, i): i for i in range(count)}
        for future in concurrent.futures.as_completed(futures):
            i, res = future.result()
            results[i] = res
            completed_count += 1
            elapsed = time.time() - t0
            rate = completed_count / elapsed if elapsed > 0 else 0
            eta = (count - completed_count) / rate if rate > 0 else 0
            print(f"[{completed_count:3d}/{count:3d}] {completed_count*100/count:5.1f}% | LOC={res['loc']:4d} | "
                  f"ID={res['program_id']} | Family={res['family_id']:<23s} | Rate={rate:4.1f}/s | ETA={eta:3.0f}s")

    t1 = time.time()
    total_time = t1 - t0

    # Save random_dataset.csv (combining existing + new)
    _save_dataset_csv_v3(dest_dir, results)
    print(f"Saved dataset CSV to {dest_dir / 'random_dataset.csv'}")

    # Metrics summary across ALL rows in the updated random_dataset.csv
    with open(csv_path, "r", encoding="utf-8") as f:
        all_csv_records = list(csv.DictReader(f))

    locs = [int(float(r["loc"])) for r in all_csv_records if "loc" in r]
    min_loc_actual = min(locs) if locs else 0
    max_loc_actual = max(locs) if locs else 0
    avg_loc = sum(locs) / len(locs) if locs else 0

    from collections import Counter
    fam_counts = dict(Counter(r["family_id"] for r in all_csv_records))

    status_dist = {}
    for r in all_csv_records:
        leak = int(r.get("actual_mqil_leakage", 0))
        st = "VALID" if leak == 0 else "LEAKAGE_DETECTED"
        status_dist[st] = status_dist.get(st, 0) + 1

    report = {
        "dataset_name": "random_3",
        "total_programs": len(all_csv_records),
        "min_loc_target": min_loc,
        "max_loc_target": max_loc,
        "min_loc_actual": min_loc_actual,
        "max_loc_actual": max_loc_actual,
        "avg_loc": round(avg_loc, 2),
        "family_distribution": fam_counts,
        "dataset_status_distribution": status_dist,
        "newly_generated_in_this_run": count,
        "regenerations_count_in_this_run": len(regeneration_log),
        "total_execution_time_seconds": round(total_time, 2)
    }

    report_path = dest_dir / "random_dataset_report.json"
    with open(report_path, "w", encoding="utf-8") as f:
        json.dump(report, f, indent=2)

    print("\nDataset Generation Complete!")
    print(json.dumps(report, indent=2))
    return report

