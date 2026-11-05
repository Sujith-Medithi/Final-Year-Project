# Project Review & Architectural Summary: MQIL-Based Program Quantification & Machine Learning Pipeline

**Project Repository:** `https://github.com/Sujith-Medithi/Final-Year-Project.git`  
**Primary Research Foundation:** *"MQIL: Model Checking based Quantification of Information Leakage"*, Priyanka Panigrahi & Chandan Karfa, *IEEE Embedded Systems Letters*, 2026.  
**Role / Scope:** Person 1 — Data Engineering, Synthetic Benchmark Generation, 2-Safety Formal Miter Transpilation, CBMC Model Checking, and Static AST Feature Extraction.

---

## 1. Executive Summary & Objective

The objective of this project is to create an automated, verifiable machine-learning-ready data pipeline for quantifying information leakage in C programs. The pipeline:
1. Synthesizes complex C programs across diverse cryptographic and data-flow vulnerability families.
2. Formally verifies non-interference and quantifies precise information leakage using Bounded Model Checking (CBMC) on 2-safety self-composition miters.
3. Parses Abstract Syntax Trees (ASTs) using `pycparser` to extract a 28-feature representation of each program.
4. Generates comprehensive CSV datasets where machine learning models (Person 2 / Person 3) can predict formal verification outcomes (leakage presence and assertion failure counts) directly from static program features without paying the exponential runtime cost of SMT solving.

---

## 2. Benchmark Datasets Generated

The pipeline has produced several iterative generations of datasets, culminating in `random_4`:

| Dataset | Programs | Target LOC | High Inputs | Low Inputs | Total Inputs | Status & Purpose |
| :--- | :---: | :---: | :---: | :---: | :---: | :--- |
| **`stage1_smoke`** | 10 | 30 – 100 | 1 | 1 | 2 | Smoke testing and parser calibration. |
| **`random`** | 1,000 | 200 – 500 | 1 – 3 | 1 – 4 | 2 – 7 | Initial baseline generation. |
| **`random_2`** | 1,000 | 600 – 1,000 | 3 – 8 | 4 – 10 | 7 – 18 | Intermediate complexity scaling. |
| **`random_3`** | 1,000 | 1,200 – 1,800 | 8 – 15 | 8 – 15 | 16 – 30 | Pre-production dataset across 10 families. |
| **`random_4`** | **1,000** | **2,000 – 2,500** | **16 – 22** | **16 – 22** | **32 – 44** | **Flagship benchmark**: 100% CBMC verified, 0 nulls, 0 duplicate feature rows, 0 hash collisions. |
| **`benchmark_30_loc`** | 1 | 30 | 1 | 1 | 2 | Dedicated micro-benchmark for manual AST verification. |

### The 10 Vulnerability Families (100 Programs Each in `random_4`)
1. **`zero_leakage`**: Provably non-interferent dead / masked secret computations (`actual_mqil_leakage = 0`, formal status `VALID`).
2. **`direct_leakage`**: Direct assignment from secret inputs to observable sinks.
3. **`multi_step_explicit`**: Transitive taint flow propagation chains.
4. **`arithmetic_flow`**: Secret arithmetic transformations (`+`, `-`, `*`, `/`).
5. **`bitwise_flow`**: Secret bitwise manipulations (`^`, `&`, `|`, bit shifts).
6. **`implicit_flow`**: Secret-dependent control-flow branching.
7. **`nested_implicit_flow`**: Multi-level hierarchical nested conditional branching.
8. **`secret_dependent_loops`**: Secret-controlled loop bounds and iteration tallies.
9. **`secret_dependent_array`**: Secret-dependent indexing and LUT buffer lookups.
10. **`mixed_control_data`**: Hybrid control-flow and data-flow interactions.

---

## 3. Core Pipeline Components & Toolchain

The repository is organized around four core stages:

```
[Program Generator] ──> [Miter Transpiler] ──> [CBMC Verifier] ──> [AST Feature Extractor] ──> Master CSV
```

