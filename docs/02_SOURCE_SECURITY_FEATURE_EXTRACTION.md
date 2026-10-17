# Phase 2 --- Whole-Program Security & Structural Feature Extraction
**Responsible Role**: Person 1 (Data Engineering & Program Analysis)

---

## 1. Objective

Extract all 27 structural, security, and flow features directly from C source code and the generated miter program using Abstract Syntax Tree (AST) parsing with `pycparser`.

Features are strictly partitioned into three groups based on the **MQIL Reference Specification & Parity Architecture**:
* **Group A**: Program Structure (**10 features**, measured on the un-instrumented C source file).
* **Group B**: Security & Taint Flow Features (**14 features**, measured on the generated miter C file and input specification).
* **Group C**: Normalized Security Ratios (**3 features**, scale-invariant ratios measured on internal miter counters).

**Total Feature Count**: $10 + 14 + 3 = 27\text{ features}$.

---

## 2. Group A — Program Structure (Measured on Source File)

> **Measurement Rule (Decision C1)**: Group A features capture the syntactic and architectural complexity of the original, un-instrumented C program (`source.c`). System and libc header declarations (`fake_libc`) are excluded by syntactic rule (Decision C4, D8).

| Feature Name | Type | Description |
| :--- | :--- | :--- |
| `loc` | Integer | Total physical lines of code in the source file (`len(source.splitlines())`). |
| `num_instructions` | Integer | Total executable C statements in source AST (`Assignment`, `FuncCall`, `If`, `Return`). |
| `num_branches` | Integer | Total control branches (`If`, `Switch`, `For`, `While`, `DoWhile`) in source AST. |
| `num_loops` | Integer | Total loop constructs (`For`, `While`, `DoWhile`) in source AST. |
| `num_functions` | Integer | Total user-defined function definitions (`FuncDef`) excluding prototypes and libc. |
| `num_variables` | Integer | Total user variable declarations (globals, locals, struct/union members, func params). |
| `num_arrays` | Integer | Total array declarations (`ArrayDecl`) across globals, locals, and struct/union fields. |
| `num_structure` | Integer | Total `struct` definitions and struct variable instance declarations. |
| `num_union` | Integer | Total `union` definitions and union variable instance declarations. |
| `loop_to_unwind_ratio` | Float | Ratio of maximum detected loop upper bound constant to CBMC unwind depth: $\text{bound} / 5.0$. |

---

## 3. Group B — Security & Taint Flow Features (Measured on Miter & Inputs)

> **Measurement Rule (Decision C2, C3)**: Group B features track sensitive information flow, taint propagation, bitwise side-channels, and equivalence checks on the generated **miter program (`miter.c`)**, seeded with high-input variables (`high_vars`) suffixed with `_1` and `_2`.

| Feature Name | Type | Extraction Mechanism & Semantic Meaning |
| :--- | :--- | :--- |
| `num_high_inputs` | Integer | Count of sensitive secret inputs ($|H|$) specified in `input_args.json`. |
| `num_low_inputs` | Integer | Count of public inputs ($|L|$) specified in `input_args.json`. |
| `num_explicit_flows` | Integer | Statements where a tainted variable directly taints an expression (data-flow tracking). |
| `num_culprit_blocks` | Integer | Branch constructs (`If`, `Switch`, `For`, `While`, `DoWhile`) whose condition depends on secret data. |
| `num_implicit_flows` | Integer | Simple statements executed conditionally inside culprit blocks (control-dependence flow). |
| `num_information_leak` | Integer | Previously clean variables that become tainted via explicit sensitive data flows. |
| `num_secret_dependent_prints` | Integer | Print/I/O calls (`printf`, `puts`, `sprintf`, etc.) with tainted argument expressions. |
| `num_assumptions` | Integer | Assumptions injected into the miter (`__CPROVER_assume(...)`). |
| `num_assertions` | Integer | Equivalence check assertions injected into the miter (`assert(...)`). |
| `num_array_accesses` | Integer | Total array subscript accesses (`ArrayRef`) evaluated across the miter AST. |
| `num_tainted_returns` | Integer | Return statements where the returned expression evaluates sensitive tainted data. |
| `num_tainted_globals` | Integer | Unique global variables that become tainted through execution. |
| `max_taint_depth` | Integer | Maximum acyclic taint propagation chain length from secret seeds in the dependency graph. |
| `num_secret_bitops` | Integer | Bitwise operations (`>>`, `<<`, `&`, `|`, `^`) operating on tainted operands. |

---

## 4. Group C — Normalized Security Ratios (Scale-Invariant Indicators)

> **Measurement Rule (Decision D2, K21)**: All ratios are computed strictly using numerators and denominators measured on the **same file** (internal miter counters) to guarantee that all ratio values lie within $[0.0, 1.0]$.

### 1. Taint Ratio
$$\text{taint\_ratio} = \frac{\text{num\_information\_leak}}{\max(V_{\text{miter}}, 1)}$$
Measures the proportion of the miter variable space ($V_{\text{miter}}$) tainted by secret inputs.

### 2. Secret Branch Ratio
$$\text{secret\_branch\_ratio} = \frac{\text{num\_culprit\_blocks}}{\max(B_{\text{miter}}, 1)}$$
Measures the proportion of control-flow branches ($B_{\text{miter}}$) vulnerable to timing/control leakage.

### 3. Secret Memory Ratio
$$\text{secret\_memory\_ratio} = \frac{\text{num\_secret\_indexed\_accesses}}{\max(\text{num\_array\_accesses}, 1)}$$
Measures the fraction of array accesses indexed by secret-dependent expressions (cache-timing vulnerability).

---

## 5. Person 1 Deliverable Checkpoint

Person 1 produces:
* `src/core/feature_extractor.py`: Automated extractor processing the C program and miter output.
* Output dictionary containing all **27 features** for every benchmark in the dataset.
