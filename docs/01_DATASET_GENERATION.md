# Phase 1 — Whole-Program Benchmark Dataset Generation (MQIL Framework)
**Responsible Role**: Person 1 (Data Engineering & Program Synthesis)

---

## 1. Objective

Build a reproducible, diverse, and progressively scaled dataset of compilable C programs for:

> **Core Problem Statement**: Predict the quantitative information leakage (`#leak`) of a C source program using supervised machine learning, without requiring a compiler or formal model checker during ML inference.

Every dataset sample represents an entire C program evaluated under defined sensitive (high) inputs and non-sensitive (low) inputs.

---

## 2. Whole-Program Architecture (No Function Isolation)

Unlike naive unit-level approaches, the analysis evaluates the **entire C program as a whole**:
* **Global Variables**: Global state, tables, and shared data.
* **Helper Functions**: All internal functions, cryptographic transformations, and subroutines.
* **`main()` Function**: The program entrypoint orchestrating calls and input consumption.

### Companion Specification File (`input_args.json`)
Every C program `program.c` has a companion JSON descriptor read by the MQIL tool:
```json
{
  "input_vars": ["key", "plaintext", "iv"],
  "high_vars": ["key"],
  "low_vars": ["plaintext", "iv"]
}
```
* **`input_vars`**: All inputs provided to the program.
* **`high_vars`**: Sensitive secrets ($H$) whose leakage must be tracked.
* **`low_vars`**: Non-sensitive / public inputs ($L$) directly observable or controlled by the attacker.

---

## 3. Four-Stage Dataset Generation Roadmap

To ensure robustness, verification accuracy, and scalability, dataset generation is divided into **four progressive stages**:

| Stage | Name | Target Program Count | Distribution | Primary Purpose & Verification Gates |
| :--- | :--- | :--- | :--- | :--- |
| **Stage 1** | **Smoke Test & Canonical Baseline** | **10 – 15 programs** | 1–2 programs per family across all families | Verify pipeline end-to-end: compiler sanity, official miter transpiler, CBMC execution, and feature extraction. |
| **Stage 2** | **Pipeline Validation** | **50 programs** | 5 programs per family across 10 families | Stress test generator parameters, detect edge cases, confirm non-zero variance, test concurrent miter transpilation. |
| **Stage 3** | **Core Benchmark Scaling** | **1,000 programs** | 100 programs per family across 10 families | Production ML training dataset: sufficient sample size for tree ensembles, MLP, SVR, family-grouped splitting, and ablation studies. |
| **Stage 4** | **Production & Deep Learning Scale** | **10,000+ programs** | 1,000+ programs per family + crypto benchmarks | Large-scale deep learning / GNN evaluation, fuzz-based program mutation, and high-throughput batch model checking. |

---

### Stage 1: Smoke Test & Canonical Baseline (10 – 15 Programs)
* **Goal**: Establish a bug-free baseline pipeline.
* **Volume**: 10 to 15 hand-curated and seeded canonical C programs covering each family identifier (`family_id`).
* **Content**:
  - One clean canonical sample per family:
    1. `zero_leakage`: `output = low_input; return output;`
    2. `direct_leakage`: `output = high_input; return output;`
    3. `partial_leakage`: `output = high_input & 0x0F; return output;`
    4. `implicit_flow`: `if (high_input > 10) output = 1; else output = 0;`
    5. `arithmetic`: `output = (high_input * 3 + 7) % 256;`
    6. `bitwise`: `output = (high_input ^ 0xAA) << 1;`
    7. `nested_branches`: Multi-tier thresholds on `high_input`.
    8. `loop_accumulator`: Secret accumulation inside bounded loop.
    9. `array_lookup`: Table lookup indexed by `high_input % 8`.
    10. `mixed_control_data`: Hybrid branches, loops, and bitwise operations.
* **Verification Gates**:
  1. `gcc -fsyntax-only` passes with zero errors and zero warnings.
  2. Miter transpiler generates valid self-composition 2-safety C files with `#include <assert.h>` and `__CPROVER_assume()`.
  3. CBMC runs cleanly under WSL Ubuntu and produces integer `#leak`.
  4. Feature extractor extracts all Group A, Group B, and Ratio columns without `NaN` or runtime crashes.

---

### Stage 2: Pipeline Validation (50 Programs)
* **Goal**: Validate generator parameterization, feature variance, and concurrent transpilation.
* **Volume**: 50 programs (5 programs per family $\times$ 10 families).
* **Generation Mechanism**:
  - Parameterized generator randomly varies:
    - Secret bit-width and variable types (`uint8_t`, `uint16_t`, `uint32_t`, `int`).
    - Bitmask constants (`0x01`, `0x0F`, `0x55`, `0xAA`, `0xFF`).
    - Loop bounds ($N \in [2, 16]$) ensuring CBMC unwinding completes within acceptable timeout.
    - Branch condition thresholds.
* **Verification Gates**:
  1. Verify zero duplicated programs via SHA-256 source code hashing.
  2. Confirm non-zero variance across Group A and Group B features on the training subset.
  3. Validate multi-worker execution of the miter transpiler without file overwrite race conditions.

---

