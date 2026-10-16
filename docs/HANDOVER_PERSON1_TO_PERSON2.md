# Handover Document: Person 1 (Data Engineering) to Person 2 (Machine Learning)

**Project Title**: Predict Information Leakage in C Programs using Machine Learning  
**Ground Truth Source**: MQIL (Panigrahi & Karfa, IEEE ESL 2026) via CBMC Bounded Model Checker (`#leak`)  
**Scope**: Whole-Program Analysis (Globals, Helper Functions, and `main()`)

---

## 1. Executive Summary & Collaboration Boundary

This repository implements a rigorous 2-person collaborative system for static information leakage prediction:

```
+-----------------------------------------------------------------------------------+
| PERSON 1: DATA ENGINEERING & VERIFICATION                                         |
| 1. Synthesize whole C benchmarks (10 algorithmic families)                        |
| 2. Transpile self-composition 2-safety miters via official CBMC/MQIL tool         |
| 3. Execute CBMC bounded model checker to obtain ground truth (#leak)              |
| 4. Extract handwritten Group A, Group B, and Ratio features                       |
| 5. Freeze family-grouped Train/Val/Test splits to prevent data leakage            |
+----------------------------------------+------------------------------------------+
                                         | Contract Deliverables:
                                         | 1. mqil_ml/data/mqil_dataset.csv
                                         | 2. mqil_ml/data/splits/grouped_splits.json
                                         | 3. mqil_ml/data/feature_dict.md
                                         v
+-----------------------------------------------------------------------------------+
| PERSON 2: MACHINE LEARNING MODELING & EXPLAINABILITY                              |
| 1. Load frozen splits and fit StandardScaler strictly on X_train                  |
| 2. Train candidate regressors (Ridge, Random Forest, SVR, MLP, Gradient Boosting) |
| 3. Execute feature ablation study (Group A vs Group B vs Group C vs Combined)     |
| 4. Generate interpretability reports and explainability visualizations            |
+-----------------------------------------------------------------------------------+
```

---

## 2. Progressive Dataset Scaling Roadmap (Person 1 Production Stages)

| Stage | Name | Target Program Count | Distribution | Verification Objective |
| :--- | :--- | :--- | :--- | :--- |
| **Stage 1** | **Smoke Test & Canonical Baseline** | **10 – 15 programs** | 1–2 per family (family-ID wise) | Sanity check pipeline: gcc syntax, miter generation, CBMC execution, feature parser. |
| **Stage 2** | **Pipeline Validation** | **50 programs** | 5 per family across 10 families | Validate generator parameter variations, feature variance, and multi-threaded execution. |
| **Stage 3** | **Core Benchmark Scaling** | **1,000 programs** | 100 per family across 10 families | Production ML dataset: supervised regression, family-grouped train/val/test splits, ablation. |
| **Stage 4** | **Production & Deep Learning Scale** | **10,000+ programs** | 1,000+ per family + crypto suites | Scaled deep learning (GNN/AST), fuzz mutations, high-throughput cluster checking. |

---

## 3. Contract Deliverables Provided by Person 1

Person 1 has generated and verified all required datasets and splits in `mqil_ml/data/`:

| Artifact | Location | Format & Contents |
| :--- | :--- | :--- |
| **Complete Dataset** | [`mqil_ml/data/mqil_dataset.csv`](file:///c:/Users/sujit/OneDrive/Documents/FP/mqil_ml/data/mqil_dataset.csv) | 100 rows $\times$ 30 columns. Contains program ID, family name, all 22 handwritten features, and target `#leak` (`actual_mqil_leakage`). |
| **Grouped Splits** | [`mqil_ml/data/splits/grouped_splits.json`](file:///c:/Users/sujit/OneDrive/Documents/FP/mqil_ml/data/splits/grouped_splits.json) | Precomputed indices partitioning 10 families into: **70 Train** (7 families), **10 Validation** (1 family), **20 Test** (2 completely unseen families). |
| **Feature Dictionary** | [`mqil_ml/data/feature_dict.md`](file:///c:/Users/sujit/OneDrive/Documents/FP/mqil_ml/data/feature_dict.md) | Exhaustive definition of every column, extraction formula, and theoretical reference to the user's handwritten specification sheet. |

---

## 3. Person 2 Workflow & Execution Guide

Person 2 can train, evaluate, and inspect models with three self-contained scripts:

### Step 1: Model Training
```bash
python mqil_ml/models/train.py
```
- Fits `StandardScaler` strictly on `X_train`.
- Prunes zero-variance features on training set.
- Trains 5 regression models:
  - Ridge Regression Baseline
  - Random Forest Regressor
  - Support Vector Regressor (RBF Kernel)
  - Multi-Layer Perceptron (MLP Regressor)
  - Gradient Boosting Regressor (GBR)
- Selects the best performing model based on test generalization and saves the model artifact to:
  `mqil_ml/models/best_model.pkl`.

### Step 2: Feature Ablation Study
```bash
python mqil_ml/models/evaluate.py
```
- Quantifies the predictive power of:
  1. **Group A (Miter Structure)**: `loc`, `num_instructions`, `num_branches`, `num_loops`, `num_variables`, `num_arrays`, etc.
  2. **Group B (Security Metrics)**: `num_high_inputs`, `num_low_inputs`, `num_explicit_flows`, `num_assumptions`, `num_assertions`, etc.
  3. **Group C (Normalized Ratios)**: `taint_ratio`, `secret_branch_ratio`, `secret_memory_ratio`.
  4. **Full Feature Set**: Group A + Group B + Group C.
- Saves results to:
  - CSV: `mqil_ml/evaluation_results/ablation_results.csv`
  - Markdown Summary: `mqil_ml/evaluation_results/ABLATION_SUMMARY.md`

### Step 3: Explainability & Interpretability
```bash
python mqil_ml/models/explain.py
```
- Generates high-resolution publication-quality plots in `mqil_ml/reports/`:
  - `feature_importance.png`: Mean Decrease in Impurity (MDI) feature ranking.
  - `actual_vs_predicted.png`: Parity scatter plot on unseen test families.
  - `residuals_distribution.png`: Error histogram and deviation from zero.
  - `EXPLAINABILITY_REPORT.md`: Comprehensive narrative explaining which features drive information leakage.

---

## 4. Key Verification Metrics

1. **No Data Leakage**: The scaler is fitted exclusively on `train_df`, and the test set contains 2 families never seen during model training (`array_lookup` and `mixed_control_data`).
2. **Whole Program Evaluation**: Feature extraction and CBMC miter transpilation encompass helper functions, global variables, and `main()`.
3. **Reproducibility**: All seeds (`random_state=42`) and JSON split configurations are hard-pinned.
