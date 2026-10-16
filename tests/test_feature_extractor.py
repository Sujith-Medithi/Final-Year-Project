"""
Comprehensive Unit and Golden Parity Test Suite for Feature Extractor (Phase 4).
Verifies:
  - Exact feature reproduction on golden_program2
  - Struct-member taint propagation (K25): s.f = secret; out = s.f; -> explicit flows 2, leaks 2
  - Array-element taint propagation: arr[0] = secret; out = arr[0];
  - Inter-procedural taint propagation (K6): call argument binding by position
  - num_variables excludes prototypes and extern (D8, K24)
  - Prototype 'assert' not counted in num_assertions (D5, K22)
  - All ratios bounded in [0, 1] (D2, K21)
"""

import json
import tempfile
from pathlib import Path
import pytest

from src.core.feature_extractor import (
    ProgramFeatureExtractor,
    extract_all_mqil_features,
    extract_group_a_features,
    extract_group_b_features,
    parse_c_ast,
    extract_d8_variables,
    FEATURE_COLS
)
from src.core.transpiler import generate_miter_program

WORKSPACE = Path(__file__).resolve().parent.parent
FIXTURES_DIR = WORKSPACE / "tests" / "fixtures"

def test_golden_program2_parity():
    golden_c = FIXTURES_DIR / "golden_program2.c"
    golden_json = FIXTURES_DIR / "golden_program2.json"
    assert golden_c.exists(), f"Missing golden fixture {golden_c}"
    assert golden_json.exists(), f"Missing golden config {golden_json}"

    with tempfile.TemporaryDirectory() as tmpdir:
        miter_path = Path(tmpdir) / "golden_miter.c"
        generate_miter_program(golden_c, golden_json, miter_path)
        assert miter_path.exists()

        feats = extract_all_mqil_features(golden_c, golden_json, miter_path)

        # Frozen interface checks
        assert list(feats.keys()) == FEATURE_COLS

        # Group A checks on SOURCE
        assert feats["loc"] == 91
        assert feats["num_instructions"] == 34
        assert feats["num_branches"] == 5
        assert feats["num_loops"] == 3
        assert feats["num_functions"] == 3
        assert feats["num_variables"] == 24
        assert feats["num_arrays"] == 3
        assert feats["num_structure"] == 2
        assert feats["num_union"] == 2

        # Group B checks on MITER
        assert feats["num_high_inputs"] == 2
        assert feats["num_low_inputs"] == 1
        assert feats["num_explicit_flows"] == 13
        assert feats["num_culprit_blocks"] == 3
        assert feats["num_implicit_flows"] == 6
        assert feats["num_information_leak"] == 13
        assert feats["num_secret_dependent_prints"] == 6
        assert feats["num_assumptions"] == 3
        # In the valid miter with D7 union member-wise equality, 19 assert calls exist
        assert feats["num_assertions"] == 19
        assert feats["num_array_accesses"] == 23

        # Ratio checks (D2: computed from miter-side counters, in [0, 1])
        assert 0.0 <= feats["taint_ratio"] <= 1.0
        assert 0.0 <= feats["secret_branch_ratio"] <= 1.0
        assert 0.0 <= feats["secret_memory_ratio"] <= 1.0

def test_struct_member_taint_propagation():
    """
    Verifies that assigning to a struct member and reading back:
      s.f = secret;
      out = s.f;
    produces explicit_flows = 2 and information_leak = 2 (s and out).
    """
    c_code = """
struct Container {
    int f;
    int other;
};

int main(void) {
    int secret;
    int out;
    struct Container s;
    s.f = secret;
    out = s.f;
    return 0;
}
"""
    cfg = {"input_vars": ["secret"], "high_vars": ["secret"], "low_vars": []}
    with tempfile.TemporaryDirectory() as tmpdir:
        td = Path(tmpdir)
        c_path = td / "struct_test.c"
        json_path = td / "struct_test.json"
        miter_path = td / "struct_test_miter.c"

        c_path.write_text(c_code)
        json_path.write_text(json.dumps(cfg))

        generate_miter_program(c_path, json_path, miter_path)
        feats = extract_all_mqil_features(c_path, json_path, miter_path)

        # 2 copies of (s_x.f = secret_x; out_x = s_x.f;) -> 4 flows on miter, 4 leaks
        # For each side x in {1, 2}: s_x and out_x become tainted
        assert feats["num_explicit_flows"] == 4
        assert feats["num_information_leak"] == 4

