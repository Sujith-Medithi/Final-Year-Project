# Dataset Generation Pipeline Analysis & Implementation Architecture
**Research Project:** Predict the Information Leakage of a C Program Using Machine Learning  
**Target Output File:** `DATASET_GENERATION_ANALYSIS.md`  
**Root Directory:** `c:\Users\sujit\OneDrive\Documents\FP`  
**Generated Date:** October 2026

---

# 1. Project Overview

### 1.1 Project Title
**Predict the Information Leakage of a C Program Using Machine Learning (MQIL Framework)**

### 1.2 Problem Statement
Quantitative Information Flow (QIF) analyzes how many bits of confidential secret data (e.g., cryptographic keys, passwords, biometric records) are observable through public outputs or micro-architectural side channels. Traditional formal verification methods—specifically SMT/SAT-based Bounded Model Checking with tools like **CBMC**—provide mathematical ground truth for information leakage by verifying 2-safety hyperproperties on self-composition product programs (miters). 

However, formal model checking is computationally intractable on large, complex codebases due to path explosion and unbounded state spaces. This project addresses this bottleneck by asking:  
*Can a machine learning regression model, trained on static structural features (from the source program AST) and semantic information-flow features (from the miter program AST), accurately predict quantitative information leakage in milliseconds?*

### 1.3 Dataset-Generation Objective
The objective of the dataset-generation pipeline (Person 1 responsibilities) is to:
1. Synthesize compilable, standardized C benchmark programs isolating fundamental security leakage mechanisms across 10 canonical vulnerability families.
2. Transpile each program into a formal **2-safety product program (Miter)** under self-composition.
3. Compute mathematical ground-truth leakage labels using **CBMC 6.6.0** bounded model checking.
4. Extract the complete **29-dimensional feature vector** (`FEATURE_COLS`) combining **Group A Structural Features** (Source AST), **Group B Security & Taint Flow Features** (Miter AST), **Group C Normalized Ratios**, and the **7 Flow & Verification Disambiguation Features**.
5. Assemble deterministic, tamper-proof datasets (`dataset.csv`) across three progressive development stages (`stage1_smoke`, `stage2_pipeline`, and `stage3_scaling`) with family-isolated grouped splits for supervised ML training.

### 1.4 Role of Dataset Generation in the Complete ML Project
The dataset generation pipeline serves as the ground-truth data engine for the machine learning workflow (Person 2 responsibilities). Person 2 trains regression models (Ridge, Random Forest, SVR, MLP, and Gradient Boosting), conducts a 4-tier feature ablation study, and evaluates explainability (SHAP values and feature importances) to determine which code patterns contribute most to information leakage.

### 1.5 End-to-End Pipeline Diagram

```text
┌────────────────────────────────────────────────────────────────────────────────────────┐
│                              1. C PROGRAM SYNTHESIS                                    │
│   src/generator/program_templates.py ──→ src/generator/synthesizer.py                  │
│                                              │                                         │
│                      ├───→ Original C Source (datasets/<stage>/programs/P*.c)          │
│                      └───→ Input Specs JSON   (datasets/<stage>/configs/P*.json)       │
└──────────────────────────────────────────────┬─────────────────────────────────────────┘
                                               │
               ┌───────────────────────────────┴───────────────────────────────┐
               ▼                                                               ▼
┌──────────────────────────────────────────────┐   ┌───────────────────────────────────────────┐
│     2. SOURCE C FEATURE EXTRACTION           │   │            3. MITER GENERATION            │
│                                              │   │                                           │
│ Source C Program (P*.c)                      │   │ Source C (P*.c) + Specs (P*.json)         │
│       │                                      │   │       │                                   │
│       ▼ [pycparser with fake_libc]           │   │       ▼ [tools/cbmc_mqil/src/main.py]     │
│ Source AST (c_ast.FileAST)                   │   │ Self-Composition Miter Transpiler:        │
│       │                                      │   │   • Duplicates functions into fn_1, fn_2  │
│       ▼ [SourceStructureVisitor + Rule D8]   │   │   • Duplicates variables into v_1, v_2    │
│ Group A Structural Features                  │   │   • Injects __CPROVER_assume(low_1==low_2)│
│ (loc, num_instructions, num_branches, etc.)  │   │   • Injects assert(out_1 == out_2)        │
└──────────────────────┬───────────────────────┘   │       │                                   │
                       │                           │       ▼                                   │
                       │                           │ Miter C Program                           │
                       │                           │ (datasets/<stage>/miters/P*_miter.c)      │
                       │                           └───────────────────┬───────────────────────┘
                       │                                               │
                       │                       ┌───────────────────────┴───────────────────────┐
                       │                       ▼                                               ▼
                       │   ┌───────────────────────────────────────────┐   ┌───────────────────────────┐
                       │   │       4. MITER SECURITY EXTRACTION        │   │   5. CBMC VERIFICATION    │
                       │   │                                           │   │                           │
                       │   │ Miter C Program (P*_miter.c)              │   │ Miter C (P*_miter.c)      │
                       │   │       │                                   │   │       │                   │
                       │   │       ▼ [pycparser with fake_libc]        │   │       ▼ [CBMC 6.6.0 WSL]  │
                       │   │ Miter AST (c_ast.FileAST)                 │   │ src/core/cbmc_runner.py   │
                       │   │       │                                   │   │   • Unwinds loops (--unwind 5)
                       │   │       ▼ [Fixpoint Interprocedural Taint]  │   │   • Evaluates assertions  │
                       │   │ Seeds: high_vars_1, high_vars_2           │   │       │                   │
                       │   │       │                                   │   │       ▼                   │
                       │   │       ▼ [FinalCounterVisitor + Rule D2]   │   │ Ground-Truth Target Label │
                       │   │ Group B Security Features & Ratios        │   │ actual_mqil_leakage       │
                       │   │ (num_explicit_flows, taint_ratio, etc.)   │   │ (#leak = failed asserts)  │
                       └───┼───────────────────┬───────────────────────┘   └───────────┬───────────────┘
                           │                   │                                       │
                           └───────────────────┼───────────────────────────────────────┘
                                               │
                                               ▼
┌────────────────────────────────────────────────────────────────────────────────────────┐
│                                 6. DATASET ASSEMBLY                                    │
│  src/pipeline.py:                                                                      │
│    Metadata (program_id, family_id, paths, inputs, sha256)                             │
│    + Group A Features (from Source AST)                                                │
│    + Group B Security Features (from Miter AST)                                        │
│    + Normalized Ratios (taint_ratio, secret_branch_ratio, secret_memory_ratio)         │
│    + Ground-Truth Target (actual_mqil_leakage, actual_mqil_assertions_total)           │
│                                              │                                         │
│                                              ▼                                         │
│       Output: datasets/<stage>/dataset.csv (31 to 32 Columns)                          │
│       Splits: datasets/<stage>/splits/grouped_splits.json                              │
│       Provenance: datasets/<stage>/MANIFEST.json                                       │
└────────────────────────────────────────────────────────────────────────────────────────┘
```

---

# 2. Repository Structure Relevant to Dataset Generation

