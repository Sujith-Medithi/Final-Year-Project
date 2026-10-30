"""
Automated Smoke and Invariant Verification Test Suite.
Verifies:
  - Stage 1 canonical baseline & input transparency
  - Non-interference invariants (P000001, P000012 #leak==0, leaking programs #leak>0)
  - Stage 2 scaled dataset and splits integrity
  - Serialized model and report deliverables
"""

from pathlib import Path
import json
import pandas as pd
import pytest

import sys
WORKSPACE = Path(__file__).resolve().parent.parent
if str(WORKSPACE) not in sys.path:
    sys.path.insert(0, str(WORKSPACE))
DATASETS_DIR = WORKSPACE / "datasets"
RESULTS_DIR = WORKSPACE / "results"

def test_stage1_dataset_invariants():
    s1_csv = DATASETS_DIR / "stage1_smoke" / "dataset.csv"
    assert s1_csv.exists(), f"Missing Stage 1 CSV: {s1_csv}"
    
    df = pd.read_csv(s1_csv)
    assert len(df) == 12, f"Expected 12 programs, found {len(df)}"
    assert df.isna().sum().sum() == 0, "Stage 1 contains NaN values"

    # Input transparency check
    for _, row in df.iterrows():
        pid = row["program_id"]
        cfg_file = DATASETS_DIR / "stage1_smoke" / "configs" / f"{pid}.json"
        assert cfg_file.exists(), f"Missing config file: {cfg_file}"
        with open(cfg_file, "r", encoding="utf-8") as f:
            cfg = json.load(f)
        assert "input_vars" in cfg and "high_vars" in cfg and "low_vars" in cfg
        assert len(cfg["input_vars"]) == len(cfg["high_vars"]) + len(cfg["low_vars"])

    # Zero leakage invariants
    p1 = df[df["program_id"] == "P000001"].iloc[0]
    p12 = df[df["program_id"] == "P000012"].iloc[0]
    assert p1["actual_mqil_leakage"] == 0, "P000001 must have 0 leakage"
    assert p12["actual_mqil_leakage"] == 0, "P000012 must have 0 leakage"

    # Leaking invariants
    leaking = df[~df["program_id"].isin(["P000001", "P000012"])]
    assert (leaking["actual_mqil_leakage"] > 0).all(), "Leaking programs must produce #leak > 0"

def test_stage2_pipeline_invariants():
    s2_csv = DATASETS_DIR / "stage2_pipeline" / "dataset.csv"
    assert s2_csv.exists(), f"Missing Stage 2 Pipeline CSV: {s2_csv}"

    df = pd.read_csv(s2_csv)
    assert len(df) == 50, f"Expected 50 programs, found {len(df)}"
    assert df.isna().sum().sum() == 0, "Stage 2 contains NaN values"
    assert df["sha256"].nunique() == 50, "Stage 2 contains duplicate programs"

    # Zero leakage checks
    zero_df = df[df["family_id"] == "zero_leakage"]
    assert (zero_df["actual_mqil_leakage"] == 0).all(), "All zero_leakage programs must have #leak == 0"

    # Leaking checks
    leaking_df = df[df["family_id"].isin(["arithmetic", "array_lookup", "bitwise", "direct_leakage", "implicit_flow", "mixed_control_data", "nested_branches", "partial_leakage"])]
    assert (leaking_df["actual_mqil_leakage"] > 0).all(), "Leaking families must produce #leak > 0"

    # Splits check
    splits_file = DATASETS_DIR / "stage2_pipeline" / "splits" / "grouped_splits.json"
    assert splits_file.exists(), f"Missing splits file: {splits_file}"
    with open(splits_file, "r", encoding="utf-8") as f:
        splits = json.load(f)
    assert len(splits["train_indices"]) == 35
    assert len(splits["val_indices"]) == 5
    assert len(splits["test_indices"]) == 10

def test_deliverables_exist():
    # Reports
    assert (RESULTS_DIR / "reports" / "STAGE1_REPORT.md").exists()
    assert (RESULTS_DIR / "reports" / "STAGE2_REPORT.md").exists()
    assert (RESULTS_DIR / "reports" / "ABLATION_SUMMARY.md").exists()
    assert (RESULTS_DIR / "reports" / "EXPLAINABILITY_REPORT.md").exists()
    
    # Figures
    assert (RESULTS_DIR / "figures" / "feature_importance.png").exists()
    assert (RESULTS_DIR / "figures" / "actual_vs_predicted.png").exists()
    assert (RESULTS_DIR / "figures" / "residuals_distribution.png").exists()

    # Trained model
    assert (RESULTS_DIR / "models" / "best_model.pkl").exists()

