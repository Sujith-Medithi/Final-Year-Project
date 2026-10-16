"""
Unified Program Templates and Canonical Kernels for MQIL Benchmarks.
Consolidates all 10 canonical leakage families:
  1. zero_leakage
  2. direct_leakage
  3. partial_leakage
  4. implicit_flow
  5. arithmetic
  6. bitwise
  7. nested_branches
  8. loop_accumulator
  9. array_lookup
  10. mixed_control_data
  Plus edge-cases: multi_secret and zero_leakage_cancel
"""

from typing import List, Dict, Any, Tuple

STAGE1_CANONICAL_PROGRAMS: List[Dict[str, Any]] = [
    {
        "id": "P000001",
        "family": "zero_leakage",
        "desc": "High input multiplied by zero; only public input influences output.",
        "globals": "int glob_zero_1 = 0;",
        "helpers": "int zero_kernel_1(int s, int p) {\n    int dead = s * 0;\n    return p * 2 + 1;\n}",
        "body": "    int out;\n    out = zero_kernel_1(high_sec, pub_val);\n    glob_zero_1 = out;",
        "input_vars": ["high_sec", "pub_val"],
        "high_vars": ["high_sec"],
        "low_vars": ["pub_val"]
    },
    {
        "id": "P000002",
        "family": "direct_leakage",
        "desc": "High secret input forwarded directly to global output variable.",
        "globals": "int glob_direct_2 = 0;",
        "helpers": "int direct_kernel_2(int h, int p) {\n    int t = h + 10;\n    return t - 10;\n}",
        "body": "    int res;\n    res = direct_kernel_2(key_in, pub_in);\n    glob_direct_2 = res;",
        "input_vars": ["key_in", "pub_in"],
        "high_vars": ["key_in"],
        "low_vars": ["pub_in"]
    },
    {
        "id": "P000003",
        "family": "partial_leakage",
        "desc": "Secret key truncated via 4-bit mask (secret & 0x0F) plus public bias.",
        "globals": "int glob_partial_3 = 0;",
        "helpers": "int mask_kernel_3(int s, int b) {\n    int masked = s & 15;\n    return masked + b;\n}",
        "body": "    int partial_out;\n    partial_out = mask_kernel_3(secret_k, pub_bias);\n    glob_partial_3 = partial_out;",
        "input_vars": ["secret_k", "pub_bias"],
        "high_vars": ["secret_k"],
        "low_vars": ["pub_bias"]
    },
    {
        "id": "P000004",
        "family": "implicit_flow",
        "desc": "Control flow branch dependent on secret password threshold.",
        "globals": "int glob_implicit_4 = 0;",
        "helpers": "int branch_kernel_4(int secret, int pub_id) {\n    int flag = 0;\n    if (secret > 100) {\n        flag = 1;\n    } else {\n        flag = 2;\n    }\n    return flag + pub_id;\n}",
        "body": "    int outcome;\n    outcome = branch_kernel_4(sec_pw, pub_user);\n    glob_implicit_4 = outcome;",
        "input_vars": ["sec_pw", "pub_user"],
        "high_vars": ["sec_pw"],
        "low_vars": ["pub_user"]
    },
    {
        "id": "P000005",
        "family": "arithmetic",
        "desc": "Affine algebraic transformation (3*s + 7) mod 256 combined with public scaling.",
        "globals": "int glob_arith_5 = 0;",
        "helpers": "int affine_kernel_5(int s, int scale) {\n    int temp = (s * 3 + 7) % 256;\n    return temp * scale;\n}",
        "body": "    int val;\n    val = affine_kernel_5(sec_val, pub_scale);\n    glob_arith_5 = val;",
        "input_vars": ["sec_val", "pub_scale"],
        "high_vars": ["sec_val"],
        "low_vars": ["pub_scale"]
    },
    {
        "id": "P000006",
        "family": "bitwise",
        "desc": "Cryptographic XOR mask with 0xAA and 1-bit rotation.",
        "globals": "int glob_bit_6 = 0;",
        "helpers": "int crypto_kernel_6(int token, int nonce) {\n    int x = (token ^ 170) << 1;\n    return x ^ nonce;\n}",
        "body": "    int bit_res;\n    bit_res = crypto_kernel_6(sec_token, pub_nonce);\n    glob_bit_6 = bit_res;",
        "input_vars": ["sec_token", "pub_nonce"],
        "high_vars": ["sec_token"],
        "low_vars": ["pub_nonce"]
    },
    {
        "id": "P000007",
        "family": "nested_branches",
        "desc": "Multi-tier nested decision intervals leaking secret category.",
        "globals": "int glob_nested_7 = 0;",
        "helpers": """int classify_kernel_7(int score, int flag) {
    int cat = 0;
    if (score > 50) {
        if (score > 80) { cat = 3; } else { cat = 2; }
    } else {
        if (score > 20) { cat = 1; } else { cat = 0; }
    }
    return cat + flag;
}""",
        "body": "    int level;\n    level = classify_kernel_7(sec_score, pub_flag);\n    glob_nested_7 = level;",
        "input_vars": ["sec_score", "pub_flag"],
        "high_vars": ["sec_score"],
        "low_vars": ["pub_flag"]
    },
    {
        "id": "P000008",
        "family": "loop_accumulator",
        "desc": "Bounded loop extracting and accumulating 4 secret bits.",
        "globals": "int glob_loop_8 = 0;",
        "helpers": """int loop_kernel_8(int data, int seed) {
    int acc = seed;
    for (int i = 0; i < 4; i++) {
        acc += (data >> i) & 1;
    }
    return acc;
}""",
        "body": "    int sum;\n    sum = loop_kernel_8(sec_data, pub_seed);\n    glob_loop_8 = sum;",
        "input_vars": ["sec_data", "pub_seed"],
        "high_vars": ["sec_data"],
        "low_vars": ["pub_seed"]
    },
    {
        "id": "P000009",
        "family": "array_lookup",
        "desc": "Cache-timing style lookup into precomputed substitution table.",
        "globals": "int lookup_table_9[4] = {10, 25, 42, 99}; int glob_arr_9 = 0;",
        "helpers": """int table_kernel_9(int idx, int base) {
    int safe_idx = idx % 4;
    if (safe_idx < 0) safe_idx = -safe_idx;
    return lookup_table_9[safe_idx] + base;
}""",
        "body": "    int lookup_val;\n    lookup_val = table_kernel_9(sec_idx, pub_base);\n    glob_arr_9 = lookup_val;",
        "input_vars": ["sec_idx", "pub_base"],
        "high_vars": ["sec_idx"],
        "low_vars": ["pub_base"]
    },
    {
        "id": "P000010",
        "family": "mixed_control_data",
        "desc": "Hybrid control and data flow combining arrays, loops, and conditions.",
        "globals": "int status_arr_10[3] = {1, 2, 4}; int glob_mix_10 = 0;",
        "helpers": """int hybrid_kernel_10(int param, int config) {
    int state = config;
    for (int i = 0; i < 2; i++) {
        if ((param >> i) & 1) { state += status_arr_10[i]; }
        else { state -= 1; }
    }
    return state;
}""",
        "body": "    int final_st;\n    final_st = hybrid_kernel_10(sec_param, pub_config);\n    glob_mix_10 = final_st;",
        "input_vars": ["sec_param", "pub_config"],
        "high_vars": ["sec_param"],
        "low_vars": ["pub_config"]
    },
    {
        "id": "P000011",
        "family": "multi_secret",
        "desc": "Two independent secret keys combined with public nonce.",
        "globals": "int glob_multi_11 = 0;",
        "helpers": "int multi_kernel_11(int k1, int k2, int nonce) {\n    int comb = (k1 & 15) ^ (k2 & 15);\n    return comb + nonce;\n}",
        "body": "    int combo_out;\n    combo_out = multi_kernel_11(sec_key1, sec_key2, pub_nonce);\n    glob_multi_11 = combo_out;",
        "input_vars": ["sec_key1", "sec_key2", "pub_nonce"],
        "high_vars": ["sec_key1", "sec_key2"],
        "low_vars": ["pub_nonce"]
    },
    {
        "id": "P000012",
        "family": "zero_leakage_cancel",
        "desc": "High secret input self-annihilation via XOR (s ^ s) leaving strictly public value.",
        "globals": "int glob_cancel_12 = 0;",
        "helpers": "int cancel_kernel_12(int pin, int mode) {\n    int zero = pin ^ pin;\n    return zero + mode * 5;\n}",
        "body": "    int verified_zero;\n    verified_zero = cancel_kernel_12(sec_pin, pub_mode);\n    glob_cancel_12 = verified_zero;",
        "input_vars": ["sec_pin", "pub_mode"],
        "high_vars": ["sec_pin"],
        "low_vars": ["pub_mode"]
    }
]

def format_whole_c_program(globals_code: str, helper_funcs: str, body: str, input_vars: List[str]) -> str:
    """Formats a whole compilable C program with standard headers and uninitialized symbolic inputs in main for CBMC."""
    main_decls = "\n".join([f"    int {v};" for v in input_vars])
    return f"""#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

{globals_code}

{helper_funcs}

int main()
{{
{main_decls}
{body}
    return 0;
}}
"""

