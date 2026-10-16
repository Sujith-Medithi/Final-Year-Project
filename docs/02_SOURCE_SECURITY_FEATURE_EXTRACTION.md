# Phase 2 --- Whole-Program Security & Structural Feature Extraction
**Responsible Role**: Person 1 (Data Engineering & Program Analysis)

---

## 1. Objective

Extract all 21 structural and security features directly from C source code and the generated miter program using Abstract Syntax Tree (AST) parsing with `pycparser`.

Features are strictly partitioned into the two groups specified in the **MQIL Reference Specification**:
* **Group A**: Program Structure (*measured at the miter version / Refer MQIL Paper Table I & II*).
* **Group B**: Security Features (*measured across the whole program*).
* **Normalized Ratios**: Scale-invariant ratios.

---

## 2. Group A — Program Structure (at Miter Version)

> **Key Rule from Handwritten Reference**: Group A features are measured on the **generated miter program (`output.c`)**, exactly reflecting the characteristics analyzed by CBMC (as shown in Table I & II of the MQIL paper).

| Feature Name | Type | Description |
| :--- | :--- | :--- |
| `loc` | Integer | Total physical lines of code in the entire generated miter file. |
| `num_instructions` | Integer | Total executable C statements across all functions and `main()`. |
| `num_branches` | Integer | Total control branches (`if`, `switch`, ternary conditionals) in the miter. |
| `num_loops` | Integer | Total loop constructs (`for`, `while`, `do-while`) in the miter. |
| `num_functions` | Integer | Total function definitions declared/defined in the miter. |
| `num_variables` | Integer | Total scalar, pointer, and local variables declared across the miter. |
| `num_arrays` | Integer | Total array buffers declared in the miter. |
| `num_structure` | Integer | Total `struct` definitions and struct variable instances. |
| `num_union` | Integer | Total `union` definitions and union variable instances. |

---

## 3. Group B — Security Features (Whole Program)

These features track data-flow and control-dependence flows originating from sensitive inputs ($h \in H$) through the program:

| Feature Name | Type | Extraction Mechanism & Semantic Meaning |
| :--- | :--- | :--- |
| `num_high_inputs` | Integer | Count of sensitive inputs ($|H|$) specified in `input_args.json`. |
| `num_low_inputs` | Integer | Count of public inputs ($|L|$) specified in `input_args.json`. |
| `num_explicit_flows` | Integer | Count of statements where a tainted sensitive variable directly taints an expression (data-flow tracking). |
| `num_culprit_blocks` | Integer | Count of branch conditions (`if`, `switch`) whose predicate expression depends on sensitive data. |
| `num_implicit_flows` | Integer | Count of statements executed conditionally inside a culprit block (control-dependence flow). |
| `num_information_leak`| Integer | Count of paths where tainted data reaches observable output variables or return values. |
| `num_secret_dependent_prints` | Integer | Print/I/O statements with tainted arguments (`printf("%d", key)`). |
| `num_assumptions` | Integer | Number of assumptions injected into the miter (`__CPROVER_assume(h1 != h2)`). |
| `num_assertions` | Integer | Total equivalence assertions injected into the miter (`assert(v1 == v2)`). |
| `num_array_accesses` | Integer | Memory accesses with secret-dependent index expressions (e.g. $x = \text{secret} \ \& \ y; \ z = \text{array}[x]$). |

---

## 4. Normalized Ratios (Scale-Invariant Indicators)

To ensure machine learning models generalize seamlessly to large programs (kLOC) without bias from raw line counts, we compute three normalized ratios:

### 1. Taint Ratio
$$\text{taint\_ratio} = \frac{\text{num\_information\_leak}}{\max(\text{num\_variables}, 1)}$$
*(Also recorded relative to assertions: $\frac{\text{num\_information\_leak}}{\max(\text{num\_assertions}, 1)}$)*. Measures the fraction of the program's variable space that leaks secrets.

### 2. Secret Branch Ratio
$$\text{secret\_branch\_ratio} = \frac{\text{num\_culprit\_blocks}}{\max(\text{num\_branches}, 1)}$$
Measures the proportion of control-flow branches vulnerable to timing / side-channel attacks.

### 3. Secret Memory Ratio
$$\text{secret\_memory\_ratio} = \frac{\text{num\_arrays}}{\max(\text{num\_array\_accesses}, 1)}$$
Measures the ratio of total memory buffers to secret-dependent indexing access operations.

---

## 5. Person 1 Deliverable Checkpoint

Person 1 produces:
* `mqil_ml/core/feature_extractor.py`: Automated extractor processing the C program and miter output.
* Output dictionary containing all 21 features for every benchmark in the dataset.