from src.core.cbmc_runner import parse_cbmc_output

def test_cbmc_parser_successful_zero_leakage():
    """Test 1: Successful zero-leakage result."""
    cbmc_output = """
[main.assertion.1] line 75 assertion glob_zero_1_1 == glob_zero_1_2: SUCCESS
[main.assertion.2] line 76 assertion out_1 == out_2: SUCCESS
[zero_kernel_1.overflow.1] line 55 arithmetic overflow on signed * in p * 2: SUCCESS
[zero_kernel_1.overflow.2] line 55 arithmetic overflow on signed + in p * 2 + 1: SUCCESS
[zero_kernel_1_2.assertion.1] line 49 assertion dead_1 == dead_2: SUCCESS

** 0 of 5 failed (1 iterations)
VERIFICATION SUCCESSFUL
"""
    res = parse_cbmc_output(cbmc_output, exit_code=0, program_name="P000001_miter.c")
    assert res["actual_mqil_assertions_total"] == 3
    assert res["actual_mqil_leakage"] == 0
    assert res["leakage_result"] == "SUCCESSFUL"
    assert res["safety_result"] == "SUCCESSFUL"
    assert res["overall_cbmc_status"] == "SUCCESSFUL"
    assert res["dataset_status"] == "VALID"

def test_cbmc_parser_leakage_detected():
    """Test 2: Leakage but no safety failure."""
    cbmc_output = """
[main.assertion.1] line 41 assertion glob_direct_2_1 == glob_direct_2_2: FAILURE
[main.assertion.2] line 42 assertion res_1 == res_2: SUCCESS
[direct_kernel_2_2.assertion.1] line 25 assertion dead_1 == dead_2: SUCCESS

** 1 of 3 failed (2 iterations)
VERIFICATION FAILED
"""
    res = parse_cbmc_output(cbmc_output, exit_code=10, program_name="P000002_miter.c")
    assert res["actual_mqil_leakage"] >= 1
    assert res["leakage_result"] == "FAILED"
    assert res["safety_result"] == "SUCCESSFUL"
    assert res["overall_cbmc_status"] == "FAILED"
    assert res["dataset_status"] == "LEAKAGE_DETECTED"

def test_cbmc_parser_safety_failure():
    """Test 3: Safety failure but no leakage."""
    cbmc_output = """
[main.assertion.1] line 72 assertion glob_zero_1_1 == glob_zero_1_2: SUCCESS
[main.assertion.2] line 73 assertion out_1 == out_2: SUCCESS
[zero_kernel_1.overflow.1] line 54 arithmetic overflow on signed * in p * 2: FAILURE
[zero_kernel_1.overflow.2] line 54 arithmetic overflow on signed + in p * 2 + 1: SUCCESS
[zero_kernel_1_2.assertion.1] line 48 assertion dead_1 == dead_2: SUCCESS

** 1 of 5 failed (2 iterations)
VERIFICATION FAILED
"""
    res = parse_cbmc_output(cbmc_output, exit_code=10, program_name="P000001_miter.c")
    assert res["actual_mqil_leakage"] == 0
    assert res["leakage_result"] == "SUCCESSFUL"
    assert res["safety_result"] == "FAILED"
    assert res["overall_cbmc_status"] == "FAILED"
    assert res["dataset_status"] == "INVALID_UNSAFE_PROGRAM"

def test_cbmc_parser_incomplete_unwinding():
    """Test 4: Incomplete unwinding."""
    cbmc_output = """
[main.assertion.1] line 75 assertion out_1 == out_2: SUCCESS
[main.assertion.2] line 76 assertion glob_1 == glob_2: SUCCESS
[main.unwind.0] line 30 unwinding assertion loop 0: FAILURE

** 1 of 3 failed (2 iterations)
VERIFICATION FAILED
"""
    res = parse_cbmc_output(cbmc_output, exit_code=10, program_name="loop_miter.c")
    assert res["actual_mqil_leakage"] is None
    assert len(res["unwinding_failures"]) > 0
    assert res["dataset_status"] == "INCOMPLETE_UNWINDING"