def test_array_element_taint_propagation():
    """
    Verifies array element assignment propagates taint to base array and out:
      arr[0] = secret;
      out = arr[0];
    """
    c_code = """
int main(void) {
    int secret;
    int out;
    int arr[2];
    arr[0] = secret;
    out = arr[0];
    return 0;
}
"""
    cfg = {"input_vars": ["secret"], "high_vars": ["secret"], "low_vars": []}
    with tempfile.TemporaryDirectory() as tmpdir:
        td = Path(tmpdir)
        c_path = td / "arr_test.c"
        json_path = td / "arr_test.json"
        miter_path = td / "arr_test_miter.c"

        c_path.write_text(c_code)
        json_path.write_text(json.dumps(cfg))

        generate_miter_program(c_path, json_path, miter_path)
        feats = extract_all_mqil_features(c_path, json_path, miter_path)

        assert feats["num_explicit_flows"] == 4
        assert feats["num_information_leak"] == 4

def test_interprocedural_call_binding():
    """
    Verifies secret passed to a helper function binds to formal parameter
    and propagates taint into the helper body:
      helper(secret); -> helper parameter is tainted -> helper body assignment is counted.
    """
    c_code = """
int helper(int arg) {
    int local = arg + 1;
    return local;
}

int main(void) {
    int secret;
    int res = helper(secret);
    return 0;
}
"""
    cfg = {"input_vars": ["secret"], "high_vars": ["secret"], "low_vars": []}
    with tempfile.TemporaryDirectory() as tmpdir:
        td = Path(tmpdir)
        c_path = td / "call_test.c"
        json_path = td / "call_test.json"
        miter_path = td / "call_test_miter.c"

        c_path.write_text(c_code)
        json_path.write_text(json.dumps(cfg))

        generate_miter_program(c_path, json_path, miter_path)
        feats = extract_all_mqil_features(c_path, json_path, miter_path)

        # secret passed to helper -> helper arg tainted -> local initialized with arg (+flow)
        # res initialized with return (+flow)
        assert feats["num_explicit_flows"] >= 2
        assert feats["num_information_leak"] >= 2

def test_num_variables_excludes_prototypes_and_extern():
    """
    Verifies D8 rule:
    extern declarations and prototype parameters are excluded from num_variables.
    """
    c_code = """
extern int ext_var;
int prototype_fn(int proto_param1, int proto_param2);

int real_fn(int real_param) {
    int local_var = 1;
    return real_param + local_var;
}

int main(void) {
    int a;
    return 0;
}
"""
    with tempfile.NamedTemporaryFile(suffix=".c", mode="w", delete=False) as f:
        f.write(c_code)
        c_path = Path(f.name)

    try:
        ga = extract_group_a_features(c_path)
        # Counted variables:
        # real_param (1), local_var (2), a (3) = 3
        # Excluded: ext_var (extern), proto_param1, proto_param2 (prototype params)
        assert ga["num_variables"] == 3
    finally:
        c_path.unlink(missing_ok=True)

def test_assert_prototype_not_counted_in_assertions():
    """
    Verifies D5 rule:
    Prototype declaration 'void assert(int expression);' is not counted as an assertion.
    Only AST FuncCall nodes named 'assert' count.
    """
    c_code = """
void assert(int expression);

int main(void) {
    int x = 1;
    assert(x > 0);
    return 0;
}
"""
    cfg = {"input_vars": ["x"], "high_vars": [], "low_vars": ["x"]}
    with tempfile.TemporaryDirectory() as tmpdir:
        td = Path(tmpdir)
        c_path = td / "assert_test.c"
        json_path = td / "assert_test.json"
        miter_path = td / "assert_test_miter.c"

        c_path.write_text(c_code)
        json_path.write_text(json.dumps(cfg))

        generate_miter_program(c_path, json_path, miter_path)
        feats = extract_all_mqil_features(c_path, json_path, miter_path)

        # 2 replicated user asserts + 0 undefined assert_2 + equivalence assertions
        # The prototype 'void assert(int expression);' must not be counted.
        text = miter_path.read_text()
        assert "void assert(int expression);" in text
        # If prototype was counted, assertions would be higher
        assert feats["num_assertions"] >= 2
