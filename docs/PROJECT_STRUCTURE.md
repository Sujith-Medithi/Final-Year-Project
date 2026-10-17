# System Architecture & Clean Project Directory Structure

**Project Title**: Predict Information Leakage in C Programs using Machine Learning  
**Core Framework**: MQIL (Model Checking-based Quantification of Information Leakage, *Panigrahi & Karfa, IEEE ESL 2026*)  
**Architecture Standard**: Modular Separation of Concerns (SoC), DRY (Don't Repeat Yourself), Single Source of Truth (SSOT).

---

## 1. Master Directory Tree

```text
FP/
├── docs/                                 # All project documentation, guides, and reference papers
│   ├── 01_DATASET_GENERATION.md          # 4-stage progressive dataset generation specification
│   ├── 02_SOURCE_SECURITY_FEATURE_EXTRACTION.md # Group A, Group B, and Ratio feature rules
│   ├── 03_GROUND_TRUTH_QIF.md            # MQIL #leak vs Shannon mutual information analysis
│   ├── 04_PREPROCESSING_AND_SPLITTING.md # Family-grouped leak-free train/val/test splitting
│   ├── 05_REGRESSION_MODELS.md           # Model specifications (Ridge, RF, SVR, MLP, GBR)
│   ├── 06_EVALUATION.md                  # Evaluation metrics (MAE, RMSE, R²) and ablation study
│   ├── 07_INTERPRETABILITY_AND_EXPERIMENTS.md # Explainability and SHAP attribution design
│   ├── 08_END_TO_END_PROJECT.md          # Full system architecture and workflow
│   ├── HANDOVER_PERSON1_TO_PERSON2.md    # Boundary contract between Person 1 and Person 2
│   ├── FEATURE_DICTIONARY.md             # Exhaustive column definitions of all 27 features
│   ├── PROJECT_STRUCTURE.md              # [This Document] Directory layout and design rationale
│   └── MQIL_Research_Paper.pdf           # Original IEEE ESL 2026 research paper
│
├── tools/                                # External tools & formal verification engines
│   └── cbmc_mqil/                        # Official MQIL self-composition transpiler
│       ├── src/                          # Transpiler engine (main.py, modules/ast.py, utils.py)
│       ├── Benchmarks/                   # Real-world cryptographic algorithms (AES, DES, RSA, SHA)
│       └── examples/                     # Verification test files
│
├── src/                                  # Pure, concise, non-repetitive Python source code
│   ├── core/                             # Core verified analysis engines (reusable across all stages)
│   │   ├── __init__.py
│   │   ├── transpiler.py                 # Clean wrapper invoking tools/cbmc_mqil/src/main.py
│   │   ├── cbmc_runner.py                # Formal verification runner (WSL / Native CBMC 6.6.0)
│   │   └── feature_extractor.py          # pycparser AST visitor (Group A, Group B, Ratios)
│   │
│   ├── generator/                        # Program generation engine (DRY, parameterized)
│   │   ├── __init__.py
│   │   ├── program_templates.py          # Consolidated canonical templates for 10 leakage families
│   │   └── synthesizer.py                # Parameterized benchmark synthesizer (Stage 1 & Scaled)
│   │
│   ├── models/                           # Supervised Machine Learning pipeline (Person 2)
│   │   ├── __init__.py
│   │   ├── train.py                      # Trains Ridge, RF, SVR, MLP, and Gradient Boosting
│   │   ├── evaluate.py                   # 4-tier feature ablation study (A vs B vs C vs Full)
│   │   └── explain.py                    # Feature importance, parity plots, residual histograms
│   │
│   └── pipeline.py                       # Unified pipeline orchestrator linking generator, CBMC, and ML
│
├── datasets/                             # Cleanly separated data stages (benchmarks, miters, CSVs)
│   ├── stage1_smoke/                     # Stage 1: 12 Canonical Baseline Programs
│   │   ├── programs/                     # P000001.c ... P000012.c
│   │   ├── configs/                      # P000001.json ... P000012.json (input_vars, high_vars, low_vars)
│   │   ├── miters/                       # P000001_miter.c ... P000012_miter.c
│   │   └── dataset.csv                   # Stage 1 tabular feature dataset (12 rows x 31 cols)
│   │
│   └── stage2_scaled/                    # Stage 2: Scaled 100-program ML benchmark dataset
│       ├── programs/                     # 10 family subfolders (100 C programs + configs)
│       ├── miters/                       # 100 dual-copy self-composition miter files
│       ├── splits/                       # Leak-free family-grouped splits (70 train, 10 val, 20 test)
│       └── dataset.csv                   # The 100-row ML dataset used for regression training
│
├── results/                              # Unified output directory for all generated deliverables
│   ├── reports/                          # Formatted analytical markdown summaries & CSVs
│   │   ├── STAGE1_REPORT.md              # Stage 1 verification report (all 12 programs checked)
│   │   ├── ABLATION_SUMMARY.md           # Comparative table: Structural vs Security features
│   │   ├── ABLATION_RESULTS.csv          # Raw evaluation metrics across models and feature subsets
│   │   └── EXPLAINABILITY_REPORT.md      # Feature importance rankings and security takeaways
│   │
│   ├── figures/                          # Publication-quality visualization plots (300 DPI PNGs)
│   │   ├── feature_importance.png        # MDI Feature importance bar chart
│   │   ├── actual_vs_predicted.png       # Test set parity scatter plot (Actual vs Predicted #leak)
│   │   └── residuals_distribution.png    # Residual error frequency histogram
│   │
│   └── models/                           # Trained model checkpoints & preprocessors
│       └── best_model.pkl                # Serialized model, scaler, and active feature list
│
├── tests/                                # Automated verification test suite
│   ├── __init__.py
│   └── test_smoke_pipeline.py            # Automated tests asserting 100% of pipeline invariants
│
├── archive/                              # Archived legacy files (isolated from active codebase)
│   └── legacy_chatgpt_archive/           # Legacy ChatGPT scripts (Shannon entropy toy models)
│
├── main.py                               # Master CLI entrypoint for all developer operations
└── requirements.txt                      # Hard-pinned Python environment dependencies
```

---

## 2. Directory Rationale & Design Conventions

### 1. `docs/` (Documentation & Reference)
* **Why it exists**: Previously, eight `.md` files and a reference PDF cluttered the root directory. Moving them into `docs/` keeps the root clean and provides a centralized knowledge base.
* **Contents**: The 8 comprehensive design phases, the Person 1 to Person 2 Handover contract, the feature dictionary, and the original IEEE ESL 2026 research paper.

### 2. `tools/` (External & Vendor Tools)
* **Why it exists**: The official MQIL repository was previously extracted as `cbmc-main/cbmc-main/` (awkward double-nesting).
* **Fix**: Flattened into `tools/cbmc_mqil/`. It contains the official pycparser-based AST transpiler that creates 2-safety self-composition miters, alongside official crypto benchmarks (AES, DES, RSA, SHA).

### 3. `src/` (Core Application Source Code)
* **Why it exists**: Houses all active, reusable Python code without repetitive copies:
  - `src/core/`: Contains the foundational verification engines:
    - `transpiler.py`: Calls `tools/cbmc_mqil/src/main.py`.
    - `cbmc_runner.py`: Executes CBMC (via native binary or Ubuntu WSL) with `--unwind 5` and parses `#leak` assertions.
    - `feature_extractor.py`: Uses `pycparser` AST visitors to extract Group A, Group B, and Ratio features without requiring compilation.
  - `src/generator/`: Consolidates benchmark templates into `program_templates.py` and `synthesizer.py`. Eliminates hundreds of lines of duplicate code.
  - `src/models/`: Encapsulates Person 2's ML workflow: `train.py` (model fitting), `evaluate.py` (ablation), and `explain.py` (visualizations).
  - `src/pipeline.py`: The single pipeline orchestrator tying together generation, verification, and machine learning.

### 4. `datasets/` (Data Staging)
* **Why it exists**: In the previous layout, miter files and benchmarks were mixed across multiple root-level folders (`mqil_ml/miter/`, `mqil_ml/stage1/miter/`, `mqil_ml/benchmarks/`).
* **Fix**: Cleanly partitioned into:
  - `stage1_smoke/`: The 12 canonical programs, their companion JSONs (explicitly listing `input_vars`, `high_vars`, and `low_vars`), their 12 miters, and `dataset.csv`.
  - `stage2_scaled/`: The 100 scaled benchmarks, 100 miters, family-grouped splits (`grouped_splits.json`), and the complete 100-row ML dataset.

### 5. `results/` (Artifacts & Deliverables)
* **Why it exists**: Keeps all generated outputs strictly separated from source code:
  - `results/reports/`: Formatted markdown summaries (`STAGE1_REPORT.md`, `ABLATION_SUMMARY.md`, `EXPLAINABILITY_REPORT.md`).
  - `results/figures/`: High-resolution plots (`feature_importance.png`, `actual_vs_predicted.png`, `residuals_distribution.png`).
  - `results/models/`: Serialized ML model checkpoint (`best_model.pkl`).

### 6. `tests/` (Automated Quality Assurance)
* **Why it exists**: Provides regression testing. `tests/test_smoke_pipeline.py` verifies all Stage 1 and Stage 2 data integrity, non-interference invariants (`#leak == 0` for zero-leakage programs), and deliverable files.

### 7. `main.py` (Root CLI Entrypoint)
* **Why it exists**: A single, standard interface for running any component of the project.

---

## 3. How Repetitive Code Was Eliminated (DRY Architecture)

1. **Consolidated Program Templates**:
   - *Before*: `stage1_definitions.py` and `synthesize_benchmarks.py` maintained separate, copy-pasted C string bodies for families like `zero_leakage`, `direct_leakage`, `implicit_flow`, etc.
   - *After*: Centralized in `src/generator/program_templates.py`, which is dynamically parameterized by `src/generator/synthesizer.py`.
2. **Unified Transpilation & Verification Logic**:
   - *Before*: `stage1/run_stage1.py` and `run_mqil_pipeline.py` duplicated the exact same subprocess calls to CBMC and `pycparser`.
   - *After*: `src/core/transpiler.py`, `src/core/cbmc_runner.py`, and `src/core/feature_extractor.py` act as the single source of truth used across all stages.
3. **Unified CLI**:
   - Replaced fragmented scripts (`run_stage1.py`, `run_mqil_pipeline.py`, `train.py`, `evaluate.py`, `explain.py`) with a centralized entrypoint: `main.py`.

---

## 4. Master Command Reference

| Action | Command | Output Deliverable |
| :--- | :--- | :--- |
| **Stage 1 Smoke Test** | `python main.py --stage 1` | `datasets/stage1_smoke/dataset.csv`, `results/reports/STAGE1_REPORT.md` |
| **Stage 2 Scaled Synthesis** | `python main.py --stage 2` | `datasets/stage2_scaled/dataset.csv`, `datasets/stage2_scaled/splits/` |
| **Train ML Models** | `python main.py --train` | `results/models/best_model.pkl` |
| **Feature Ablation Study** | `python main.py --evaluate` | `results/reports/ABLATION_SUMMARY.md`, `results/reports/ablation_results.csv` |
| **Explainability Analysis** | `python main.py --explain` | `results/figures/*.png`, `results/reports/EXPLAINABILITY_REPORT.md` |
| **Full Person 2 ML Pipeline** | `python main.py --ml` | Runs train, evaluate, and explain sequentially |
| **Complete End-to-End Run** | `python main.py --all` | Runs data synthesis, CBMC verification, and all ML models |
| **Automated Verification** | `python tests/test_smoke_pipeline.py` | Asserts all invariants and data consistency |