```text
c:\Users\sujit\OneDrive\Documents\FP\
├── main.py                                  ← CLI Entry point driving all generation stages
├── dataset.csv                              ← Root static 50-program baseline dataset
├── datasets/
│   ├── stage1_smoke/                        ← Stage 1: 12 Canonical Baseline Programs
│   │   ├── dataset.csv                      ← 12 rows, 31 columns (Smoke verified)
│   │   ├── MANIFEST.json                    ← Cryptographic integrity certificate & toolchain versions
│   │   ├── cbmc_verification.json           ← Raw CBMC solver execution log
│   │   ├── programs/ (P000001.c - P000012.c)← Raw compilable source C programs
│   │   ├── configs/  (P000001.json - ...)   ← Companion input variable specifications
│   │   └── miters/   (P000001_miter.c - ...)← 2-safety self-composition product programs
│   ├── stage2_pipeline/                     ← Stage 2: 50 Parametric Validation Programs
│   │   ├── dataset.csv                      ← 50 rows, 32 columns (includes sha256)
│   │   ├── MANIFEST.json                    ← Cryptographic certificate & split summary
│   │   ├── cbmc_verification.json           ← Raw CBMC solver execution log
│   │   ├── programs/ (P000001.c - P000050.c)← Diverse parameterized C source files
│   │   ├── configs/  (P000001.json - ...)   ← Companion input specifications
│   │   ├── miters/   (P000001_miter.c - ...)← 2-safety product programs
│   │   └── splits/
│   │       └── grouped_splits.json          ← Family-grouped train/val/test index partitions
│   └── stage3_scaling/                      ← Stage 3: 1,000 Scaled Core Benchmark Programs
│       ├── dataset.csv                      ← 1,000 rows, 32 columns (Primary ML Dataset)
│       ├── MANIFEST.json                    ← Full provenance certificate & split distribution
│       ├── cbmc_verification.json           ← Raw CBMC solver status for all 1,000 instances
│       ├── programs/ (P000001.c - P001000.c)← 1,000 unique C benchmark source files
│       ├── configs/  (P000001.json - ...)   ← 1,000 companion input JSON files
│       ├── miters/   (P000001_miter.c - ...)← 1,000 generated 2-safety miters
│       └── splits/
│           └── grouped_splits.json          ← 700 Train (7 fams), 100 Val (1 fam), 200 Test (2 fams)
├── src/
│   ├── pipeline.py                          ← Unified orchestrator for Stages 1, 2, and 3
│   ├── generator/
│   │   ├── program_templates.py             ← Canonical kernels and format_whole_c_program()
│   │   └── synthesizer.py                   ← Parametric program generator & deduplicator
│   └── core/
│       ├── transpiler.py                    ← Python bridge to miter generator
│       ├── cbmc_runner.py                   ← Bounded Model Checker runner (WSL / Native)
│       └── feature_extractor.py             ← Complete 22-feature AST visitor & taint engine
├── tools/
│   ├── fake_libc/                           ← Minimal standard C library stubs for pycparser
│   └── cbmc_mqil/
│       └── src/
│           ├── main.py                      ← Official AST miter generator script
│           └── modules/                     ← AST rewriting passes (Renamer, AddAssert, etc.)
├── tests/                                   ← Automated regression tests (21 passed tests)
└── archive/                                 ← Legacy prototype scripts and historical records
```

### Component Status Classification:
* **Current Code:** `main.py`, `src/pipeline.py`, `src/generator/*`, `src/core/*`, `tools/cbmc_mqil/src/main.py`, `tools/fake_libc/*`, `datasets/stage*`.
* **Supporting Code:** `tests/*` (validation suite), `results/reports/*` (markdown verification audits).
* **Legacy / Possibly Unused:** `archive/legacy_chatgpt_archive/`, `tools/cbmc_mqil/src/modules/FuncCopy2.py` (deprecated visitor), `scratch/` (temporary debugging scripts).

---

# 3. Dataset Generation Entry Point

### 3.1 Entry Point Specification
* **File Name:** `main.py`
* **Exact Path:** `c:\Users\sujit\OneDrive\Documents\FP\main.py`
* **Responsible Function:** `main()` (lines 27–90)
* **Execution Start:** Command-line invocation with `--stage` flag.
* **Orchestrator File:** `src/pipeline.py` (`run_stage1_smoke`, `run_stage2_pipeline`, `run_stage3_scaling`)

### 3.2 Execution Commands
```powershell
# Stage 1: Smoke test and 12 canonical programs
python main.py --stage 1

# Stage 2: Pipeline validation on 50 programs
python main.py --stage 2

# Stage 3: Full 1,000-program scaling on 8 threads
python main.py --stage 3
```

### 3.3 Call & Dependency Chain
```text
main.py
  │
  └── src/pipeline.py: run_stage3_scaling()
        │
        ├── [Step 1: Program Synthesis]
        │     └── src/generator/synthesizer.py: generate_stage2_benchmarks(count_per_family=100)
        │           └── src/generator/program_templates.py: format_whole_c_program()
        │                 ├── Writes: datasets/stage3_scaling/programs/P*.c
        │                 └── Writes: datasets/stage3_scaling/configs/P*.json
        │
        ├── [Step 2: Concurrent Worker Processing (ThreadPoolExecutor - 8 workers)]
        │     │
        │     ├── Miter Transpilation
        │     │     └── src/core/transpiler.py: generate_miter_program()
        │     │           └── tools/cbmc_mqil/src/main.py
        │     │                 └── Writes: datasets/stage3_scaling/miters/P*_miter.c
        │     │
        │     ├── CBMC Ground-Truth Solving
        │     │     └── src/core/cbmc_runner.py: run_cbmc_verification()
        │     │           └── Executes: wsl -d Ubuntu cbmc <miter.c> --unwind 5
        │     │                 └── Extracts: actual_mqil_leakage (#leak)
        │     │
        │     └── Feature Extraction
        │           └── src/core/feature_extractor.py: extract_all_mqil_features()
        │                 ├── extract_group_a_features()  (Measured on Source AST)
        │                 ├── extract_group_b_features()  (Measured on Miter AST)
        │                 └── Computes Group C Ratios     (D2 normalized counters)
        │
        └── [Step 3: Dataset Assembly & Split Generation]
              ├── Sorts by program_id and saves datasets/stage3_scaling/dataset.csv
              ├── src/pipeline.py: create_family_grouped_splits() → grouped_splits.json
              └── Updates datasets/stage3_scaling/MANIFEST.json
```

---

# 4. Complete Dataset Pipeline

| Stage | Input | Processing | Output | Actual File / Function |
|---|---|---|---|---|
| **1. C Generation** | Family specifications, index $k$, constants | Generates uninitialized symbolic variables, helper kernels, assignments, standard headers | `P*.c` source files and `P*.json` configs | `src/generator/synthesizer.py`: `generate_stage2_benchmarks()` |
| **2. AST Generation** | `P*.c` and `P*_miter.c` | Sanitizes headers, parses C99 syntax using `fake_libc` headers | In-memory `c_ast.FileAST` tree | `src/core/feature_extractor.py`: `parse_c_ast()` |
| **3. Structural Extraction** | Source AST (`P*.c`) | Visits statement and declaration nodes; enforces Rule D8 variable counting | 9 Group A Structural metrics (`loc`, `num_instructions`, etc.) | `src/core/feature_extractor.py`: `extract_group_a_features()` |
| **4. Miter Generation** | `P*.c` and `P*.json` | Duplicates functions (`_1`, `_2`), injects public assumptions, injects equivalence assertions | `P*_miter.c` 2-safety product program | `tools/cbmc_mqil/src/main.py` via `src/core/transpiler.py` |
| **5. Security Extraction** | Miter AST (`P*_miter.c`) | Seeds high variables, runs interprocedural fixpoint taint propagation, counts culprit blocks | 10 Group B Security metrics + 3 Normalized Ratios | `src/core/feature_extractor.py`: `extract_group_b_features()` |
| **6. CBMC Solving** | `P*_miter.c` | Bounded model checking with SAT solving (`--unwind 5`) | Terminal verification report with assertion statuses | `src/core/cbmc_runner.py`: `run_cbmc_verification()` |
| **7. Leakage Calculation** | CBMC terminal text | Regex filters for `[*.assertion.*]`, counts failed assertions | Target integer `actual_mqil_leakage` | `src/core/cbmc_runner.py:L70-L95` |
| **8. Dataset Assembly** | Feature dicts, metadata, CBMC target | Formats tabular records, asserts 0 NaNs, exports CSV, creates grouped splits | `dataset.csv`, `grouped_splits.json`, `MANIFEST.json` | `src/pipeline.py`: `run_stage3_scaling()` |

---

# 5. C Program Generation

