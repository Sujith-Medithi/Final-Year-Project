"""
Random Program Generator V4: High-Scale, Ultra-Diverse C Benchmarks for random_4.
Enforces:
  - Strict 2000 <= LOC <= 2500
  - num_high_inputs > 15 (random in [16, 22])
  - num_low_inputs > 15 (random in [16, 22])
  - Heterogeneous, un-patterned features across and within families
  - Full CBMC verification (--no-standard-checks, --unwind 5)
  - Full whole-program AST feature extraction
  - Inter-file code and feature-vector uniqueness
"""

import random
from pathlib import Path
from typing import Dict, Any, List, Tuple, Optional, Set
import hashlib
import json
import csv
import concurrent.futures
import threading
import time
from collections import Counter

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

def _generate_types_v4(rng: random.Random, prefix: str) -> Tuple[List[str], List[str], List[str]]:
    """Generates 2 to 4 unique struct/union definitions with diverse fields and variable array sizes."""
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
        buf_size = 3
        lines.append(f"    int buffer[{buf_size}];")
        lines.append("};")
        lines.append("")

    num_unions = rng.choice([1, 2])
    chosen_unions = rng.sample(UNION_THEMES, num_unions)
    for idx, (base_u, ufields) in enumerate(chosen_unions):
        uname = f"{base_u}_{prefix}_{idx}"
        union_names.append(uname)
        lines.append(f"union {uname} {{")
        lines.append("    int word;")
        lines.append("    unsigned char raw[4];")
        lines.append("    short pairs[2];")
        lines.append("};")
        lines.append("")

    return lines, struct_names, union_names

def _generate_single_helper_v4(
    rng: random.Random,
    fname: str,
    struct_names: List[str],
    union_names: List[str],
    prefix: str
) -> Tuple[List[str], int]:
    """Generates a genuinely unique helper function with randomized logic."""
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
            lines.append(f"        default: acc = (acc + 7) & 127; break;")
            lines.append("    }")

        elif arch == "array_transform":
            lines.append("    int local_arr[3] = {4, 9, 15};")
            lines.append(f"    int {v1} = local_arr[aux % 3];")
            lines.append(f"    acc = (acc + {v1} * 2) & 127;")

        elif arch == "bitwise_mix":
            lines.append(f"    int {v1} = ((acc << 1) ^ (aux >> 1)) & 63;")
            lines.append(f"    aux = (aux + {v1}) & 63;")
            lines.append(f"    acc ^= aux;")

        elif arch == "struct_mutation":
            lines.append(f"    st.buffer[1] = (st.buffer[1] + {rng.randint(1, 9)}) & 15;")
            lines.append(f"    acc = (acc + st.buffer[1]) & 127;")

    lines.append("    return (acc + aux) & 255;")
    lines.append("}")
    lines.append("")
    return lines, param_count

