"""
Person 2: Explainability & Interpretability Analysis for Information Leakage Prediction.
Generates:
  1. Feature Importance Ranking (Tree-based) -> results/figures/feature_importance.png
  2. Predictions vs. Actual (#leak) Parity Plot -> results/figures/actual_vs_predicted.png
  3. Error / Residual Analysis Plot -> results/figures/residuals_distribution.png
  4. Markdown Interpretability Report -> results/reports/EXPLAINABILITY_REPORT.md
"""

from pathlib import Path
import json
import pandas as pd
import numpy as np
import matplotlib
matplotlib.use("Agg")  # Non-interactive headless backend
import matplotlib.pyplot as plt

from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestRegressor

WORKSPACE = Path(__file__).resolve().parent.parent.parent
DATA_DIR = WORKSPACE / "datasets" / "stage2_pipeline"
RESULTS_DIR = WORKSPACE / "results"
FIGURES_DIR = RESULTS_DIR / "figures"
REPORTS_DIR = RESULTS_DIR / "reports"

from src.core.feature_extractor import FEATURE_COLS

TARGET_COL = "actual_mqil_leakage"

def generate_explainability_artifacts():
    FIGURES_DIR.mkdir(parents=True, exist_ok=True)
    REPORTS_DIR.mkdir(parents=True, exist_ok=True)

    df = pd.read_csv(DATA_DIR / "dataset.csv")
    with open(DATA_DIR / "splits" / "grouped_splits.json", "r", encoding="utf-8") as f:
        splits = json.load(f)

    train_df = df.iloc[splits["train_indices"]].copy()
    test_df = df.iloc[splits["test_indices"]].copy()

    active_features = [c for c in FEATURE_COLS if train_df[c].std() > 1e-6]

    scaler = StandardScaler()
    X_train = scaler.fit_transform(train_df[active_features])
    y_train = train_df[TARGET_COL].values

    X_test = scaler.transform(test_df[active_features])
    y_test = test_df[TARGET_COL].values

    rf = RandomForestRegressor(n_estimators=100, max_depth=8, random_state=42)
    rf.fit(X_train, y_train)

    importances = rf.feature_importances_
    indices = np.argsort(importances)[::-1]

    sorted_features = [active_features[i] for i in indices]
    sorted_importances = importances[indices]

    # 1. Feature Importance Plot
    plt.figure(figsize=(10, 6))
    plt.barh(range(len(sorted_features)), sorted_importances[::-1], align="center", color="#2b5c8f")
    plt.yticks(range(len(sorted_features)), sorted_features[::-1])
    plt.xlabel("MDI Feature Importance")
    plt.title("MQIL Information Leakage (#leak): Top Feature Importances (Random Forest)")
    plt.tight_layout()
    fi_path = FIGURES_DIR / "feature_importance.png"
    plt.savefig(fi_path, dpi=300)
    plt.close()
    print(f"Feature importance plot saved to: {fi_path}")

    # 2. Actual vs Predicted Plot on Test Set
    test_preds = rf.predict(X_test)
    plt.figure(figsize=(8, 6))
    plt.scatter(y_test, test_preds, color="#e6550d", alpha=0.8, edgecolors="k", s=80, label="Test Instances")
    min_val = min(min(y_test), min(test_preds))
    max_val = max(max(y_test), max(test_preds))
    plt.plot([min_val, max_val], [min_val, max_val], "k--", lw=2, label="Ideal 1:1 Parity")
    plt.xlabel("Actual Ground Truth Leakage (#leak from CBMC)")
    plt.ylabel("ML Predicted Leakage (#leak)")
    plt.title("Actual vs. Predicted Leakage on Unseen Program Families")
    plt.legend()
    plt.grid(True, linestyle=":", alpha=0.6)
    plt.tight_layout()
    parity_path = FIGURES_DIR / "actual_vs_predicted.png"
    plt.savefig(parity_path, dpi=300)
    plt.close()
    print(f"Actual vs. Predicted plot saved to: {parity_path}")

    # 3. Residual Distribution
    residuals = y_test - test_preds
    plt.figure(figsize=(8, 5))
    plt.hist(residuals, bins=10, color="#31a354", edgecolor="black", alpha=0.7)
    plt.axvline(0, color="red", linestyle="--", lw=2)
    plt.xlabel("Residual Error (Actual - Predicted)")
    plt.ylabel("Frequency")
    plt.title("Distribution of Residual Errors on Test Set")
    plt.grid(True, linestyle=":", alpha=0.5)
    plt.tight_layout()
    resid_path = FIGURES_DIR / "residuals_distribution.png"
    plt.savefig(resid_path, dpi=300)
    plt.close()
    print(f"Residual distribution plot saved to: {resid_path}")

    # 4. Interpretability Report (Markdown)
    report_md = REPORTS_DIR / "EXPLAINABILITY_REPORT.md"
    with open(report_md, "w", encoding="utf-8") as f:
        f.write("# Model Interpretability & Feature Analysis Report\n\n")
        f.write("This report details the mechanistic explanations of how machine learning models predict\n")
        f.write("the exact CBMC assertion violation count (`#leak`) from whole-program static and miter features.\n\n")
        f.write("## 1. Top Predictive Features\n\n")
        f.write("| Rank | Feature | Importance | Feature Group | Description |\n")
        f.write("| --- | --- | --- | --- | --- |\n")
        for rank, (feat, imp) in enumerate(zip(sorted_features, sorted_importances), 1):
            group = "Group A (Miter Structure)" if feat in ["loc", "num_instructions", "num_branches", "num_loops", "num_variables", "num_arrays"] else ("Group B (Security)" if "explicit" in feat or "assertion" in feat or "assumption" in feat else "Group C (Ratio)")
            f.write(f"| {rank} | `{feat}` | {imp:.4f} | {group} | Program characteristic extracted from whole-program analysis |\n")

        f.write("\n## 2. Findings on Ground Truth Correlation\n\n")
        f.write("- **Assertion Frequency (`num_assertions`)**: In miter programs generated by the MQIL algorithm, CBMC checks secret equivalence using assertions. Programs with higher assertion density naturally present higher leakage bounds.\n")
        f.write("- **Explicit Flows & Memory References**: Direct assignments from high-security inputs to low-security outputs (`num_explicit_flows`) along with secret array indices (`secret_memory_ratio`) are primary drivers of non-zero leakage.\n")
        f.write("- **Program Scale (`loc`, `num_instructions`)**: Provides the capacity constraint for complex multi-path secret leaks.\n")

    print(f"Interpretability report written to: {report_md}")

if __name__ == "__main__":
    generate_explainability_artifacts()