### Stage 3: Core Benchmark Scaling (1,000 Programs)
* **Goal**: Provide the primary dataset for supervised regression modeling, cross-validation, and feature ablation.
* **Volume**: 1,000 programs (100 programs per family $\times$ 10 families).
* **Generation Mechanism**:
  - Automated combinatorial synthesis engine injecting:
    - Random AST perturbations (variable renaming, dead-code branches, multiple helper functions).
    - Diverse control-flow graphs (nested `if-else` up to depth 4, interleaved loops).
    - Multi-secret inputs (`key_part_1`, `key_part_2`).
    - Mixed arithmetic-logic expressions.
* **Verification Gates**:
  1. Grouped train/val/test splits (70% train, 10% val, 20% test) with **zero family overlap** in test set.
  2. Full feature extraction saved into `datasets/stage2_pipeline/dataset.csv`.
  3. Model training baseline: achieves low MAE on validation set and positive $R^2$ on held-out families.

---

### Stage 4: Production & Deep Learning Scale (10,000+ Programs)
* **Goal**: Support deep learning models (Graph Neural Networks over AST/CFG, Transformers, Large Language Models) and extensive stress testing.
* **Volume**: 10,000+ programs (1,000+ programs per family $\times$ 10 families + crypto benchmarks).
* **Generation Mechanism**:
  - Grammar-guided fuzzing and stochastic program synthesis.
  - Inclusion of real-world cryptographic algorithm implementations (**AES**, **DES**, **SHA-256**, **RSA**) from the MQIL research paper.
  - Variable complexity from small utilities (<50 LOC) to multi-function libraries (>500 LOC).
* **Verification Gates**:
  1. Distributed/parallel CBMC bounded model checking cluster.
  2. Automated solver timeout handling (unwind bounds scaled with loop structure).
  3. Scaled feature matrix export for GNN graph representations (node features + adjacency matrices) and tabular CSV format.

---

## 4. Benchmark Program Families

To ensure machine learning models learn generalizable security principles rather than memorizing syntax, benchmarks are organized into **distinct architectural families**:

1. **`zero_leakage`**: Functions where high inputs never affect observable state (dead code, constant returns, symmetric cancellations like $s - s$, $s \oplus s$).
2. **`direct_leakage`**: Explicit data-flow chains propagating secrets directly to return points or global outputs.
3. **`partial_leakage`**: Truncated leakage via bitmasking (`key & 0x0F`), modulo reduction, and bit-shifting.
4. **`implicit_flow`**: Control-dependence side channels where secret values determine branch conditions (`if (key > threshold)`).
5. **`arithmetic`**: Algebraic transformations, linear mappings ($a \cdot s + b$), polynomial equations, and modular arithmetic.
6. **`bitwise`**: Cryptographic primitives including XOR masks, rotations, substitution boxes (S-Boxes), and bitwise permutations.
7. **`nested_branches`**: Deep decision trees and multi-tier interval classifications.
8. **`loop_accumulator`**: Iterative leakage accumulating sensitive data inside `for`, `while`, and `do-while` loops.
9. **`array_lookup`**: Secret-dependent memory indexing (cache timing vulnerabilities: $A[\text{secret} \pmod M]$).
10. **`mixed_control_data`**: Hybrid programs combining loops, branch conditions, arrays, and arithmetic.
11. **`crypto_realworld`**: Real-world cryptographic algorithms from the MQIL paper: **AES**, **DES**, **SHA**, and **RSA**.

---

## 5. Dataset Row Schema

Every row in the assembled dataset records:
* **Program Identifiers**: `program_id`, `family_id`, `source_file`.
* **Group A Features** (Program Structure, 10 features): `loc`, `num_instructions`, `num_branches`, `num_loops`, `num_functions`, `num_variables`, `num_arrays`, `num_structure`, `num_union`, `loop_to_unwind_ratio`.
* **Group B Features** (Security & Taint Flow, 14 features): `num_high_inputs`, `num_low_inputs`, `num_explicit_flows`, `num_culprit_blocks`, `num_implicit_flows`, `num_information_leak`, `num_secret_dependent_prints`, `num_assumptions`, `num_assertions`, `num_array_accesses`, `num_tainted_returns`, `num_tainted_globals`, `max_taint_depth`, `num_secret_bitops`.
* **Group C Features** (Normalized Security Ratios, 3 features): `taint_ratio`, `secret_branch_ratio`, `secret_memory_ratio`.
* **Total Input Features**: **27 features** ($10 + 14 + 3$).
* **Ground-Truth Target**: `actual_mqil_leakage` (`#leak` = number of failed CBMC assertions) and auxiliary metadata `actual_mqil_assertions_total`, `mqil_leak_ratio`.

> [!IMPORTANT]
> The target column `actual_mqil_leakage` is strictly for model training and evaluation. It must never be included as an input feature during training or inference.

---

## 6. Execution Command for Person 1

Person 1 can execute any stage using the unified CLI:

```powershell
# Stage 1: Smoke Test (12 canonical programs)
python main.py --stage 1

# Stage 2: Pipeline Validation (50 diverse programs)
python main.py --stage 2
```

---

## 7. Person 1 Deliverable Checkpoint

Person 1 produces:
1. `datasets/stage1_smoke/`: All synthesized C source files, companion `input_args.json`, and miters.
2. `datasets/stage2_pipeline/`: 50 validated programs, miters, and grouped splits.
3. Verified compilation and deduplication (SHA-256 source hashing).
4. Ground truth CBMC model checker logs and `#leak` targets.
5. Assembled feature datasets in `datasets/stage1_smoke/dataset.csv` and `datasets/stage2_pipeline/dataset.csv`.