def _generate_security_flow_v4(
    rng: random.Random,
    family: str,
    high_vars: List[str],
    low_vars: List[str]
) -> List[str]:
    """
    Generates non-patterned, highly randomized security flows utilizing multiple inputs (>15 inputs available).
    Ensures that every program has distinct feature values even within the same family.
    """
    lines = []
    lines.append(f"    /* Security Information Flow: Family = {family} */")

    # Pick random subsets of high and low variables
    k_high = rng.randint(2, min(5, len(high_vars)))
    chosen_high = rng.sample(high_vars, k_high)
    k_low = rng.randint(2, min(5, len(low_vars)))
    chosen_low = rng.sample(low_vars, k_low)

    h0 = chosen_high[0]
    h1 = chosen_high[1]
    p0 = chosen_low[0]

    if family == "zero_leakage":
        num_dead_ops = rng.randint(2, 5)
        dead_vars = []
        for i in range(num_dead_ops):
            dvar = f"dead_sec_{i}"
            dead_vars.append(dvar)
            h_pick = chosen_high[i % len(chosen_high)]
            op_kind = rng.choice(["xor_zero", "sub_zero", "and_zero", "shift_zero"])
            if op_kind == "xor_zero":
                lines.append(f"    int {dvar} = ({h_pick} ^ {h_pick}) * 0;")
            elif op_kind == "sub_zero":
                c = rng.randint(3, 30)
                lines.append(f"    int {dvar} = (({h_pick} + {c}) - ({h_pick} + {c})) * 0;")
            elif op_kind == "and_zero":
                lines.append(f"    int {dvar} = ({h_pick} & 0) * 0;")
            else:
                lines.append(f"    int {dvar} = (({h_pick} << 2) ^ ({h_pick} << 2)) * 0;")
        sum_dead = " + ".join(dead_vars)
        lines.append(f"    out_sink = (out_sink + {sum_dead}) & 255;")

    elif family == "direct_leakage":
        num_leak_vars = rng.randint(1, min(4, len(chosen_high)))
        terms = []
        for i in range(num_leak_vars):
            h_var = chosen_high[i]
            coeff = rng.choice([1, 2, 3])
            terms.append(f"({h_var} * {coeff})")
        expr = " + ".join(terms)
        lines.append(f"    out_sink += ({expr}) & 255;")

    elif family == "multi_step_explicit":
        depth = rng.randint(3, 7)
        prev_var = h0
        for step in range(depth):
            vname = f"m_step_{step}"
            p_add = chosen_low[step % len(chosen_low)]
            c_add = rng.randint(5, 35)
            lines.append(f"    int {vname} = ({prev_var} + {p_add} + {c_add}) & 127;")
            prev_var = vname
        lines.append(f"    out_sink = (out_sink + {prev_var}) & 255;")

    elif family == "arithmetic_flow":
        num_ops = rng.randint(2, 4)
        curr_var = f"arith_v_0"
        lines.append(f"    int {curr_var} = ({h0} * 3 + {p0}) & 127;")
        for i in range(1, num_ops):
            next_var = f"arith_v_{i}"
            h_cur = chosen_high[i % len(chosen_high)]
            op = rng.choice(["+", "-", "^"])
            lines.append(f"    int {next_var} = ({curr_var} {op} ({h_cur} * 2)) & 127;")
            curr_var = next_var
        lines.append(f"    out_sink += {curr_var} & 255;")

    elif family == "bitwise_flow":
        num_ops = rng.randint(3, 6)
        lines.append(f"    int b_w0 = ({h0} ^ 0x5A) & 63;")
        prev = "b_w0"
        for i in range(1, num_ops):
            bname = f"b_w{i}"
            h_cur = chosen_high[i % len(chosen_high)]
            shift = rng.choice([1, 2])
            op = rng.choice(["^", "&", "|"])
            lines.append(f"    int {bname} = (({prev} << {shift}) {op} ({h_cur} >> {shift})) & 63;")
            prev = bname
        lines.append(f"    out_sink += {prev} & 63;")

    elif family == "implicit_flow":
        branches = rng.randint(1, 3)
        for b in range(branches):
            h_cur = chosen_high[b % len(chosen_high)]
            thresh = rng.randint(5, 40)
            c1 = rng.randint(10, 80)
            c2 = rng.randint(10, 80)
            lines.append(f"    if (({h_cur} & 63) > {thresh}) {{")
            lines.append(f"        out_sink += {c1};")
            lines.append("    } else {")
            lines.append(f"        out_sink -= {c2};")
            lines.append("    }")

    elif family == "nested_implicit_flow":
        lines.append(f"    if (({h0} & 1) != 0) {{")
        lines.append(f"        if (({h1} & 2) != 0) {{")
        lines.append(f"            out_sink += {rng.randint(20, 60)};")
        lines.append("        } else {")
        lines.append(f"            out_sink += {rng.randint(10, 30)};")
        lines.append("        }")
        lines.append("    } else {")
        h2 = chosen_high[2 % len(chosen_high)]
        lines.append(f"        if (({h2} & 4) != 0) {{")
        lines.append(f"            out_sink -= {rng.randint(10, 30)};")
        lines.append("        } else {")
        lines.append(f"            out_sink -= {rng.randint(30, 70)};")
        lines.append("        }")
        lines.append("    }")

    elif family == "secret_dependent_loops":
        num_loops = rng.randint(1, 2)
        for l in range(num_loops):
            h_cur = chosen_high[l % len(chosen_high)]
            lines.append(f"    int l_bound_{l} = ({h_cur} & 1) + 1;")
            lines.append(f"    for (int it = 0; it < l_bound_{l}; it++) {{")
            lines.append(f"        out_sink += (it * 3 + {rng.randint(2, 8)});")
            lines.append("    }")

    elif family == "secret_dependent_array":
        lut_size = 4
        lut_vals = [rng.randint(10, 99) for _ in range(lut_size)]
        lut_str = ", ".join(str(v) for v in lut_vals)
        lines.append(f"    int s_lut[{lut_size}] = {{ {lut_str} }};")
        mask = lut_size - 1
        lines.append(f"    int s_idx = ({h0} & {mask});")
        lines.append(f"    out_sink += s_lut[s_idx];")

    elif family == "mixed_control_data":
        lines.append(f"    int m_var = ({h0} ^ 0x55) & 63;")
        thresh = rng.randint(15, 35)
        lines.append(f"    if (m_var > {thresh}) {{")
        lines.append(f"        out_sink += (m_var * 2 + {p0}) & 127;")
        lines.append("    } else {")
        lines.append(f"        out_sink -= (m_var + {rng.randint(5, 15)}) & 31;")
        lines.append("    }")
        lines.append(f"    out_sink ^= ({h1} & 15);")

    lines.append("")
    return lines

