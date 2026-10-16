"""
Unified Benchmark Synthesizer for MQIL.
Generates complete C programs across families with companion input_args.json.
Supports both Stage 1 (Canonical Baseline) and Scaled Benchmarks (e.g., 50, 100, 1000 programs).
"""

from pathlib import Path
import json
from typing import List, Dict, Any

from src.generator.program_templates import (
    STAGE1_CANONICAL_PROGRAMS,
    format_whole_c_program
)

def generate_stage1_benchmarks(dest_programs_dir: Path, dest_configs_dir: Path) -> List[Dict[str, Any]]:
    """Synthesizes the 12 Stage 1 canonical baseline programs and companion configs."""
    dest_programs_dir.mkdir(parents=True, exist_ok=True)
    dest_configs_dir.mkdir(parents=True, exist_ok=True)

    metadata = []
    for item in STAGE1_CANONICAL_PROGRAMS:
        pid = item["id"]
        c_code = format_whole_c_program(item["globals"], item["helpers"], item["body"], item["input_vars"])
        c_path = dest_programs_dir / f"{pid}.c"
        c_path.write_text(c_code, encoding="utf-8")

        config = {
            "input_vars": item["input_vars"],
            "high_vars": item["high_vars"],
            "low_vars": item["low_vars"]
        }
        json_path = dest_configs_dir / f"{pid}.json"
        with open(json_path, "w", encoding="utf-8") as f:
            json.dump(config, f, indent=2)

        metadata.append({
            **item,
            "c_path": c_path,
            "json_path": json_path
        })
    return metadata