### Key Source Files:
- [`src/generator/random_program_generator_v4.py`](file:///c:/Users/sujit/OneDrive/Documents/FP/src/generator/random_program_generator_v4.py):
  High-scale benchmark generator. Synthesizes dynamic structs, unions, arrays, helper functions (14–26 per program), randomized pipeline stages (`ternary_chain_stage`, etc.), and controlled security kernels satisfying strict LOC and cardinality constraints.
- [`tools/cbmc_mqil/src/main.py`](file:///c:/Users/sujit/OneDrive/Documents/FP/tools/cbmc_mqil/src/main.py):
  Official MQIL AST-level 2-safety transpiler. Duplicates programs into twin executions $P_1(H_1, L, V_1, O_1)$ and $P_2(H_2, L, V_2, O_2)$, injects assumptions (`__CPROVER_assume(low_1 == low_2)`), and inserts assertions (`assert(v_1 == v_2)`).
- [`src/core/cbmc_runner.py`](file:///c:/Users/sujit/OneDrive/Documents/FP/src/core/cbmc_runner.py):
  Formal model checker harness. Executes CBMC under WSL Ubuntu with flags:
  `--unwind 5 --unwinding-assertions --no-standard-checks`
  Extracts SAT satisfiability, total assertions checked, and failed assertions (`actual_mqil_leakage`).
- [`src/core/feature_extractor.py`](file:///c:/Users/sujit/OneDrive/Documents/FP/src/core/feature_extractor.py):
  Static feature analyzer built on `pycparser`. Traverses ASTs to extract 28 structural and security features.

---

## 4. Key Engineering Challenges Solved & Big Steps Taken

During development and scaling to 2,000+ LOC programs with $>30$ inputs, four critical engineering hurdles were solved:

### Challenge 1: SAT Solver Bloat on Non-Linear Modulo Operations
- **Problem**: In `zero_leakage`, attempting to cancel secrets via modulo arithmetic (`sec % 1`) resulted in exponential SAT clause explosions, causing CBMC to hang or exceed 60-second timeouts.
- **Fix**: Replaced modulo with linear algebraic identity zeroing that SAT solvers resolve instantly:
  ```c
  (sec ^ sec) * 0;
  ((sec << 2) ^ (sec << 2)) * 0;
  (sec & 0) * 0;
  ```

### Challenge 2: Helper Function Twin-Call Explosion
- **Problem**: Calling 20 helper functions repeatedly inside main loops caused the MQIL miter generator to generate twin function declarations and multiple calls per iteration, inflating miter files to $>6,000$ lines and exhausting CBMC memory.
- **Fix**: Introduced `ternary_chain_stage` within main execution stages. Helper functions remain declared in the AST for structural diversity and parameter-binding analysis, but are called in controlled quantities.

### Challenge 3: Unwinding Assertion Bound Failures in Array Lookups
- **Problem**: In `secret_dependent_array`, lookup tables with `lut_size = 8` caused miter verification loops (`for (int i_0 = 0; i_0 < 8; i_0++) assert(...)`) to exceed `--unwind 5`, triggering `main.unwind.28: FAILURE` and yielding `None` leakage values.
- **Fix**: Constrained lookup table loops to `lut_size = 4`. All comparison loops complete within $\le 4$ iterations, completely satisfying `--unwind 5` and restoring 100% verification success across all 1,000 programs.

### Challenge 4: CSV Float/Int Parsing on Null Fallbacks
- **Problem**: Parsing empty string leakage values crashed CSV aggregators.
- **Fix**: Hardened parsing logic with `int(float(val))` and explicit fallback handling.

---

## 5. Architectural Comparison: Existing vs. Proposed

### The Problem Identified by the Professor
In the **Existing Architecture**, security features (Group B) were extracted by running static taint analysis on the **Miter AST (`_miter.c`)**.
Because the miter duplicates every variable into Trace 1 (`_1`) and Trace 2 (`_2`), the static analysis counted both copies, causing metrics like `num_information_leak`, `num_explicit_flows`, and `num_implicit_flows` to be inflated by $2\times$ to $3.5\times$. For example, `num_information_leak` could appear larger than `num_variables` because it counted `{acc_1, acc_2}`.

### The Research Paper Ground Truth
The MQIL research paper (*Panigrahi & Karfa, 2026*) establishes:
1. **The Miter is a Verification Tool**: The miter is created strictly as an input to CBMC. Table I in the paper explicitly shows that miter generation inflates code size ($2.95\times$ LOC, $3.51\times$ variables).
2. **Leaky Variables Belong to the Source**: The paper defines `#leak` as the number of variables in the **original source program $P$** that leak information.

---

### Side-by-Side Architectural Summary

| Dimension | Existing Architecture (Legacy Miter) | New Architecture (Finalized Source-Centric) |
| :--- | :--- | :--- |
| **Group A Features**<br>*(LOC, instructions, branches, loops, variables, arrays, structs, unions)* | Extracted from **Source C AST** (`.c`) | Extracted from **Source C AST** (`.c`) *(Unchanged)* |
| **Input Counts**<br>*(`num_high_inputs`, `num_low_inputs`)* | Read from `input_args.json` | Read from `input_args.json` *(Unchanged)* |
| **Group B Security Flows**<br>*(`num_explicit_flows`, `num_implicit_flows`)* | Extracted from **Miter AST** as statement occurrence counts (duplicated across dual traces) | Extracted from **Source C AST** bound to **unique variables** receiving secret flows |
| **Culprit Blocks**<br>*(`num_culprit_blocks`)* | Extracted from **Miter AST** (duplicated across traces) | Extracted from **Source C AST** ($\text{num\_culprit\_blocks} \le \text{num\_branches}$) |
| **Assumptions Count**<br>*(`num_assumptions`)* | Counted raw `__CPROVER_assume` calls in Miter (inflated by range checks) | Strictly equal to total inputs: $\text{num\_assumptions} == \text{num\_inputs} (\text{high} + \text{low})$ per MQIL Table III |
| **Information Leak Count**<br>*(`num_information_leak`)* | Extracted from **Miter AST** (counts `var_1` and `var_2` separately) | Extracted from **Source C AST** (unique internal intermediate clean variables carrying secret taint) |
| **Input Exclusion** | Public and secret inputs could appear in leaked counts | Inputs (`high_vars`, `low_vars`, formal parameters) strictly excluded from internal leaked counts |
| **Flow Sensitivity (Def-Kill)** | Monotonic may-taint (variables never cleaned on overwrite) | Unconditional scalar overwrites with clean data kill taint ($\text{x} = 21$ cleans variable $\text{x}$) |
| **Taint Ratio**<br>*(`taint_ratio`)* | $\frac{\text{clean\_vars (Miter)}}{\text{miter\_variables}}$ | $\frac{\text{clean\_vars (Source)}}{\text{num\_variables (Source)}} \in [0.0, 1.0]$ |
| **Ground Truth Targets**<br>*(`actual_mqil_leakage`, `actual_mqil_assertions_total`, `cbmc_verified`)* | Formally verified by **CBMC on Miter** | Formally verified by **CBMC on Miter** *(Unchanged)* |

---

### Concrete Comparison on `benchmark_30_loc.c`

```c
// High: secret_val, Low: public_val
int security_kernel(int sec, int pub) {
    int mask = (sec ^ 0x3F) & 15;
    int acc = pub * 3;
    if (mask > 8) {
        acc += (mask * 2);
    } else {
        acc -= (mask + 1);
    }
    return acc;
}
// In main(): intermediate = security_kernel(secret_val, public_val); g_sink = intermediate + status;
```

| Metric | Existing Architecture | Finalized Source-Centric Architecture | Mathematical Guarantee / Explanation |
| :--- | :---: | :---: | :--- |
| **`num_variables`** | 9 | **9** | Total variables declared in source program. |
| **`num_assumptions`** | 6 | **2** | Strictly equal to inputs: $\text{high\_vars} (1) + \text{low\_vars} (1) = 2$. |
| **`num_culprit_blocks`** | **2** | **1** | Only 1 secret-dependent branch (`mask > 8`), strictly $\le \text{num\_branches} (1)$. |
| **`num_explicit_flows`** | **10** | **4** | Unique variables with explicit secret flows: `{acc, g_sink, intermediate, mask}` $\le \text{num\_variables} (9)$. |
| **`num_implicit_flows`** | **4** | **1** | Unique variables modified in culprit blocks: `{acc}` $\le \text{num\_variables} (9)$. |
| **`num_information_leak`** | **6** | **4** | Unique internal variables carrying secret taint: `{acc, g_sink, intermediate, mask}` $\le \text{num\_variables} (9)$. |
| **`taint_ratio`** | 0.2308 (6 / 26) | **0.4444** (4 / 9) | Strictly bounded in $[0.0, 1.0]$. |
| **`secret_branch_ratio`** | 2.0 (inflated) | **1.0** (1 / 1) | Strictly bounded in $[0.0, 1.0]$. |
| **`actual_mqil_leakage`** | **3** | **3** | Formally verified by CBMC observational equivalence check. |

---

## 6. Directory Layout & Key Deliverables

```
FP/
├── datasets/
│   ├── stage1_smoke/                  # Small calibration programs
│   ├── random/                        # 1,000 programs (200-500 LOC)
│   ├── random_2/                      # 1,000 programs (600-1000 LOC)
│   ├── random_3/                      # 1,000 programs (1.2k-1.8k LOC)
│   └── random_4/                      # Flagship dataset (1,000 programs, 2k-2.5k LOC, >15 inputs)
│       ├── programs/                  # 1,000 unique C benchmark programs
│       ├── configs/                   # 1,000 variable sensitivity JSONs
│       ├── miters/                    # 1,000 2-safety miter C files & ASTs
│       ├── cbmc/                      # 1,000 CBMC verification JSON reports
│       ├── features/                  # 1,000 feature extraction JSON files
│       ├── random_dataset.csv         # Master tabular dataset (1,000 × 35, 0 nulls)
│       └── random_dataset_report.json # Dataset validation and distribution summary
├── docs/
│   └── MQIL_Research_Paper.pdf        # IEEE 2026 research paper
├── src/
│   ├── core/
│   │   ├── cbmc_runner.py             # CBMC execution engine
│   │   ├── feature_extractor.py       # AST feature extraction engine
│   │   └── transpiler.py              # MQIL transpiler wrapper
│   ├── generator/
│   │   ├── random_program_generator_v4.py # Flagship dataset generator
│   │   └── program_templates.py       # Structural code templates
│   └── models/                        # ML model training scripts (Person 2/3)
├── tools/
│   └── cbmc_mqil/                     # Official MQIL AST miter generator
├── benchmark_30_loc.c                 # Micro-benchmark source C file
├── benchmark_30_loc_miter.c           # Micro-benchmark miter C file
└── run_generate_random_4.py           # Top-level parallel batch runner
```

---

## 7. Instructions for the Reviewing Agent

If you are an AI agent reviewing or continuing this project, consider these guidelines:

1. **Person 1 Boundary (Current Work)**:
   - All dataset generation, miter generation, CBMC verification, and AST feature extraction are complete, verified, committed, and pushed to `origin/main` (`commit d194bebd`).
   - The flagship dataset is located in [`datasets/random_4/`](file:///c:/Users/sujit/OneDrive/Documents/FP/datasets/random_4/).

2. **When Discussing with the Professor**:
   - Frame the difference between the **Existing** and **Proposed** feature architectures using the **MQIL paper (Section III & V, Table I)**:
     - The miter is an artificial verification harness; extracting features from it introduces self-composition artifact inflation ($2\times$ duplication).
     - Moving Group B taint extraction to the original source C file preserves mathematical sanity ($\text{num\_information\_leak} \le \text{num\_variables}$) while keeping the miter strictly for what it was designed for: **CBMC ground-truth label generation**.

3. **Handover to Person 2 & Person 3 (Machine Learning)**:
   - **Input Features ($X$)**: The 28 static AST features in [`datasets/random_4/random_dataset.csv`](file:///c:/Users/sujit/OneDrive/Documents/FP/datasets/random_4/random_dataset.csv).
   - **Target Labels ($y$)**:
     - Binary classification: `cbmc_verified` (`VALID` vs `LEAKAGE_DETECTED`).
     - Regression / Count prediction: `actual_mqil_leakage` (number of leaky variables).
   - Baseline models to evaluate: Random Forest, XGBoost, Multi-Layer Perceptron (MLP), and Graph Neural Networks (GNN) on the AST graph representation.

