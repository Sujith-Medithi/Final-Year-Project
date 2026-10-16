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

WORKSPACE = Path(__file__).resolve().parent.parent
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

if __name__ == "__main__":
    test_stage1_dataset_invariants()
    test_stage2_pipeline_invariants()
    test_deliverables_exist()
    print("ALL TESTS PASSED SUCCESSFULLY.")
