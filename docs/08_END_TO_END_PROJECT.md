# Phase 8 --- Complete End-to-End MQIL ML Architecture & Collaboration Guide
**Joint System Architecture**: Person 1 & Person 2 Collaboration

---

## 1. Research Objective

> **Predict the quantitative information leakage (`#leak`) of a C source program using supervised machine learning regression, eliminating the need for formal model checkers or compilers during inference.**

---

## 2. End-to-End Architecture

```text
                               PERSON 1: DATA ENGINEERING
                  ┌──────────────────────────────────────────────────┐
                  │ 1. Whole-Program C Benchmarks + input_args.json │
                  │                           │                      │
                  │                           ▼                      │
                  │ 2. MQIL Miter Transpiler (cbmc-main/src/main.py) │
                  │                           │                      │
                  │              ┌────────────┴────────────┐         │
                  │              ▼                         ▼         │
                  │     CBMC Runner               Feature Extractor  │
                  │     (cbmc --unwind 5)         • Group A (Miter)  │
                  │     Target: #leak             • Group B (Security│
                  │              │                • 3 Ratios         │
                  │              └────────────┬────────────┘         │
                  │                           ▼                      │
                  │ 3. Assemble Frozen Dataset (mqil_dataset.csv)    │
                  │ 4. Precompute Leak-Free Family-Grouped Splits    │
                  └───────────────────────────┬──────────────────────┘
                                              │
                                   [ HANDOVER CHECKPOINT ]
                                              │
                                              ▼
                                 PERSON 2: ML & EVALUATION
                  ┌──────────────────────────────────────────────────┐
                  │ 5. Feature Scaling (Fit strictly on X_train)     │
                  │ 6. Train Regressors (RF, SVR, MLP, XGBoost)      │
                  │ 7. Out-of-Distribution Evaluation & Ablation     │
                  │ 8. Explainability via SHAP (Feature Attribution) │
                  └──────────────────────────────────────────────────┘
```

---

## 3. Project Directory Layout

```text
FP/
├── docs/                    # All specifications, documentation, and research papers
├── tools/                   # External formal verification engines (cbmc_mqil)
├── src/                     # Modular source code
│   ├── core/                # Core engines (transpiler.py, cbmc_runner.py, feature_extractor.py)
│   ├── generator/           # Benchmark synthesis (program_templates.py, synthesizer.py)
│   ├── models/              # ML training, ablation, and explainability (train, evaluate, explain)
│   └── pipeline.py          # Unified pipeline orchestrator
├── datasets/                # Staged datasets
│   ├── stage1_smoke/        # 12 canonical baseline programs, miters, and CSV
│   └── stage2_pipeline/     # 50 validated programs, miters, grouped splits, and CSV
├── results/                 # Unified deliverables
│   ├── reports/             # STAGE1_REPORT, STAGE2_REPORT, ABLATION_SUMMARY, EXPLAINABILITY_REPORT
│   ├── figures/             # Feature importance, parity plots, residual histograms
│   └── models/              # Serialized best_model.pkl
├── tests/                   # Automated smoke & invariant test suite
├── archive/                 # Archived legacy files
├── main.py                  # Master CLI entrypoint
└── requirements.txt         # Dependencies
```

---

## 4. End-to-End Execution Sequence

### For Person 1 (Data Engineering):
```bash
# Runs Stage 1 canonical baseline & smoke test (12 programs)
python main.py --stage 1

# Runs Stage 2 pipeline validation (50 programs)
python main.py --stage 2
```

### For Person 2 (Machine Learning):
```bash
# Trains models, runs feature ablation, and generates explainability figures
python main.py --ml
```