def generate_stage2_benchmarks(dest_programs_dir: Path, dest_configs_dir: Path, count_per_family: int = 5) -> List[Dict[str, Any]]:
    """
    Synthesizes 50 Stage 2 validation programs (5 per family across 10 families).
    Varies bitmasks, loop bounds, arithmetic scalers, and branch thresholds.
    Tracks SHA-256 hashes to guarantee zero duplicate programs.
    """
    import hashlib
    dest_programs_dir.mkdir(parents=True, exist_ok=True)
    dest_configs_dir.mkdir(parents=True, exist_ok=True)

    seen_hashes = set()
    benchmarks = []
    pid_counter = 1

    families = [
        "zero_leakage", "direct_leakage", "partial_leakage", "implicit_flow",
        "arithmetic", "bitwise", "nested_branches", "loop_accumulator",
        "array_lookup", "mixed_control_data"
    ]

    for fam in families:
        for k in range(count_per_family):
            pid = f"P{pid_counter:06d}"
            pid_counter += 1

            if fam == "zero_leakage":
                helpers = f"int zero_kernel_{k}(int s, int p) {{\n    int temp = (s + {k * 3}) * 0;\n    return (temp + (p * {k + 2})) + 1;\n}}"
                body = f"    int out;\n    out = zero_kernel_{k}(high_sec, pub_val);\n    glob_zero_{k} = out;\n    int dead = high_sec ^ high_sec;\n    dead = 0;"
                globals_code = f"int glob_zero_{k};"
                input_vars = ["high_sec", "pub_val"]
                high_vars = ["high_sec"]
            elif fam == "direct_leakage":
                helpers = f"int direct_kernel_{k}(int h, int p) {{\n    int t1 = h + {k * 5};\n    return t1 - {k * 5} + p;\n}}"
                body = f"    int res;\n    res = direct_kernel_{k}(key_in, pub_in);\n    glob_direct_{k} = res;"
                globals_code = f"int glob_direct_{k};"
                input_vars = ["key_in", "pub_in"]
                high_vars = ["key_in"]
            elif fam == "partial_leakage":
                mask = [1, 3, 7, 15, 31][k % 5]
                shift = (k % 3) + 1
                helpers = f"int partial_kernel_{k}(int s, int b) {{\n    return ((s >> {shift}) & {mask}) + b;\n}}"
                body = f"    int part_out;\n    part_out = partial_kernel_{k}(secret_k, pub_bias);\n    glob_part_{k} = part_out;"
                globals_code = f"int glob_part_{k};"
                input_vars = ["secret_k", "pub_bias"]
                high_vars = ["secret_k"]
            elif fam == "implicit_flow":
                thresh = (k + 1) * 15
                helpers = f"int branch_kernel_{k}(int s, int u) {{\n    int flag = 0;\n    if (s > {thresh}) {{\n        flag = {k * 10 + 5};\n    }} else {{\n        flag = {k * 10 + 20};\n    }}\n    return flag + u;\n}}"
                body = f"    int branch_out;\n    branch_out = branch_kernel_{k}(sec_pw, pub_user);\n    glob_branch_{k} = branch_out;"
                globals_code = f"int glob_branch_{k};"
                input_vars = ["sec_pw", "pub_user"]
                high_vars = ["sec_pw"]
            elif fam == "arithmetic":
                multiplier = (k * 2) + 3
                bias = (k * 7) + 1
                helpers = f"int affine_kernel_{k}(int s, int sc) {{\n    return (((s * {multiplier} + {bias}) % 256) * sc);\n}}"
                body = f"    int arith_out;\n    arith_out = affine_kernel_{k}(sec_val, pub_scale);\n    glob_arith_{k} = arith_out;"
                globals_code = f"int glob_arith_{k};"
                input_vars = ["sec_val", "pub_scale"]
                high_vars = ["sec_val"]
            elif fam == "bitwise":
                mask_val = [0x55, 0xAA, 0x0F, 0xF0, 0x33][k % 5]
                rot = (k % 3) + 1
                helpers = f"int crypto_kernel_{k}(int tok, int n) {{\n    int x = (tok ^ {mask_val}) << {rot};\n    return x ^ n;\n}}"
                body = f"    int bit_out;\n    bit_out = crypto_kernel_{k}(sec_token, pub_nonce);\n    glob_bit_{k} = bit_out;"
                globals_code = f"int glob_bit_{k};"
                input_vars = ["sec_token", "pub_nonce"]
                high_vars = ["sec_token"]
            elif fam == "nested_branches":
                t1 = 20 + k * 10
                t2 = 50 + k * 10
                helpers = f"""int nested_kernel_{k}(int sc, int fl) {{
    int cat = 0;
    if (sc > {t2}) {{
        cat = 3;
    }} else {{
        if (sc > {t1}) {{ cat = 1; }} else {{ cat = 0; }}
    }}
    return cat + fl + {k};
}}"""
                body = f"    int nest_out;\n    nest_out = nested_kernel_{k}(sec_score, pub_flag);\n    glob_nest_{k} = nest_out;"
                globals_code = f"int glob_nest_{k};"
                input_vars = ["sec_score", "pub_flag"]
                high_vars = ["sec_score"]
            elif fam == "loop_accumulator":
                loop_limit = 2 + (k % 4)
                helpers = f"""int loop_kernel_{k}(int d, int seed) {{
    int acc = seed;
    for (int i = 0; i < {loop_limit}; i++) {{
        acc += ((d >> i) & 1) + {k};
    }}
    return acc;
}}"""
                body = f"    int loop_out;\n    loop_out = loop_kernel_{k}(sec_data, pub_seed);\n    glob_loop_{k} = loop_out;"
                globals_code = f"int glob_loop_{k};"
                input_vars = ["sec_data", "pub_seed"]
                high_vars = ["sec_data"]
            elif fam == "array_lookup":
                helpers = f"""int table_kernel_{k}(int idx, int base) {{
    int safe_idx = idx % 4;
    if (safe_idx < 0) safe_idx = -safe_idx;
    return lookup_table_{k}[safe_idx] + base;
}}"""
                body = f"    int arr_out;\n    arr_out = table_kernel_{k}(sec_idx, pub_base);\n    glob_arr_{k} = arr_out;"
                globals_code = f"int lookup_table_{k}[4] = {{10 + {k * 4}, 25 + {k}, 42, 99}}; int glob_arr_{k};"
                input_vars = ["sec_idx", "pub_base"]
                high_vars = ["sec_idx"]
            else: # mixed_control_data
                loop_cnt = 2 + (k % 2)
                helpers = f"""int hybrid_kernel_{k}(int param, int cfg) {{
    int state = cfg;
    for (int i = 0; i < {loop_cnt}; i++) {{
        if ((param >> i) & 1) {{ state += status_arr_{k}[i]; }}
        else {{ state -= 1; }}
    }}
    return state + {k};
}}"""
                body = f"    int mix_out;\n    mix_out = hybrid_kernel_{k}(sec_param, pub_config);\n    glob_mix_{k} = mix_out;"
                globals_code = f"int status_arr_{k}[3] = {{1 + {k}, 2, 4 + {k}}}; int glob_mix_{k};"
                input_vars = ["sec_param", "pub_config"]
                high_vars = ["sec_param"]

            low_vars = [v for v in input_vars if v not in high_vars]
            c_code = format_whole_c_program(globals_code, helpers, body, input_vars)

            # SHA-256 deduplication assertion
            code_hash = hashlib.sha256(c_code.strip().encode("utf-8")).hexdigest()
            assert code_hash not in seen_hashes, f"Duplicate program detected: {pid}"
            seen_hashes.add(code_hash)

            c_path = dest_programs_dir / f"{pid}.c"
            c_path.write_text(c_code, encoding="utf-8")

            config = {
                "input_vars": input_vars,
                "high_vars": high_vars,
                "low_vars": low_vars
            }
            json_path = dest_configs_dir / f"{pid}.json"
            with open(json_path, "w", encoding="utf-8") as f:
                json.dump(config, f, indent=2)

            benchmarks.append({
                "program_id": pid,
                "family_id": fam,
                "c_path": c_path,
                "json_path": json_path,
                "input_vars": input_vars,
                "high_vars": high_vars,
                "low_vars": low_vars,
                "sha256": code_hash
            })

    return benchmarks