def generate_diverse_c_program_v4(
    prog_id: str,
    family: str,
    seed: int,
    min_loc: int = 2000,
    max_loc: int = 2500
) -> Tuple[str, Dict[str, Any]]:
    """
    Generates a genuinely unique, structurally distinct C program for random_4.
    Guarantees:
      - 2000 <= LOC <= 2500
      - num_high_inputs > 15 (random in [16, 22])
      - num_low_inputs > 15 (random in [16, 22])
      - Unique structural and feature variation
    """
    rng = random.Random(seed)

    # Inputs: strictly above 15
    num_high = rng.randint(16, 22)
    num_low = rng.randint(16, 22)
    high_vars = [f"sec_{prog_id.lower()}_{i}" for i in range(num_high)]
    low_vars = [f"pub_{prog_id.lower()}_{i}" for i in range(num_low)]
    input_vars = high_vars + low_vars

    prefix = f"{prog_id}_{seed % 10000}"

    lines = []
    lines.append("/*")
    lines.append(f" * Benchmark Program: {prog_id}")
    lines.append(f" * Family: {family}")
    lines.append(f" * Generator Seed: {seed}")
    lines.append(f" * High Inputs: {num_high} | Low Inputs: {num_low}")
    lines.append(" */")
    lines.append("#include <stdio.h>")
    lines.append("#include <stdlib.h>")
    lines.append("#include <stdbool.h>")
    lines.append("#include <string.h>")
    lines.append("")

    # Types (Structs & Unions)
    type_lines, struct_names, union_names = _generate_types_v4(rng, prefix)
    lines.extend(type_lines)

    # Globals
    lines.append("int g_out = 0;")
    lines.append("int g_chk = 0;")
    lines.append("")

    # Generate 14 to 26 diverse helper functions
    num_helpers = rng.randint(14, 26)
    helper_names = []
    helper_param_counts = []
    for f in range(num_helpers):
        fname = f"fn_{prefix}_{f}"
        helper_names.append(fname)
        hlines, pcount = _generate_single_helper_v4(rng, fname, struct_names, union_names, prefix)
        helper_param_counts.append(pcount)
        lines.extend(hlines)

    target_loc = rng.randint(min_loc + 50, max_loc - 50)

    # Build main()
    lines.append("int main() {")
    for var in input_vars:
        lines.append(f"    int {var};")
    lines.append("    int out_sink = 0;")
    lines.append("    int chk_sum = 0;")
    lines.append("")

    # Add assumptions for low inputs and high inputs
    for var in low_vars:
        lines.append(f"    __CPROVER_assume({var} >= -100 && {var} <= 100);")
    for var in high_vars:
        lines.append(f"    __CPROVER_assume({var} >= 0 && {var} <= 255);")
    lines.append("")

    # Allocate instances of generated structs & unions
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

    # Pipeline stages until target LOC is reached
    stage = 0
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
        est_remaining = 45  # security flow + closing
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

    # Security Information Flow
    sec_lines = _generate_security_flow_v4(rng, family, high_vars, low_vars)
    lines.extend(sec_lines)

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