### 5.1 Generator Files
* `src/generator/program_templates.py`: Canonical kernels and template wrapper `format_whole_c_program()` ([lines 179–197](file:///c:/Users/sujit/OneDrive/Documents/FP/src/generator/program_templates.py#L179-L197)).
* `src/generator/synthesizer.py`: Parametric synthesis functions `generate_stage1_benchmarks()` and `generate_stage2_benchmarks()`.

### 5.2 Program Formatting Logic
Each program is formatted with standard C headers, global output variables, a helper kernel function, and uninitialized symbolic variables in `main()`:
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

<globals_code>   // e.g., int glob_direct_0;

<helper_funcs>   // e.g., int direct_kernel_0(int h, int p) { ... }

int main()
{
    int key_in;  // Symbolic High Input
    int pub_in;  // Symbolic Low Input
    int res;
    res = direct_kernel_0(key_in, pub_in);
    glob_direct_0 = res;
    return 0;
}
```

### 5.3 The 10 Canonical Program Families & Parameterization
Programs are deterministic functions of family archetype and program index $k$:

1. **`zero_leakage`**: Secret multiplied by zero: `temp = (s + k*3) * 0; return (temp + (p * (k+2))) + 1;`
2. **`direct_leakage`**: High input forwarded directly: `int t1 = h + k*5; return t1 - k*5 + p;`
3. **`partial_leakage`**: Bitwise shift and masking: `return ((s >> ((k%3)+1)) & [1, 3, 7, 15, 31][k%5]) + b;`
4. **`implicit_flow`**: Branch threshold dependent on secret: `if (s > (k+1)*15) flag = k*10+5; else flag = k*10+20;`
5. **`arithmetic`**: Modular affine transform: `return (((s * (k*2+3) + (k*7+1)) % 256) * sc);`
6. **`bitwise`**: XOR mask and rotation: `int x = (tok ^ [0x55, 0xAA, 0x0F, 0xF0, 0x33][k%5]) << ((k%3)+1); return x ^ n;`
7. **`nested_branches`**: Decision interval thresholds: `t1 = 20 + k*10; t2 = 50 + k*10; if (sc > t2) ... else if (sc > t1) ...`
8. **`loop_accumulator`**: Bounded loop accumulating bits: `limit = 2 + (k%4); for (int i = 0; i < limit; i++) acc += ((d >> i) & 1) + k;`
9. **`array_lookup`**: Secret-indexed lookup table: `lookup_table[idx % 4] + base;` where table has `{10 + k*4, 25 + k, 42, 99}`.
10. **`mixed_control_data`**: Hybrid loop + status array + conditional branch.

### 5.4 Deduplication & Naming
* **Deduplication:** Computes SHA-256 of every program string; an assertion crashes generation if any duplicate code hash is detected (`synthesizer.py:L170-L172`).
* **Naming:** 6-digit zero-padded index: `P000001.c` through `P001000.c`.
* **Storage:** `datasets/<stage_name>/programs/` with companion `datasets/<stage_name>/configs/P*.json`.

---

# 6. AST Generation

### 6.1 AST Technology
* **Tool / Library:** `pycparser`
* **Version:** `3.00`
* **Parser Standard:** ANSI C99 with GNU extensions
* **Header Support:** Stubs in `tools/fake_libc/` providing C99 types (`size_t`, `FILE`, `bool`).

### 6.2 AST Creation Flow
* **File:** `src/core/feature_extractor.py`
* **Function:** `parse_c_ast(file_path: Path) -> c_ast.FileAST` (lines 59–76)
* **Code Cleaning:** `clean_c_code_for_pycparser()` strips `#include` directives, `#define` macros, and C/C++ comments so `pycparser` parses standard code without invoking an external preprocessor binary.
* **Storage:** ASTs exist strictly **in-memory** as Python objects (`c_ast.FileAST`). No temporary files are written to disk.

### 6.3 AST Traversal
* **Mechanism:** Subclasses of `pycparser.c_ast.NodeVisitor`.
* **Method Dispatch:** Overrides methods matching node class names (e.g., `visit_FuncDef`, `visit_If`, `visit_Assignment`, `visit_ArrayRef`).
* **Traversal Control:** Each visitor method invokes `self.generic_visit(node)` to recursively traverse child nodes.

---

# 7. Structural Feature Extraction Table

All structural features are extracted from the **clean Source C file** (`C1` rule) to capture true source program complexity without miter overhead.

| Feature | Definition | AST Node(s) | Extraction Logic | Source File | Function | CSV Column |
|---|---|---|---|---|---|---|
| `loc` | Lines of source code | N/A (Text) | `len(text.splitlines())` | `src/core/feature_extractor.py` | `extract_group_a_features` | `loc` |
| `num_instructions` | Executable statements | `Assignment`, `FuncCall`, `If`, `Return` | Sum of visits to statement AST nodes | `src/core/feature_extractor.py` | `SourceStructureVisitor` | `num_instructions` |
| `num_branches` | Control-flow branch points | `If`, `Switch`, `For`, `While`, `DoWhile` | Counts every conditional and loop branch point | `src/core/feature_extractor.py` | `SourceStructureVisitor` | `num_branches` |
| `num_loops` | Loop constructs | `For`, `While`, `DoWhile` | Counts iteration loops | `src/core/feature_extractor.py` | `SourceStructureVisitor` | `num_loops` |
| `num_functions` | Defined functions | `FuncDef` | Counts defined functions with bodies | `src/core/feature_extractor.py` | `SourceStructureVisitor` | `num_functions` |
| `num_variables` | Declared variables (D8) | `Decl` (`TypeDecl`, `ArrayDecl`, `PtrDecl`) | Counts globals, locals, loop vars, params of defs; excludes extern/typedef/prototypes | `src/core/feature_extractor.py` | `extract_d8_variables` | `num_variables` |
| `num_arrays` | Array declarations | `Decl` wrapping `ArrayDecl` | Counts variable declarations of array type | `src/core/feature_extractor.py` | `SourceStructureVisitor` | `num_arrays` |
| `num_structure` | Struct definitions & vars | `Decl` wrapping `Struct` | Counts struct definitions and struct instance variables | `src/core/feature_extractor.py` | `SourceStructureVisitor` | `num_structure` |
| `num_union` | Union definitions & vars | `Decl` wrapping `Union` | Counts union definitions and union instance variables | `src/core/feature_extractor.py` | `SourceStructureVisitor` | `num_union` |

---

# 8. Detailed Group A Features Specification

### Feature: `loc`
* **Definition:** Total line count of the source C file.
* **Source:** Source C file (`source_c_path`).
* **Function:** `extract_group_a_features()` (`feature_extractor.py:L302`).
* **AST node(s):** None (computed on raw file text).
* **Extraction logic:** `len(text.splitlines())`.
* **Example:** A 22-line C file produces `loc = 22`.
* **CSV column:** `loc`.

### Feature: `num_instructions`
* **Definition:** Total count of executable instructions/statements.
* **Source:** Source C AST.
* **Function:** `SourceStructureVisitor` (`feature_extractor.py:L244-L290`).
* **AST node(s):** `c_ast.Assignment`, `c_ast.FuncCall`, `c_ast.If`, `c_ast.Return`.
* **Extraction logic:** Increments counter on visiting assignments, function calls, `if` statements, and returns.
* **Example:** `res = kernel(x, y); glob = res; return 0;` $\rightarrow$ 3 instructions.
* **CSV column:** `num_instructions`.

### Feature: `num_branches`
* **Definition:** Total number of control-flow decision branches.
* **Source:** Source C AST.
* **Function:** `SourceStructureVisitor` (`feature_extractor.py:L254-L286`).
* **AST node(s):** `c_ast.If`, `c_ast.Switch`, `c_ast.For`, `c_ast.While`, `c_ast.DoWhile`.
* **Extraction logic:** Increments on any conditional or loop branch node.
* **Example:** One `if` condition and one `for` loop $\rightarrow$ `num_branches = 2`.
* **CSV column:** `num_branches`.

### Feature: `num_loops`
* **Definition:** Total count of iteration loops.
* **Source:** Source C AST.
* **Function:** `SourceStructureVisitor` (`feature_extractor.py:L266-L286`).
* **AST node(s):** `c_ast.For`, `c_ast.While`, `c_ast.DoWhile`.
* **Extraction logic:** Increments counter strictly on loop constructs.
* **Example:** One `for (int i=0; i<4; i++)` $\rightarrow$ `num_loops = 1`.
* **CSV column:** `num_loops`.

### Feature: `num_functions`
* **Definition:** Total number of implemented function definitions.
* **Source:** Source C AST.
* **Function:** `SourceStructureVisitor.visit_FuncDef()` (`feature_extractor.py:L215`).
* **AST node(s):** `c_ast.FuncDef`.
* **Extraction logic:** Counts function definitions with bodies. Prototype declarations (`FuncDecl` without body) are excluded.
* **Example:** A file defining `direct_kernel_0` and `main` $\rightarrow$ `num_functions = 2`.
* **CSV column:** `num_functions`.

### Feature: `num_variables`
* **Definition:** Total number of unique variable declarations under Rule **D8**.
* **Source:** Source C AST.
* **Function:** `extract_d8_variables()` (`feature_extractor.py:L77-L123`).
* **AST node(s):** `c_ast.Decl` containing `TypeDecl`, `ArrayDecl`, or `PtrDecl`.
* **Extraction logic:** Counts globals, local variables, loop-declared index variables, parameters of function definitions, and struct/union members. Strictly excludes `extern` declarations, `typedef` declarations, prototype parameter declarations, and fake libc symbols.
* **Example:** In `P000001.c` (`glob_zero_0`, `s`, `p`, `temp`, `high_sec`, `pub_val`, `out`, `dead`) $\rightarrow$ `num_variables = 8`.
* **CSV column:** `num_variables`.

### Feature: `num_arrays`
* **Definition:** Total number of array declarations.
* **Source:** Source C AST.
* **Function:** `SourceStructureVisitor.visit_Decl()` (`feature_extractor.py:L225`).
* **AST node(s):** `c_ast.Decl` where `node.type` is `c_ast.ArrayDecl`.
* **Extraction logic:** Increments whenever a declaration has an array type.
* **Example:** `int lookup_table_0[4];` $\rightarrow$ `num_arrays = 1`.
* **CSV column:** `num_arrays`.

### Feature: `num_structure`
* **Definition:** Total count of `struct` definitions and struct variable declarations.
* **Source:** Source C AST.
* **Function:** `SourceStructureVisitor.visit_Decl()` (`feature_extractor.py:L229-L237`).
* **AST node(s):** `c_ast.Struct`, or `c_ast.Decl` with `Struct` type.
* **Extraction logic:** Increments on struct type definition and every declared struct instance.
* **Example:** `struct Packet { int id; }; struct Packet pkt;` $\rightarrow$ `num_structure = 2`. (Invariant `0` in synthetic micro-benchmarks).
* **CSV column:** `num_structure`.

### Feature: `num_union`
* **Definition:** Total count of `union` definitions and union variable declarations.
* **Source:** Source C AST.
* **Function:** `SourceStructureVisitor.visit_Decl()` (`feature_extractor.py:L233-L240`).
* **AST node(s):** `c_ast.Union`, or `c_ast.Decl` with `Union` type.
* **Extraction logic:** Increments on union type definition and every declared union instance.
* **Example:** `union Word { int i; char c[4]; }; union Word w;` $\rightarrow$ `num_union = 2`. (Invariant `0` in synthetic micro-benchmarks).
* **CSV column:** `num_union`.

---

# 9. Miter Generation

### 9.1 Concept of a Miter Program
A **miter** program implements **2-safety self-composition**. Proving that a program does not leak secret information (non-interference) requires showing that for any two executions starting with identical public inputs ($L_1 = L_2$) but potentially different secret inputs ($H_1 \ne H_2$), the public outputs remain identical ($O_1 = O_2$). The miter encodes both executions into a single sequential C program.

### 9.2 Generator Modules
* **Wrapper:** `src/core/transpiler.py`: `generate_miter_program()` (lines 15–46).
* **AST Rewriter Engine:** `tools/cbmc_mqil/src/main.py` (lines 17–108).
* **Modules:** `Renamer.py`, `FuncDefHandler2.py`, `AddAssumeCalls.py`, `AddAssertCalls.py`, `AddNonDetCalls.py`.

### 9.3 Transformation Logic
1. **Function Cloning:** Every function (except `main`) is duplicated into suffixed versions: `kernel_1` and `kernel_2`.
2. **Variable Duplication:** Variables inside `main` and global variables are duplicated: `key_in_1`, `key_in_2`, `pub_in_1`, `pub_in_2`, `res_1`, `res_2`.
3. **Public Input Equivalence (Assumptions):**  
   `__CPROVER_assume(pub_in_1 == pub_in_2);`
4. **Secret Inputs:**  
   `key_in_1` and `key_in_2` remain unconstrained non-deterministic symbolic variables.
5. **Observability Assertions:**  
   At program exit, equivalence assertions check output and state variables:  
   `assert(glob_direct_1 == glob_direct_2);`  
   `assert(res_1 == res_2);`
* **Storage Location:** `datasets/<stage_name>/miters/P*_miter.c`.

---

# 10. Miter AST

### 10.1 Parsing the Miter File
The miter C file is parsed into a `c_ast.FileAST` using the same `parse_c_ast()` function in `src/core/feature_extractor.py`.

### 10.2 Structural Differences from Source AST
* The miter AST contains **two copies** of helper functions and variables (suffixed with `_1` and `_2`).
* It includes formal verification primitives: `__CPROVER_assume` and `assert`.
* It includes non-deterministic initializer functions (`__CPROVER_nondet_int()`).

### 10.3 Usage for Security Features
The Miter AST is used exclusively for **Group B Security Feature Extraction** because:
1. Suffixes `_1` and `_2` allow tracking whether differences in `secret_1` vs `secret_2` propagate to state variables.
2. It contains the exact `__CPROVER_assume` and `assert` nodes needed to measure assumption and assertion counts.

---

# 11. Security Feature Extraction Table

All security features are measured on the **Miter AST** (Rules **C2**, **C3**) using interprocedural fixpoint taint analysis.

| Feature | Meaning | Source | Category | Extraction Logic | File | Function | CSV Column |
|---|---|---|---|---|---|---|---|
| `num_high_inputs` | Secret input count | Config JSON | Metadata | `len(meta["high_vars"])` | `feature_extractor.py` | `extract_group_b_features` | `num_high_inputs` |
| `num_low_inputs` | Public input count | Config JSON | Metadata | `len(meta["low_vars"])` | `feature_extractor.py` | `extract_group_b_features` | `num_low_inputs` |
| `num_explicit_flows` | Data-flow assignments from secrets | Miter AST | Miter AST | Counts assignments/inits where RHS contains tainted variables | `feature_extractor.py` | `FinalCounterVisitor` | `num_explicit_flows` |
| `num_culprit_blocks` | Secret-dependent branch conditions | Miter AST | Miter AST | Counts `If`, `While`, `For` whose predicate expression contains tainted variables | `feature_extractor.py` | `FinalCounterVisitor` | `num_culprit_blocks` |
| `num_implicit_flows` | Statements in culprit branch bodies | Miter AST | Miter AST | Rule **D3**: Counts executable statements inside secret-dependent branches | `feature_extractor.py` | `_count_implicit_statements` | `num_implicit_flows` |
| `num_information_leak` | Clean variables tainted | Miter AST | Miter AST | Rule **C3**: Counts non-seed, non-parameter variables that become tainted | `feature_extractor.py` | `extract_group_b_features` | `num_information_leak` |
| `num_secret_dependent_prints` | Print calls outputting secrets | Miter AST | Miter AST | Counts calls to `printf`, `puts` whose arguments contain tainted variables | `feature_extractor.py` | `FinalCounterVisitor` | `num_secret_dependent_prints`|
| `num_assumptions` | Public equality assumptions | Miter AST | Miter AST | Rule **D5**: Counts calls to `__CPROVER_assume` | `feature_extractor.py` | `FinalCounterVisitor` | `num_assumptions` |
| `num_assertions` | Equivalence assertions | Miter AST | Miter AST | Rule **D5**: Counts calls to `assert` | `feature_extractor.py` | `FinalCounterVisitor` | `num_assertions` |
| `num_array_accesses` | Array indexing operations | Miter AST | Miter AST | Counts `ArrayRef` subscript nodes across both miter runs | `feature_extractor.py` | `FinalCounterVisitor` | `num_array_accesses` |
| `taint_ratio` | Fraction of variables tainted | Miter AST | Ratio | Formula: `num_information_leak / miter_variables` ($\in [0, 1]$) | `feature_extractor.py` | `extract_all_mqil_features`| `taint_ratio` |
| `secret_branch_ratio` | Fraction of branches tainted | Miter AST | Ratio | Formula: `num_culprit_blocks / miter_branches` ($\in [0, 1]$) | `feature_extractor.py` | `extract_all_mqil_features`| `secret_branch_ratio` |
| `secret_memory_ratio` | Fraction of array accesses tainted | Miter AST | Ratio | Formula: `secret_indexed_accesses / num_array_accesses` ($\in [0, 1]$) | `feature_extractor.py` | `extract_all_mqil_features`| `secret_memory_ratio` |

---

# 12. CBMC (C Bounded Model Checker)

### 12.1 Purpose in the Pipeline
CBMC acts as the **mathematical oracle** establishing ground-truth leakage labels. It does not generate code or extract AST features; it executes formal bounded model checking on the 2-safety miter to determine whether equivalence assertions hold.

### 12.2 Invocation & Commands
* **File:** `src/core/cbmc_runner.py`
* **Function:** `run_cbmc_verification(miter_file_path: Path, unwind: int = 5, timeout: int = 45)` (lines 21–103)
* **Command:**
  ```bash
  cbmc datasets/<stage>/miters/P000001_miter.c --unwind 5
  # WSL Execution (Windows environment):
  wsl -d Ubuntu cbmc /mnt/c/.../P000001_miter.c --unwind 5
  ```
* **Arguments:**
  * `--unwind 5`: Bounds loop unrolling to 5 iterations for deterministic termination.
  * `timeout=45`: Prevents solver hangs on deep state spaces.

### 12.3 Output Parsing
CBMC outputs assertion evaluations to stdout. The runner parses the results using regex:
```python
assertion_pattern = re.compile(
    r"\[([^\]]*\.assertion\.\d+)\]\s+line\s+\d+\s+assertion\s+([^:]+):\s+(SUCCESS|FAILURE)"
)
```
* **Ground-Truth Target:** Every equivalence assertion returning `FAILURE` indicates that differing secrets produced distinguishable public outputs.
* **Leakage Count:** `actual_mqil_leakage` $=$ count of failed assertions.
* **Total Assertions:** `actual_mqil_assertions_total` $=$ total assertions checked.

---

# 13. Information Leakage Calculation

### 13.1 Mathematical Formulation
* **File:** `src/core/cbmc_runner.py:L69-L95`
* **Target CSV Column:** `actual_mqil_leakage`
* **Auxiliary Column:** `actual_mqil_assertions_total`
* **Mathematical Formula:**
  $$\text{actual\_mqil\_leakage} = \sum_{i=1}^{N_{\text{assert}}} \mathbb{I}\left(\text{CBMC}\left(\text{out}_{1}^{(i)} == \text{out}_{2}^{(i)}\right) = \text{FAILURE}\right)$$
  Where:
  * $N_{\text{assert}}$ is the total number of equivalence assertions placed on observable variables.
  * $\mathbb{I}(\cdot)$ is the indicator function returning $1$ if the assertion fails (leakage detected) and $0$ if it holds (no leakage).

### 13.2 Variable Domains
* **Secret Domain ($\mathcal{S}$):** 32-bit signed symbolic integer ($[-2^{31}, 2^{31}-1]$).
* **Public Input Domain ($\mathcal{P}$):** 32-bit signed symbolic integer.
* **Leakage Range:** Discrete integer in $[0, N_{\text{assert}}]$ (typically $0, 2, 3$, or $4$).

### 13.3 Concrete Numerical Example
In `P000004` (`implicit_flow`):
* Miter places 3 assertions comparing execution 1 and 2:
  1. `assert(glob_implicit_4_1 == glob_implicit_4_2);`
  2. `assert(outcome_1 == outcome_2);`
  3. `assert(flag_1 == flag_2);`
* CBMC proves that for $\text{sec\_pw\_1} = 150$ and $\text{sec\_pw\_2} = 50$, all three assertions fail.
* **`actual_mqil_leakage = 3`**, **`actual_mqil_assertions_total = 3`**.

---

# 14. Dataset Assembly

### 14.1 Assembly Logic
* **File:** `src/pipeline.py` (functions `run_stage1_smoke`, `run_stage2_pipeline`, `run_stage3_scaling`)
* **Join Key:** `program_id` (`P000001` through `P001000`)
* **Metadata Joined:** `program_id`, `family_id`, `source_file`, `miter_file`, `all_inputs`, `high_inputs`, `low_inputs`, `sha256`.
* **Feature Dictionaries Joined:** Group A (Source AST), Group B (Miter AST), Group C Ratios.
* **Target Joined:** `actual_mqil_leakage`, `actual_mqil_assertions_total`.

### 14.2 Data Integrity & Validation
* **Sorting:** Records are sorted deterministically by `program_id`.
* **Missing Values:** Zero NaNs permitted; validated by automated regression tests.
* **Output Path:** `datasets/<stage_name>/dataset.csv`.

---

# 15. CSV Files Produced

| CSV Name | Path | Purpose | Producer | Consumer | Important Columns |
|---|---|---|---|---|---|
| `stage1_smoke/dataset.csv` | `datasets/stage1_smoke/dataset.csv` | Smoke test / 12 canonical programs baseline | `run_stage1_smoke()` | Automated CI tests (`pytest`) | `program_id`, `loc`, `actual_mqil_leakage` |
| `stage2_pipeline/dataset.csv` | `datasets/stage2_pipeline/dataset.csv` | Pipeline validation / 50 diverse programs | `run_stage2_pipeline()` | Feature variance audits | `sha256`, `taint_ratio`, `actual_mqil_leakage` |
| `stage3_scaling/dataset.csv` | `datasets/stage3_scaling/dataset.csv` | **Primary Machine Learning Dataset (1,000 rows)** | `run_stage3_scaling()` | Supervised ML models (`src/models/`) | All 22 features, `actual_mqil_leakage` |
| `dataset.csv` (Root) | `dataset.csv` | Root workspace reference copy (50 rows) | Pipeline export | Ad-hoc manual verification | All 22 features, `actual_mqil_leakage` |

---

# 16. One Complete Example Trace: `P000004` (Implicit Flow)

### 16.1 Original Source C Program (`datasets/stage1_smoke/programs/P000004.c`)
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_implicit_4 = 0;

int branch_kernel_4(int secret, int pub_id) {
    int flag = 0;
    if (secret > 100) {
        flag = 1;
    } else {
        flag = 2;
    }
    return flag + pub_id;
}

int main()
{
    int sec_pw;
    int pub_user;
    int outcome;
    outcome = branch_kernel_4(sec_pw, pub_user);
    glob_implicit_4 = outcome;
    return 0;
}
```

### 16.2 Source AST & Group A Features
* Parsing `P000004.c` produces:
  * `loc`: **26**
  * `num_instructions`: **8**
  * `num_branches`: **1** (`if (secret > 100)`)
  * `num_loops`: **0**
  * `num_functions`: **2** (`branch_kernel_4`, `main`)
  * `num_variables`: **7** (`glob_implicit_4`, `secret`, `pub_id`, `flag`, `sec_pw`, `pub_user`, `outcome`)
  * `num_arrays`: **0**, `num_structure`: **0**, `num_union`: **0**

### 16.3 Miter Transformation (`datasets/stage1_smoke/miters/P000004_miter.c`)
* Helper duplicated: `branch_kernel_4_1`, `branch_kernel_4_2`.
* Public assumption injected: `__CPROVER_assume(pub_user_1 == pub_user_2);`
* Equivalence assertions injected:
  * `assert(glob_implicit_4_1 == glob_implicit_4_2);`
  * `assert(outcome_1 == outcome_2);`
  * `assert(flag_1 == flag_2);`

### 16.4 Miter AST & Group B Features
* Seeds: `sec_pw_1`, `sec_pw_2`.
* Fixpoint propagation taints formal parameters `secret_1`, `secret_2`.
* Branch condition `if (secret > 100)` is secret-dependent $\rightarrow$ `num_culprit_blocks = 3`.
* Statements inside branch bodies $\rightarrow$ `num_implicit_flows = 6`.
* Secret branch ratio $\rightarrow$ `secret_branch_ratio = 1.0` (100% of branches depend on secret).

### 16.5 CBMC Verification
* Solves miter with `--unwind 5`.
* CBMC proves all 3 equivalence assertions fail.
* `actual_mqil_leakage = 3`, `actual_mqil_assertions_total = 3`.

### 16.6 Resulting Row in `dataset.csv`
```csv
P000004,implicit_flow,datasets\stage1_smoke\programs\P000004.c,datasets\stage1_smoke\miters\P000004_miter.c,"sec_pw,pub_user",sec_pw,pub_user,26,8,1,0,2,7,0,0,0,1,1,4,3,6,4,0,2,3,0,0.2222,1.0,0.0,3,3
```

---

# 17. Configuration and Metadata

| File Path | Format | Parameter | Meaning / Effect on Pipeline |
|---|---|---|---|
| `datasets/<stage>/configs/P*.json` | JSON | `input_vars`, `high_vars`, `low_vars` | Specifies which symbolic variables are sensitive secrets vs public inputs. |
| `datasets/<stage>/splits/grouped_splits.json` | JSON | `train_indices`, `val_indices`, `test_indices` | Partitions programs strictly by family (7 train, 1 val, 2 test) to evaluate ML generalization. |
| `datasets/<stage>/MANIFEST.json` | JSON | `cbmc_version`, `cbmc_flags`, `sha256_dataset_csv` | Stores cryptographic SHA-256 hash and toolchain versions to guarantee reproducibility. |
| `pytest.ini` | INI | `testpaths = tests`, `filterwarnings` | Controls automated test discovery and execution. |

---

# 18. Dependencies

| Dependency | Purpose | Used By | Version |
|---|---|---|---|
| `python` | Pipeline execution environment | Entire codebase | 3.10+ (tested on 3.14) |
| `pycparser` | C99 AST parsing and code generation | `src/core/feature_extractor.py`, `tools/cbmc_mqil/` | 3.00 |
| `CBMC` | Bounded model checker (SAT/SMT solver) | `src/core/cbmc_runner.py` | 6.6.0 (via Ubuntu WSL) |
| `pandas` | Tabular data manipulation and CSV export | `src/pipeline.py` | $\ge 2.0.0$ |
| `scikit-learn` | Supervised regression models & metrics | `src/models/train.py`, `evaluate.py` | $\ge 1.3.0$ |
| `pytest` | Automated pipeline regression tests | `tests/` | $\ge 8.0.0$ |
| `fake_libc` | Standard library header stubs | Preprocessor for `pycparser` | Built-in (`tools/fake_libc`) |

---

# 19. Execution Instructions

```powershell
# Command 1: Run Stage 1 Canonical Baseline (12 programs)
# Input: src/generator/program_templates.py
# Output: datasets/stage1_smoke/dataset.csv
python main.py --stage 1

# Command 2: Run Stage 2 Pipeline Validation (50 programs)
# Input: 10 families parametric templates
# Output: datasets/stage2_pipeline/dataset.csv, grouped_splits.json
python main.py --stage 2

# Command 3: Run Stage 3 Benchmark Scaling (1,000 programs across 8 threads)
# Input: 10 families parametric scaling
# Output: datasets/stage3_scaling/dataset.csv, grouped_splits.json, MANIFEST.json
python main.py --stage 3

# Command 4: Train Supervised Machine Learning Regressors
# Input: datasets/stage3_scaling/dataset.csv
# Output: Trained Ridge, RF, SVR, MLP, and GBDT models in results/models/
python main.py --train

# Command 5: Run 4-Tier Feature Ablation Study
# Input: Feature subsets (Group A, Group B, Group C, Full)
# Output: Model ablation performance metrics in results/reports/
python main.py --evaluate

# Command 6: Run Automated Regression Verification Tests
# Input: Entire pipeline test suite
# Output: 21 passing test assertions
pytest tests/
```

---

# 20. Current vs. Legacy Code

### 20.1 Currently Used
* `main.py`: Active master CLI driver.
* `src/pipeline.py`: Active unified pipeline orchestrator for Stages 1, 2, 3, and ML workflows.
* `src/generator/program_templates.py`: Active canonical kernels and whole-program formatter.
* `src/generator/synthesizer.py`: Active parametric benchmark synthesizer and deduplicator.
* `src/core/transpiler.py`: Active subprocess bridge to the miter transpiler.
* `src/core/feature_extractor.py`: Active 22-feature AST visitor and fixpoint taint propagation engine.
* `src/core/cbmc_runner.py`: Active CBMC execution engine and assertion regex parser.
* `tools/cbmc_mqil/src/main.py`: Active official self-composition miter AST generator.
* `datasets/stage1_smoke/`, `stage2_pipeline/`, `stage3_scaling/`: Active benchmark datasets.

### 20.2 Legacy / Possibly Unused
* `archive/legacy_chatgpt_archive/`: Historical prototype scripts from earlier development.
* `tools/cbmc_mqil/src/modules/FuncCopy2.py`: Deprecated AST visitor replaced by `FuncDefHandler2.py`.
* `scratch/`: One-off scratch scripts (`verify_all_cells.py`, `regenerate_all_with_headers.py`, `test_headers.py`).
* `dataset.csv` (Workspace Root): Static 50-row export superseded by versioned stage datasets.

---

# 21. Dependency / Call Graph

```text
main.py
│
└── src/pipeline.py
    │
    ├── src/generator/synthesizer.py
    │   └── src/generator/program_templates.py
    │       └── format_whole_c_program()
    │           ├── Output: datasets/<stage>/programs/P*.c
    │           └── Output: datasets/<stage>/configs/P*.json
    │
    ├── src/core/transpiler.py
    │   └── tools/cbmc_mqil/src/main.py
    │       ├── modules/FuncDefHandler2.py
    │       ├── modules/Renamer.py
    │       ├── modules/AddAssumeCalls.py
    │       ├── modules/AddAssertCalls.py
    │       └── modules/AddNonDetCalls.py
    │           └── Output: datasets/<stage>/miters/P*_miter.c
    │
    ├── src/core/cbmc_runner.py
    │   ├── Subprocess: wsl -d Ubuntu cbmc ... --unwind 5
    │   └── Regex: [*.assertion.*]
    │       └── Output: actual_mqil_leakage (#leak)
    │
    ├── src/core/feature_extractor.py
    │   ├── parse_c_ast() [via pycparser + tools/fake_libc/]
    │   ├── extract_group_a_features() [SourceStructureVisitor on Source AST]
    │   ├── extract_group_b_features() [TaintPropagator on Miter AST]
    │   └── extract_all_mqil_features() [Normalized Ratios: taint_ratio, etc.]
    │
    └── Dataset Assembly & Split Generation
        ├── datasets/<stage>/dataset.csv
        ├── datasets/<stage>/splits/grouped_splits.json
        └── datasets/<stage>/MANIFEST.json
```

---

# 22. Consolidated Feature Dictionary

| # | Feature Name | Type | Meaning | Source | Extraction Method | Dataset Role |
|---|---|---|---|---|---|---|
| 1 | `loc` | Structural | Total lines of source code | Source C File | Text line split | Feature ($X$) |
| 2 | `num_instructions` | Structural | Executable instructions | Source AST | `Assignment`, `FuncCall`, `If`, `Return` | Feature ($X$) |
| 3 | `num_branches` | Structural | Decision branch points | Source AST | `If`, `Switch`, `For`, `While`, `DoWhile` | Feature ($X$) |
| 4 | `num_loops` | Structural | Iteration loops | Source AST | `For`, `While`, `DoWhile` | Feature ($X$) |
| 5 | `num_functions` | Structural | Function definitions | Source AST | `FuncDef` count | Feature ($X$) |
| 6 | `num_variables` | Structural | Variables declared (Rule D8) | Source AST | Filtered `Decl` (globals, locals, params) | Feature ($X$) |
| 7 | `num_arrays` | Structural | Array variable declarations | Source AST | `Decl` wrapping `ArrayDecl` | Feature ($X$) |
| 8 | `num_structure` | Structural | Struct definitions & instances | Source AST | `Decl` wrapping `Struct` | Feature ($X$) |
| 9 | `num_union` | Structural | Union definitions & instances | Source AST | `Decl` wrapping `Union` | Feature ($X$) |
| 10| `num_high_inputs` | Security | Confidential secret inputs | Config JSON | `len(meta["high_vars"])` | Feature ($X$) |
| 11| `num_low_inputs` | Security | Public observable inputs | Config JSON | `len(meta["low_vars"])` | Feature ($X$) |
| 12| `num_explicit_flows` | Security | Secret-dependent assignments | Miter AST | Taint propagation to LHS | Feature ($X$) |
| 13| `num_culprit_blocks` | Security | Secret-dependent branches | Miter AST | Condition predicate depends on secret | Feature ($X$) |
| 14| `num_implicit_flows` | Security | Statements in culprit blocks | Miter AST | Rule D3 statement counting | Feature ($X$) |
| 15| `num_information_leak` | Security | Clean variables tainted | Miter AST | Rule C3 clean variable set | Feature ($X$) |
| 16| `num_secret_dependent_prints` | Security | Prints outputting secrets | Miter AST | Print calls with tainted arguments | Feature ($X$) |
| 17| `num_assumptions` | Security | Public input equality checks | Miter AST | Calls to `__CPROVER_assume` | Feature ($X$) |
| 18| `num_assertions` | Security | Equivalence assertions checked | Miter AST | Calls to `assert` | Feature ($X$) |
| 19| `num_array_accesses` | Security | Array subscript operations | Miter AST | `ArrayRef` node count | Feature ($X$) |
| 20| `taint_ratio` | Security Ratio | Proportion of tainted variables | Miter AST | `num_information_leak / miter_variables` | Feature ($X_{20}$) |
| 21| `secret_branch_ratio`| Security Ratio | Proportion of tainted branches | Miter AST | `num_culprit_blocks / miter_branches` | Feature ($X_{21}$) |
| 22| `secret_memory_ratio`| Security Ratio | Secret-indexed memory access | Miter AST | Secret indices / total array accesses | Feature ($X_{22}$) |
| 23| `loop_to_unwind_ratio`| Structural Ratio | Loop bound to CBMC unwind ratio | Source AST | `max_loop_bound / 5.0` | Feature ($X_{23}$) |
| 24| `num_tainted_returns`| Security Flow | Returns outputting secret data | Miter AST | `Return.expr` contains tainted vars | Feature ($X_{24}$) |
| 25| `num_tainted_globals`| Security Flow | Global variables tainted by secret | Miter AST | Unique tainted base global variables | Feature ($X_{25}$) |
| 26| `max_taint_depth`| Security Graph | Longest dependency chain from secret | Miter AST | Longest acyclic path in taint dep graph | Feature ($X_{26}$) |
| 27| `num_secret_bitops`| Security Op | Bitwise operations on secret data | Miter AST | Bitwise ops (`>>`, `&`, `^`, etc.) on secrets | Feature ($X_{27}$) |
| 28| `actual_mqil_leakage`| **Target** | **Quantitative information leakage** | **CBMC Solver** | **Failed equivalence assertions count** | **Target ($y$)** |
| 29| `leakage_value`| Target Alias | Normalized / alias leakage target | CBMC Solver | Scaled / mapped leakage value | Target ($y$) |
| 30| `actual_mqil_assertions_total`| Metadata | Total assertions verified | CBMC Solver | Total equivalence assertions count | Auxiliary |

---

# 23. Important Design Decisions

1. **Why AST Is Used:** Raw text or tokens cannot capture compiler-level semantics, scope rules, or data dependencies. The Abstract Syntax Tree represents code as an in-memory hierarchical structure, enabling formal taint tracking and AST pattern matching.
2. **Why Structural Features Are Used (Group A):** Structural features establish baseline program complexity. They test whether machine learning models can predict security properties from code structure alone (which ablation studies show has poor $R^2$, proving security is semantic).
3. **Why Miter Programs Are Used:** Checking non-interference requires evaluating two executions ($P_1, P_2$). A miter (self-composition product program) reduces a 2-safety hyperproperty to a standard 1-safety verification problem that tools like CBMC can solve.
4. **Why Security Features Are Measured on the Miter:** The miter AST contains both suffixed executions (`_1` and `_2`) and formal verification primitives (`__CPROVER_assume`, `assert`), allowing precise measurement of data divergence and culprit branches.
5. **Why CBMC Is Used:** Formal verification via CBMC provides mathematical ground truth based on SAT/SMT solving. Unlike dynamic fuzzing or statistical sampling, CBMC exhaustively proves whether assertions hold across all symbolic inputs.
6. **Why Generated Micro-Benchmarks Are Used:** Generating programs across 10 controlled families isolates specific security mechanisms (e.g., bitmasking vs control-flow branching) and prevents confounding variables.
7. **Why Small Lines of Code (~20–25 LOC):** Small programs keep CBMC verification fast ($< 0.4$s per file), avoiding state-space explosion and enabling the creation of 1,000 formally verified benchmarks in under 4 minutes.
8. **Why Holding LOC Uniform Benefits ML Training:** If leaky programs had more lines of code than safe programs, ML models would take shortcuts and learn "more lines = more leakage." Holding LOC constant forces the model to rely on semantic taint flow features ($X$).
9. **Why Regression Is Appropriate:** Information leakage is quantitative ($0, 1, 2, 3\dots$ leaked bits). Regression predicts the exact magnitude of leaked information, providing richer security insights than binary classification.

---

# 24. Assumptions and Limitations

### 24.1 Assumptions
1. **Symbolic Integer Domain:** Input variables default to 32-bit signed symbolic integers.
2. **Bounded Loop Trip Counts:** Loops terminate within the CBMC unwind bound (`--unwind 5`).
3. **Standard C Semantics:** Source programs conform to C99 syntax without proprietary compiler extensions.
4. **Input Transparency:** Sensitive secrets (`high_vars`) and public inputs (`low_vars`) are explicitly designated in companion JSON configurations.

### 24.2 Limitations
1. **Synthetic Benchmark Scope:** The 1,000 scaling programs isolate micro-architectural security patterns; real-world industrial software contains larger call graphs and external libraries.
2. **Solver Unwinding:** Programs with dynamic loop bounds exceeding 5 iterations require higher unwind flags, which increases verification runtime.
3. **Heap & Dynamic Memory:** Bounded model checking models scalar variables, arrays, and structs; dynamic heap allocation (`malloc`/`free`) is constrained.

---

# 25. Professor Questions & Answers

### 1. What is the objective of the project?
**Answer:** To predict quantitative information leakage of C programs in milliseconds using machine learning trained on static structural and information-flow AST features, bypassing expensive formal verification solvers.  
*Reference:* [`main.py:L28-L30`](file:///c:/Users/sujit/OneDrive/Documents/FP/main.py#L28-L30)

### 2. What is information leakage?
**Answer:** Quantitative Information Flow (QIF) measures how many bits of a secret input an attacker can deduce by observing public outputs or program execution.

### 3. Why are we using ML instead of running CBMC directly?
**Answer:** Formal model checking with CBMC suffers from state-space explosion and can take minutes or hours on complex programs. A trained ML model predicts leakage in milliseconds, enabling instant security feedback in CI/CD pipelines.

### 4. Why supervised learning?
**Answer:** We have mathematically proven ground-truth labels for every benchmark program generated by the CBMC bounded model checker.

### 5. Why regression instead of classification?
**Answer:** Information leakage is quantitative (measuring the number of leaked bits or violated equivalence assertions), making regression ($R^2$, MAE) the natural formulation.

### 6. What is an AST?
**Answer:** An Abstract Syntax Tree is an in-memory hierarchical tree representation of source code produced by a compiler parser, where nodes represent functions, expressions, and statements.  
*Reference:* [`src/core/feature_extractor.py:L59-L76`](file:///c:/Users/sujit/OneDrive/Documents/FP/src/core/feature_extractor.py#L59-L76)

### 7. Why not extract features directly from raw text or tokens?
**Answer:** Raw text lacks syntax structure, scope, and data dependencies. ASTs allow rigorous static analysis, such as interprocedural taint tracking and AST pattern matching.

### 8. How are structural features extracted?
**Answer:** By traversing the Source C AST using `SourceStructureVisitor`, which counts statements, loops, branches, functions, and variable declarations.  
*Reference:* [`src/core/feature_extractor.py:L194-L291`](file:///c:/Users/sujit/OneDrive/Documents/FP/src/core/feature_extractor.py#L194-L291)

### 9. What are Group A features?
**Answer:** The 9 structural complexity features (`loc`, `num_instructions`, `num_branches`, `num_loops`, `num_functions`, `num_variables`, `num_arrays`, `num_structure`, `num_union`) measured strictly on the source program (Rule C1).  
*Reference:* [`src/core/feature_extractor.py:L293-L331`](file:///c:/Users/sujit/OneDrive/Documents/FP/src/core/feature_extractor.py#L293-L331)

### 10. What is a miter program?
**Answer:** A 2-safety self-composition product program that executes two parallel copies of the code under identical public inputs to evaluate non-interference.  
*Reference:* [`tools/cbmc_mqil/src/main.py:L57-L107`](file:///c:/Users/sujit/OneDrive/Documents/FP/tools/cbmc_mqil/src/main.py#L57-L107)

### 11. Why do we need a miter?
**Answer:** Information leakage is a 2-safety hyperproperty (relating two execution traces). Self-composition reduces hyperproperties to standard safety properties verifiable by ordinary model checkers.

### 12. How does the miter represent two executions?
**Answer:** Helper functions and variables are cloned with `_1` and `_2` suffixes (e.g., `kernel_1`, `kernel_2`, `key_in_1`, `key_in_2`).

### 13. What is CBMC?
**Answer:** The C Bounded Model Checker—an SMT/SAT-based formal verifier that unrolls loops and exhaustively checks safety assertions.

### 14. Why is CBMC used?
**Answer:** To provide formal mathematical ground-truth labels for information leakage.  
*Reference:* [`src/core/cbmc_runner.py:L21-L103`](file:///c:/Users/sujit/OneDrive/Documents/FP/src/core/cbmc_runner.py#L21-L103)

### 15. Does CBMC calculate information leakage directly?
**Answer:** CBMC evaluates equivalence assertions (`assert(out_1 == out_2)`). The runner parses CBMC's output and counts failed assertions to determine the leakage value.  
*Reference:* [`src/core/cbmc_runner.py:L63-L95`](file:///c:/Users/sujit/OneDrive/Documents/FP/src/core/cbmc_runner.py#L63-L95)

### 16. How is the leakage value calculated?
**Answer:** `actual_mqil_leakage` equals the count of failed equivalence assertions in the miter.

### 17. What does one row of the dataset represent?
**Answer:** One benchmark C program, characterized by its structural features ($X_A$), security features ($X_B$), normalized ratios ($X_C$), and ground-truth leakage label ($y$).

### 18. What are X and y?
**Answer:** $X$ is the complete 29-dimensional feature vector (`FEATURE_COLS`); $y$ is the target integer `actual_mqil_leakage`.

### 19. What is the difference between structural and security features?
**Answer:** Structural features measure syntax complexity on the Source AST (e.g., LOC, loop count); security features measure data dependencies and taint flow on the Miter AST (e.g., culprit blocks, taint ratio).

### 20. How do you verify that extracted features are correct?
**Answer:** Through automated test suites (`pytest tests/`) covering visitor counts, taint fixpoint calculations, and CBMC parser outputs.

### 21. What happens if AST extraction fails?
**Answer:** The parser throws an explicit exception (`RuntimeError` or `ValueError`); silent fallbacks are prohibited by Phase 1 validation rules.  
*Reference:* [`src/core/feature_extractor.py:L340-L375`](file:///c:/Users/sujit/OneDrive/Documents/FP/src/core/feature_extractor.py#L340-L375)

### 22. What happens if CBMC fails or times out?
**Answer:** The runner enforces exit codes `0` and `10`. Non-standard exit codes or timeouts ($>45$s) raise explicit exceptions (`RuntimeError`, `TimeoutError`).  
*Reference:* [`src/core/cbmc_runner.py:L39-L52`](file:///c:/Users/sujit/OneDrive/Documents/FP/src/core/cbmc_runner.py#L39-L52)

### 23. What are the limitations of the dataset?
**Answer:** Programs are synthetic micro-benchmarks with bounded loops ($\le 5$) and small LOC (~20–25) designed to isolate security patterns without solver timeouts.

### 24. How will the trained model be used on a new C program?
**Answer:** Run `extract_all_mqil_features()` on the new program and its companion JSON to generate the 29-feature vector $X$, then pass $X$ to the trained model's `predict()` method to output predicted leakage in milliseconds.  
*Reference:* [`main.py:L58-L61`](file:///c:/Users/sujit/OneDrive/Documents/FP/main.py#L58-L61)

---

# 26. Minimum File Set Required for Understanding

If uploading code to another AI or external reviewer, use this minimal set:

### Essential Files (Core Pipeline)
1. `src/pipeline.py`
   * *Purpose:* Master orchestrator driving synthesis, miter transpilation, CBMC verification, and dataset assembly.
2. `src/core/feature_extractor.py`
   * *Purpose:* Complete 29-feature AST extractor (`FEATURE_COLS`), Rule D8 variable counter, and fixpoint taint analysis engine.
3. `src/core/cbmc_runner.py`
   * *Purpose:* Invokes CBMC (native/WSL) and parses assertion results into ground-truth target labels.
4. `src/core/transpiler.py`
   * *Purpose:* Python bridge driving the self-composition miter transpiler.

### Important Files (Generator & Miter Transpiler)
5. `src/generator/program_templates.py`
   * *Purpose:* Defines the 10 canonical vulnerability families and program templates.
6. `src/generator/synthesizer.py`
   * *Purpose:* Implements parametric program generation and deduplication across 1,000 benchmarks.
7. `tools/cbmc_mqil/src/main.py`
   * *Purpose:* Core AST transformation script that builds 2-safety product programs.

### Optional Files (Context & Verification)
8. `datasets/stage3_scaling/MANIFEST.json`
   * *Purpose:* Documents dataset provenance, toolchain versions, and split distributions.
9. `datasets/stage1_smoke/dataset.csv`
   * *Purpose:* A clean 12-row sample showing the final assembled schema and values.

---

# 27. Final One-Page Summary

* **What is the project?** An ML framework to predict quantitative information leakage in C programs from static AST features in milliseconds, bypassing slow formal verification.
* **What is the input?** C source programs with companion JSON configs defining secret (`high_vars`) and public (`low_vars`) inputs.
* **What is generated?** 1,000 standardized C programs across 10 vulnerability families and their corresponding 2-safety self-composition miter programs.
* **How is AST used?** `pycparser` builds in-memory syntax trees. A visitor extracts structural metrics from the Source AST; an interprocedural taint engine extracts security flow metrics from the Miter AST.
* **What are structural features?** Group A complexity metrics (`loc`, `num_instructions`, `num_branches`, `num_loops`, `num_functions`, `num_variables`, `num_arrays`, `num_structure`, `num_union`) measured on source code.
* **What is a miter?** A product program executing two parallel runs under identical public inputs and unconstrained secrets, asserting output equivalence at exit.
* **What are security features?** Group B metrics (`num_explicit_flows`, `num_culprit_blocks`, `num_implicit_flows`, etc.) tracking data flow and secret-dependent branches.
* **What is CBMC doing?** Bounded model checking on the miter to mathematically prove whether equivalence assertions hold or fail.
* **How is leakage obtained?** Parsed from CBMC results: `actual_mqil_leakage` equals the count of failed equivalence assertions.
* **How is the final CSV created?** `src/pipeline.py` combines metadata, Group A features, Group B features, normalized ratios, disambiguation features, and CBMC labels into `dataset.csv`.
* **What is one row?** One C program with all its extracted features and its ground-truth leakage label.
* **What is X?** The complete 29-dimensional feature vector defined in `FEATURE_COLS`.
* **What is y?** The target integer `actual_mqil_leakage` ($0, 2, 3$, or $4$).