def generate_scaled_benchmarks(dest_dir: Path, count_per_family: int = 10) -> List[Dict[str, Any]]:
    """
    Synthesizes diverse whole-program benchmarks across all 10 families.
    Saves programs organized cleanly in dest_dir/<family>/P*.c and P*_args.json.
    """
    dest_dir.mkdir(parents=True, exist_ok=True)
    benchmarks = []
    pid_counter = 1

    families = [
        "zero_leakage", "direct_leakage", "partial_leakage", "implicit_flow",
        "arithmetic", "bitwise", "nested_branches", "loop_accumulator",
        "array_lookup", "mixed_control_data"
    ]

    for fam in families:
        fam_dir = dest_dir / fam
        fam_dir.mkdir(parents=True, exist_ok=True)

        for k in range(count_per_family):
            pid = f"P{pid_counter:05d}"
            pid_counter += 1

            if fam == "zero_leakage":
                helpers = f"int zero_kernel_{k}(int s, int p) {{\n    int temp = (s + {k}) * 0;\n    return (temp + (p * 2)) + 1;\n}}"
                body = f"    int out;\n    out = zero_kernel_{k}(high_sec, pub_val);\n    glob_status_{k} = out;\n    int dead = high_sec + {k};\n    dead = 0;"
                globals_code = f"int glob_status_{k};"
                input_vars = ["high_sec", "pub_val"]
                high_vars = ["high_sec"]
            elif fam == "direct_leakage":
                helpers = f"int direct_kernel_{k}(int h, int p) {{\n    int t1 = h;\n    int t2 = t1 + {k};\n    return t2 - {k};\n}}"
                body = f"    int res;\n    res = direct_kernel_{k}(key_in, pub_in);\n    glob_out_{k} = res;"
                globals_code = f"int glob_out_{k};"
                input_vars = ["key_in", "pub_in"]
                high_vars = ["key_in"]
            elif fam == "partial_leakage":
                mask = [1, 3, 7, 15, 2, 4, 8, 12, 6, 14][k % 10]
                helpers = f"int partial_kernel_{k}(int s, int b) {{\n    return (s & {mask}) + b;\n}}"
                body = f"    int part_out;\n    part_out = partial_kernel_{k}(secret_k, pub_bias);\n    glob_part_{k} = part_out;"
                globals_code = f"int glob_part_{k};"
                input_vars = ["secret_k", "pub_bias"]
                high_vars = ["secret_k"]
            elif fam == "implicit_flow":
                thresh = (k + 1) * 10
                helpers = f"int branch_kernel_{k}(int s, int u) {{\n    int flag = 0;\n    if (s > {thresh}) {{\n        flag = 10;\n    }} else {{\n        flag = 20;\n    }}\n    return flag + u;\n}}"
                body = f"    int branch_out;\n    branch_out = branch_kernel_{k}(sec_pw, pub_user);\n    glob_branch_{k} = branch_out;"
                globals_code = f"int glob_branch_{k};"
                input_vars = ["sec_pw", "pub_user"]
                high_vars = ["sec_pw"]
            elif fam == "arithmetic":
                multiplier = (k % 4) + 2
                helpers = f"int affine_kernel_{k}(int s, int sc) {{\n    return ((s * {multiplier} + {k}) % 256) * sc;\n}}"
                body = f"    int arith_out;\n    arith_out = affine_kernel_{k}(sec_val, pub_scale);\n    glob_arith_{k} = arith_out;"
                globals_code = f"int glob_arith_{k};"
                input_vars = ["sec_val", "pub_scale"]
                high_vars = ["sec_val"]
            elif fam == "bitwise":
                mask_val = [0x55, 0xAA, 0x0F, 0xF0, 0x33, 0xCC][k % 6]
                helpers = f"int crypto_kernel_{k}(int tok, int n) {{\n    int x = (tok ^ {mask_val}) << 1;\n    return x ^ n;\n}}"
                body = f"    int bit_out;\n    bit_out = crypto_kernel_{k}(sec_token, pub_nonce);\n    glob_bit_{k} = bit_out;"
                globals_code = f"int glob_bit_{k};"
                input_vars = ["sec_token", "pub_nonce"]
                high_vars = ["sec_token"]
            elif fam == "nested_branches":
                helpers = f"""int nested_kernel_{k}(int sc, int fl) {{
    int cat = 0;
    if (sc > 50) {{
        if (sc > 80) {{ cat = 3; }} else {{ cat = 2; }}
    }} else {{
        if (sc > 20) {{ cat = 1; }} else {{ cat = 0; }}
    }}
    return cat + fl + {k};
}}"""
                body = f"    int nest_out;\n    nest_out = nested_kernel_{k}(sec_score, pub_flag);\n    glob_nest_{k} = nest_out;"
                globals_code = f"int glob_nest_{k};"
                input_vars = ["sec_score", "pub_flag"]
                high_vars = ["sec_score"]
            elif fam == "loop_accumulator":
                helpers = f"""int loop_kernel_{k}(int d, int seed) {{
    int acc = seed;
    for (int i = 0; i < 4; i++) {{
        acc += ((d >> i) & 1) + {k};
    }}
    return acc;
}}"""
                body = f"    int loop_out;\n    loop_out = loop_kernel_{k}(sec_data, pub_seed);\n    glob_loop_{k} = loop_out;"
                globals_code = f"int glob_loop_{k};"
                input_vars = ["sec_data", "pub_seed"]
                high_vars = ["sec_data"]
            elif fam == "array_lookup":
                helpers = f"""int table_kernel_{k}(int idx, int base) {{
    int safe_idx = idx % 4;
    if (safe_idx < 0) safe_idx = -safe_idx;
    return lookup_table_{k}[safe_idx] + base;
}}"""
                body = f"    int arr_out;\n    arr_out = table_kernel_{k}(sec_idx, pub_base);\n    glob_arr_{k} = arr_out;"
                globals_code = f"int lookup_table_{k}[4] = {{10 + {k}, 25, 42, 99}}; int glob_arr_{k};"
                input_vars = ["sec_idx", "pub_base"]
                high_vars = ["sec_idx"]
            else: # mixed_control_data
                helpers = f"""int hybrid_kernel_{k}(int param, int cfg) {{
    int state = cfg;
    for (int i = 0; i < 2; i++) {{
        if ((param >> i) & 1) {{ state += status_arr_{k}[i]; }}
        else {{ state -= 1; }}
    }}
    return state + {k};
}}"""
                body = f"    int mix_out;\n    mix_out = hybrid_kernel_{k}(sec_param, pub_config);\n    glob_mix_{k} = mix_out;"
                globals_code = f"int status_arr_{k}[3] = {{1, 2, 4}}; int glob_mix_{k};"
                input_vars = ["sec_param", "pub_config"]
                high_vars = ["sec_param"]

            low_vars = [v for v in input_vars if v not in high_vars]
            c_code = format_whole_c_program(globals_code, helpers, body, input_vars)

            c_path = fam_dir / f"{pid}.c"
            c_path.write_text(c_code, encoding="utf-8")

            config = {
                "input_vars": input_vars,
                "high_vars": high_vars,
                "low_vars": low_vars
            }
            json_path = fam_dir / f"{pid}_args.json"
            with open(json_path, "w", encoding="utf-8") as f:
                json.dump(config, f, indent=2)

            benchmarks.append({
                "program_id": pid,
                "family_id": fam,
                "c_path": c_path,
                "json_path": json_path,
                "input_vars": input_vars,
                "high_vars": high_vars,
                "low_vars": low_vars
            })

    return benchmarks