def process_single_v4_program(
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
    Generates, miters, verifies with CBMC, and extracts features for a single V4 benchmark.
    Guarantees 2000 <= LOC <= 2500, inputs > 15, distinct SHA-256, and unique feature vector.
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
        source_code, config = generate_diverse_c_program_v4(
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

        # In zero_leakage family, CBMC must prove 0 leakage
        if family_id == "zero_leakage" and cbmc_res.get("actual_mqil_leakage", -1) != 0:
            with lock:
                seen_hashes.remove(sha256)
                regeneration_log.append({
                    "program_id": prog_id,
                    "seed": current_seed,
                    "reason": "zero_leakage program leaked non-zero bits"
                })
            current_seed += 1000
            continue

        # In leaking families, CBMC must detect leakage
        if family_id != "zero_leakage" and cbmc_res.get("actual_mqil_leakage", 0) == 0:
            with lock:
                seen_hashes.remove(sha256)
                regeneration_log.append({
                    "program_id": prog_id,
                    "seed": current_seed,
                    "reason": "leaking family did not leak"
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

def _save_dataset_csv_v4(dest_dir: Path, results: List[Dict[str, Any]]) -> None:
    """Writes or appends to random_dataset.csv for random_4."""
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

def run_random_4_dataset(
    dest_dir: Optional[Path] = None,
    count: int = 1000,
    start_idx: Optional[int] = None,
    min_loc: int = 2000,
    max_loc: int = 2500,
    master_seed: int = 400000,
    max_workers: int = 10
) -> Dict[str, Any]:
    """
    Entry point to generate random_4 dataset (1000 programs, 2000 <= LOC <= 2500).
    """
    if dest_dir is None:
        workspace = Path(__file__).resolve().parent.parent.parent
        dest_dir = workspace / "datasets" / "random_4"

    dest_programs = dest_dir / "programs"
    dest_configs = dest_dir / "configs"
    dest_miters = dest_dir / "miters"
    dest_cbmc = dest_dir / "cbmc"
    dest_features = dest_dir / "features"

    for d in [dest_programs, dest_configs, dest_miters, dest_cbmc, dest_features]:
        d.mkdir(parents=True, exist_ok=True)

    if start_idx is None:
        existing_c = list(dest_programs.glob("R*.c"))
        if existing_c:
            existing_nums = [int(p.stem[1:]) for p in existing_c if p.stem[1:].isdigit()]
            start_idx = max(existing_nums) if existing_nums else 0
        else:
            start_idx = 0

    print(f"Starting generation for random_4 from program index {start_idx + 1} (R{start_idx + 1:06d})...")

    # Pre-populate seen_hashes with all programs from random, random_2, random_3, and random_4
    workspace = dest_dir.parent.parent
    c_files_to_hash = []
    for prev_dir in [
        workspace / "datasets" / "random" / "programs",
        workspace / "datasets" / "random_2" / "programs",
        workspace / "datasets" / "random_3" / "programs",
        workspace / "datasets" / "random_4" / "programs"
    ]:
        if prev_dir.exists():
            c_files_to_hash.extend(list(prev_dir.glob("*.c")))

    with concurrent.futures.ThreadPoolExecutor(max_workers=16) as pool:
        seen_hashes = set(pool.map(lambda p: hashlib.sha256(p.read_bytes()).hexdigest(), c_files_to_hash))
    print(f"Pre-loaded {len(seen_hashes)} existing hashes across random, random_2, random_3, and random_4.")

    seen_features = set()
    csv_path = dest_dir / "random_dataset.csv"
    if csv_path.exists():
        with open(csv_path, "r", encoding="utf-8") as f:
            reader = csv.DictReader(f)
            for row in reader:
                feat_tuple = tuple(float(row.get(col, 0)) for col in FEATURE_COLS)
                seen_features.add(feat_tuple)
    print(f"Pre-loaded {len(seen_features)} existing feature vectors.")

    # Assign families evenly: count // len(SECURITY_FAMILIES) per family
    family_distribution = []
    progs_per_family = count // len(SECURITY_FAMILIES)
    remainder = count % len(SECURITY_FAMILIES)
    for idx, fam in enumerate(SECURITY_FAMILIES):
        alloc = progs_per_family + (1 if idx < remainder else 0)
        family_distribution.extend([fam] * alloc)

    print(f"Generating {count} distinct programs (2000 <= LOC <= 2500, High/Low inputs > 15) across 10 families...")

    lock = threading.Lock()
    regeneration_log = []
    results = [None] * count
    t0 = time.time()

    def worker_task(i: int) -> Tuple[int, Dict[str, Any]]:
        prog_num = start_idx + i + 1
        prog_id = f"R{prog_num:06d}"
        family_id = family_distribution[i]
        initial_seed = master_seed + prog_num * 100 + 13
        res = process_single_v4_program(
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
            high_in = res["features"]["num_high_inputs"]
            low_in = res["features"]["num_low_inputs"]
            print(f"[{completed_count:4d}/{count:4d}] {completed_count*100/count:5.1f}% | LOC={res['loc']:4d} | "
                  f"ID={res['program_id']} | H={high_in:2d}/L={low_in:2d} | Fam={res['family_id']:<23s} | "
                  f"Rate={rate:4.2f}/s | ETA={eta:4.0f}s")

    t1 = time.time()
    total_time = t1 - t0

    _save_dataset_csv_v4(dest_dir, results)
    print(f"Saved dataset CSV to {dest_dir / 'random_dataset.csv'}")

    with open(csv_path, "r", encoding="utf-8") as f:
        all_csv_records = list(csv.DictReader(f))

    locs = [int(float(r["loc"])) for r in all_csv_records if "loc" in r]
    min_loc_actual = min(locs) if locs else 0
    max_loc_actual = max(locs) if locs else 0
    avg_loc = sum(locs) / len(locs) if locs else 0

    fam_counts = dict(Counter(r["family_id"] for r in all_csv_records))

    status_dist = {}
    for r in all_csv_records:
        leak_val = str(r.get("actual_mqil_leakage", "")).strip()
        leak = int(float(leak_val)) if leak_val and leak_val != "None" else -1
        if leak == 0:
            st = "VALID"
        elif leak > 0:
            st = "LEAKAGE_DETECTED"
        else:
            st = "UNKNOWN"
        status_dist[st] = status_dist.get(st, 0) + 1

    report = {
        "dataset_name": "random_4",
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