def test_cbmc_parser_assertion_with_colon():
    """Test 5: Assertion expression containing a colon."""
    cbmc_output = """
[main.assertion.1] line 10 assertion (x > 0 ? y : z) == v2: FAILURE

** 1 of 1 failed (2 iterations)
VERIFICATION FAILED
"""
    res = parse_cbmc_output(cbmc_output, exit_code=10, program_name="test_colon.c")
    assert res["actual_mqil_assertions_total"] == 1
    assert res["actual_mqil_leakage"] == 1
    assert len(res["failed_details"]) == 1
    assert res["failed_details"][0]["property"] == "main.assertion.1"
    assert res["failed_details"][0]["assertion"] == "(x > 0 ? y : z) == v2"
    assert res["dataset_status"] == "LEAKAGE_DETECTED"
import tempfile
from src.core.feature_extractor import extract_group_b_features
from src.core.transpiler import generate_miter_program

def test_feature_extractor_high_vars_validation():
    """Test A: high_vars validation."""
    with tempfile.TemporaryDirectory() as td:
        tpath = Path(td)
        src_file = tpath / "src.c"
        src_file.write_text("int main() { return 0; }", encoding="utf-8")
        cfg_file = tpath / "cfg.json"
        cfg_file.write_text(json.dumps({
            "input_vars": ["pub"],
            "high_vars": ["secret"],
            "low_vars": ["pub"]
        }), encoding="utf-8")
        miter_file = tpath / "miter.c"
        miter_file.write_text("#include <assert.h>\nint main() { return 0; }", encoding="utf-8")
        with pytest.raises(ValueError, match="high_vars must be a subset of input_vars"):
            extract_group_b_features(src_file, cfg_file, miter_file)

def test_feature_extractor_tainted_function_return():
    """Test B: tainted function return causes explicit flow."""
    with tempfile.TemporaryDirectory() as td:
        tpath = Path(td)
        src_file = tpath / "src.c"
        src_file.write_text("""
int secret_global;
int get_secret() {
    return secret_global;
}
int main() {
    int out;
    out = get_secret();
    return 0;
}
""", encoding="utf-8")
        cfg_file = tpath / "cfg.json"
        cfg_file.write_text(json.dumps({
            "input_vars": ["secret_global"],
            "high_vars": ["secret_global"],
            "low_vars": []
        }), encoding="utf-8")
        miter_file = tpath / "miter.c"
        generate_miter_program(src_file, cfg_file, miter_file)
        feats = extract_group_b_features(src_file, cfg_file, miter_file)
        assert feats["num_explicit_flows"] >= 1

def test_feature_extractor_seed_self_update_not_explicit_flow():
    """Test C: seed self-update is not an explicit flow."""
    with tempfile.TemporaryDirectory() as td:
        tpath = Path(td)
        src_file = tpath / "src.c"
        src_file.write_text("int main() { return 0; }", encoding="utf-8")
        cfg_file = tpath / "cfg.json"
        cfg_file.write_text(json.dumps({
            "input_vars": ["high_sec"],
            "high_vars": ["high_sec"],
            "low_vars": []
        }), encoding="utf-8")
        miter_file = tpath / "miter.c"
        miter_file.write_text("""
#include <assert.h>
int high_sec_1;
int high_sec_2;
void main() {
    high_sec_1 = high_sec_1 + 1;
    assert(high_sec_1 == high_sec_2);
}
""", encoding="utf-8")
        feats = extract_group_b_features(src_file, cfg_file, miter_file)
        assert feats["num_explicit_flows"] == 0

def test_feature_extractor_tainted_global_counted():
    """Test D: tainted global is counted."""
    with tempfile.TemporaryDirectory() as td:
        tpath = Path(td)
        src_file = tpath / "src.c"
        src_file.write_text("""
int high_sec;
int global_out;
int main() {
    global_out = high_sec;
    return 0;
}
""", encoding="utf-8")
        cfg_file = tpath / "cfg.json"
        cfg_file.write_text(json.dumps({
            "input_vars": ["high_sec"],
            "high_vars": ["high_sec"],
            "low_vars": []
        }), encoding="utf-8")
        miter_file = tpath / "miter.c"
        generate_miter_program(src_file, cfg_file, miter_file)
        feats = extract_group_b_features(src_file, cfg_file, miter_file)
        assert feats["num_tainted_globals"] == 1

def test_feature_extractor_secret_global_not_counted():
    """Test E: secret global itself is not counted in num_tainted_globals."""
    with tempfile.TemporaryDirectory() as td:
        tpath = Path(td)
        src_file = tpath / "src.c"
        src_file.write_text("""
int high_sec;
int main() {
    high_sec = high_sec + 1;
    return 0;
}
""", encoding="utf-8")
        cfg_file = tpath / "cfg.json"
        cfg_file.write_text(json.dumps({
            "input_vars": ["high_sec"],
            "high_vars": ["high_sec"],
            "low_vars": []
        }), encoding="utf-8")
        miter_file = tpath / "miter.c"
        generate_miter_program(src_file, cfg_file, miter_file)
        feats = extract_group_b_features(src_file, cfg_file, miter_file)
        assert feats["num_tainted_globals"] == 0

def test_feature_extractor_unchanged_features_regression():
    """Test F: regression checks for unchanged features."""
    with tempfile.TemporaryDirectory() as td:
        tpath = Path(td)
        src_file = tpath / "src.c"
        src_file.write_text("int main() { return 0; }", encoding="utf-8")
        cfg_file = tpath / "cfg.json"
        cfg_file.write_text(json.dumps({
            "input_vars": ["s"],
            "high_vars": ["s"],
            "low_vars": []
        }), encoding="utf-8")
        miter_file = tpath / "miter.c"
        miter_file.write_text("""
#include <assert.h>
typedef void FILE;
int printf(const char *format, ...);
int puts(const char *str);
int putchar(int c);
int fprintf(FILE *stream, const char *format, ...);
int sprintf(char *str, const char *format, ...);
int snprintf(char *str, unsigned int size, const char *format, ...);
int s_1;
int s_2;
void main() {
    int x_1 = 0;
    int x_2 = 0;
    char buf[32];
    FILE *fp = 0;

    // 1. culprit blocks: if, while, do-while, for, switch (5 blocks)
    if (s_1 > 0) { x_1 = 1; }
    while (s_1 < 10) { x_1 = 2; break; }
    do { x_1 = 3; break; } while (s_1 < 5);
    for (int i = 0; s_1 < 20; i++) { break; }
    switch (s_1) { case 0: break; }

    // Ternary operator should NOT be counted as culprit block
    int y_1 = (s_1 > 0) ? 10 : 20;

    // 2. Secret dependent prints: 6 calls with tainted argument, 1 untainted puts
    printf("val: %d", s_1);
    puts("clean string");
    putchar(s_1);
    fprintf(fp, "err: %d", s_1);
    sprintf(buf, "%d", s_1);
    snprintf(buf, 32, "%d", s_1);

    // 3. Secret bitops: binary (&, |, ^, <<, >>) and compound (&=, |=, ^=, <<=, >>=)
    int b1 = s_1 & 1;
    int b2 = s_1 | 2;
    int b3 = s_1 ^ 3;
    int b4 = s_1 << 1;
    int b5 = s_1 >> 1;
    x_1 &= s_1;
    x_1 |= s_1;
    x_1 ^= s_1;
    x_1 <<= 1;
    x_1 >>= 1;

    // 4. Assertions: 2 assert calls
    assert(x_1 == x_2);
    assert(y_1 == y_1);
}
""", encoding="utf-8")
        feats = extract_group_b_features(src_file, cfg_file, miter_file)
        assert feats["num_culprit_blocks"] == 5, f"Expected 5 culprit blocks, got {feats['num_culprit_blocks']}"
        assert feats["num_assertions"] == 2, f"Expected 2 assertions, got {feats['num_assertions']}"
        assert feats["num_secret_dependent_prints"] == 5, f"Expected 5 secret prints, got {feats['num_secret_dependent_prints']}"
        assert feats["num_secret_bitops"] == 10, f"Expected 10 secret bitops, got {feats['num_secret_bitops']}"

if __name__ == "__main__":
    test_stage1_dataset_invariants()
    test_stage2_pipeline_invariants()
    test_deliverables_exist()
    test_cbmc_parser_successful_zero_leakage()
    test_cbmc_parser_leakage_detected()
    test_cbmc_parser_safety_failure()
    test_cbmc_parser_incomplete_unwinding()
    test_cbmc_parser_assertion_with_colon()
    test_feature_extractor_high_vars_validation()
    test_feature_extractor_tainted_function_return()
    test_feature_extractor_seed_self_update_not_explicit_flow()
    test_feature_extractor_tainted_global_counted()
    test_feature_extractor_secret_global_not_counted()
    test_feature_extractor_unchanged_features_regression()
    print("ALL TESTS PASSED SUCCESSFULLY.")



