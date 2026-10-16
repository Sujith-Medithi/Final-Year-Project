# MQIL Feature Dictionary (Feature Parity Specification)

This document specifies the exact counting rules, target files (source vs. miter), pycparser AST node types, filtering rules/exclusions, and worked examples for all 22 feature columns and the target column in the MQIL dataset pipeline.

---

## 0. Frozen Interfaces & Schema

The 22 input feature columns and the target column are frozen in the following exact order:

```
loc, num_instructions, num_branches, num_loops, num_functions, num_variables,
num_arrays, num_structure, num_union, num_high_inputs, num_low_inputs,
num_explicit_flows, num_culprit_blocks, num_implicit_flows, num_information_leak,
num_secret_dependent_prints, num_assumptions, num_assertions, num_array_accesses,
taint_ratio, secret_branch_ratio, secret_memory_ratio, actual_mqil_leakage
```

- Target: `actual_mqil_leakage` (CBMC failed equivalence assertions).
- Auxiliary/Ground-Truth metadata (NOT input features): `actual_mqil_assertions_total`, `mqil_leak_ratio`.

---

## 1. Group A: Program Structure (Measured on Source File)

Group A features capture the syntactic and architectural complexity of the original, un-instrumented C program (`source.c`).
- Measured on: **SOURCE C file** (Decision C1).
- Header exclusions: System and fake-libc header declarations (`stdio.h`, `stdlib.h`, `assert.h`, etc.) are excluded by syntactic rule (Decision C4, D8).

---

### `loc`
- **Measured On**: Source C file
- **Counting Rule**: Total physical line count: `len(source_code.splitlines())`.
- **Exclusions**: None.
- **Node Types**: None (raw text line count).
- **Worked Example (`golden_program2.c`)**: 91 lines $\rightarrow$ `loc = 91`.

---

### `num_instructions`
- **Measured On**: Source C file
- **Counting Rule**: Executable statements in the AST: counts each `c_ast.Assignment`, `c_ast.FuncCall`, `c_ast.If`, and `c_ast.Return`.
  - *Note (K17)*: In expressions such as `x = f();`, both the assignment and the function call are counted (+2).
- **Node Types**: `Assignment`, `FuncCall`, `If`, `Return`.
- **Exclusions**: Header/libc AST nodes (file path matching `fake_libc`).
- **Worked Example (`golden_program2.c`)**: 34 total instructions $\rightarrow$ `num_instructions = 34`.

---

### `num_branches`
- **Measured On**: Source C file
- **Counting Rule (D9, K18)**: Counts all control-flow branching constructs: conditional statements (`If`, `Switch`) as well as iterative loop headers (`For`, `While`, `DoWhile`).
- **Node Types**: `If`, `Switch`, `For`, `While`, `DoWhile`.
- **Exclusions**: Header/libc AST nodes.
- **Worked Example (`golden_program2.c`)**: 2 `if` + 2 `for` + 1 `while` $\rightarrow$ `num_branches = 5`.

---

### `num_loops`
- **Measured On**: Source C file
- **Counting Rule**: Counts all loop structures: `For`, `While`, and `DoWhile`.
- **Node Types**: `For`, `While`, `DoWhile`.
- **Exclusions**: Header/libc AST nodes.
- **Worked Example (`golden_program2.c`)**: 2 `for` + 1 `while` $\rightarrow$ `num_loops = 3`.

---

### `num_functions`
- **Measured On**: Source C file
- **Counting Rule**: Counts user-defined function definitions (`c_ast.FuncDef`).
- **Node Types**: `FuncDef`.
- **Exclusions**: Function prototypes / declarations (`Decl` without definition) and libc headers.
- **Worked Example (`golden_program2.c`)**: `total`, `helper`, `main` $\rightarrow$ `num_functions = 3`.

---

### `num_variables`
- **Measured On**: Source C file
- **Counting Rule (D8, K24)**: Counts `c_ast.Decl` nodes whose type is `TypeDecl`, `ArrayDecl`, or `PtrDecl` that represent:
  1. Global variables
  2. Local variables
  3. Loop-declared variables
  4. Parameters of **function definitions** (`FuncDef`)
  5. Struct and union member declarations
- **Exclusions**:
  - Parameters of function prototypes (`Decl` with `FuncDecl` where no body is defined).
  - Variables declared `extern`.
  - Declarations originating from `tools/fake_libc` headers.
- **Worked Example (`golden_program2.c`)**: Exactly 24 user variables (globals `slots`, `g_attempts`; struct `Account` fields `id`, `balance`, `limit`; union `Reg` fields `word`, `part`; function parameters; and locals). Prototypes and libc declarations are excluded. $\rightarrow$ `num_variables = 24`.

---

### `num_arrays`
- **Measured On**: Source C file
- **Counting Rule**: Counts variable declarations with `ArrayDecl` type (globals, locals, struct/union array fields).
- **Node Types**: `Decl` with `type` instance of `ArrayDecl`.
- **Exclusions**: Header/libc AST nodes.
- **Worked Example (`golden_program2.c`)**: `slots[4]`, `history[4]`, `part[4]` $\rightarrow$ `num_arrays = 3`.

---

### `num_structure`
- **Measured On**: Source C file
- **Counting Rule (D9)**: Counts struct type definitions (`Struct` with declarations) and struct instance declarations (`TypeDecl` with `Struct`).
- **Node Types**: `Struct` (definitions), `Decl` of struct type.
- **Exclusions**: Header/libc AST nodes.
- **Worked Example (`golden_program2.c`)**: `struct Account` definition + `acct` instance $\rightarrow$ `num_structure = 2`.

---

### `num_union`
- **Measured On**: Source C file
- **Counting Rule (D9)**: Counts union type definitions (`Union` with declarations) and union instance declarations (`TypeDecl` with `Union`).
- **Node Types**: `Union` (definitions), `Decl` of union type.
- **Exclusions**: Header/libc AST nodes.
- **Worked Example (`golden_program2.c`)**: `union Reg` definition + `reg` instance $\rightarrow$ `num_union = 2`.

---

## 2. Group B: Security Features (Measured on Miter File & Input Specification)

Group B features track sensitive information flow, security annotations, and equivalence checks.
- Measured on: **MITER C file** (`miter.c`), seeded with high-input variables (`high_vars`) suffixed with `_1` and `_2` (Decision C2).
- Taint Model (D1): Field-insensitive (`acct.limit` taints `acct`), flow-insensitive, iterated to a fixpoint across all functions in the translation unit (including transpiler-generated combined helpers `*_2`).

---

### `num_high_inputs`
- **Measured On**: Input specification (`input_args.json`)
- **Counting Rule**: `len(json["high_vars"])`.
- **Worked Example (`golden_program2.c`)**: `["pin", "seed"]` $\rightarrow$ `num_high_inputs = 2`.

---

### `num_low_inputs`
- **Measured On**: Input specification (`input_args.json`)
- **Counting Rule**: `len(json["low_vars"])`.
- **Worked Example (`golden_program2.c`)**: `["user_id"]` $\rightarrow$ `num_low_inputs = 1`.

---

### `num_explicit_flows`
- **Measured On**: Miter C file
- **Counting Rule (D1, C3)**: Number of assignment and initialized declaration statements where the RHS/initializer expression contains a tainted variable name:
  - `c_ast.Assignment` where RHS contains tainted identifier.
  - `c_ast.Decl` with `init` containing tainted identifier.
  - Lvalue base extraction (K25): Handles `StructRef` (`base.field`) and `ArrayRef` (`base[idx]`) by tainting the root identifier.
  - Formal parameter call-binding (D1): Passing a tainted variable into a function call binds and propagates taint to the function's formal parameter for downstream propagation, but formal parameter binding itself is not counted as an explicit flow statement.
- **Worked Example (`golden_program2.c`)**:
  - `acct_x.limit`, `reg_x.word`, `history_x[...]`, `report_x`, `visible_x` for $x \in \{1, 2\}$ (10 flows)
  - `acc += vals[j]` in `total` (1 flow via parameter binding)
  - `acc_1 += ...`, `acc_2 += ...` in combined helper `total_2` (2 flows via parameter binding)
  - Total $\rightarrow$ `num_explicit_flows = 13`.

---

### `num_culprit_blocks`
- **Measured On**: Miter C file
- **Counting Rule**: Number of conditional branch constructs (`If`, `Switch`, `For`, `While`, `DoWhile`) whose condition expression references at least one tainted variable.
- **Node Types**: Conditional statements with tainted variables in condition AST.
- **Worked Example (`golden_program2.c`)**:
  - `if (pin_1 > 5000)`
  - `if (pin_2 > 5000)`
  - `for (t_1 < seed_1 % 3 && t_2 < seed_2 % 3)`
  - Total $\rightarrow$ `num_culprit_blocks = 3`.

---

### `num_implicit_flows`
- **Measured On**: Miter C file
- **Counting Rule (D3, K19)**: Number of simple statements executing within the body of a culprit block:
  - Statement-level `Assignment`
  - Unary `++` or `--` statements
  - Statement-level `FuncCall`
  - `Return` statements
  - Nested `If` conditions (header counted as 1)
- **Worked Example (`golden_program2.c`)**:
  - Inside `if (pin_x > 5000)`: `status_x = 2`, `g_attempts_x++` for $x \in \{1, 2\}$ (4 statements)
  - Inside `for (t_x < seed_x ...)`: `bonus_x += 5` for $x \in \{1, 2\}$ (2 statements)
  - Total $\rightarrow$ `num_implicit_flows = 6`.

---

### `num_information_leak`
- **Measured On**: Miter C file
- **Counting Rule (C3, D1)**: Total number of previously clean program variables that become tainted via an explicit flow (excluding initial seed variables and excluding formal parameter declarations from call binding).
- **Worked Example (`golden_program2.c`)**:
  - Variables tainted: `acct_1`, `acct_2`, `reg_1`, `reg_2`, `history_1`, `history_2`, `report_1`, `report_2`, `visible_1`, `visible_2`, `acc`, `acc_1`, `acc_2`.
  - Total $\rightarrow$ `num_information_leak = 13`.

---

### `num_secret_dependent_prints`
- **Measured On**: Miter C file
- **Counting Rule (D4)**: Number of function calls named exactly `printf`, `puts`, `putchar`, `fprintf`, `sprintf`, or `snprintf` where any argument expression references a tainted variable.
- **Worked Example (`golden_program2.c`)**:
  - `printf` calls printing `report_1`, `report_2`, `visible_1`, `visible_2`, `history_1[...]`, `history_2[...]`
  - Total $\rightarrow$ `num_secret_dependent_prints = 6`.

---

### `num_assumptions`
- **Measured On**: Miter C file
- **Counting Rule (D5, K22)**: Number of AST `FuncCall` nodes named exactly `__CPROVER_assume`.
- **Worked Example (`golden_program2.c`)**:
  - Low input equality: `__CPROVER_assume(user_id_1 == user_id_2)`
  - High input divergence assumptions: `__CPROVER_assume(pin_1 != pin_2 || seed_1 != seed_2)`
  - Bound assumption on loop index: `__CPROVER_assume(slots_1[0] > 0)`
  - Total $\rightarrow$ `num_assumptions = 3`.

---

### `num_assertions`
- **Measured On**: Miter C file
- **Counting Rule (D5, K22)**: Number of AST `FuncCall` nodes named exactly `assert`.
  - Excludes `assert` function prototypes.
  - Excludes nonexistent or patched `assert_2`.
  - Includes user assertions in both program copies and miter-injected equivalence assertions.
- **Worked Example (`golden_program2.c`)**:
  - User assertions in copy 1 and copy 2: 2
  - Scalar equivalence assertions: 13
  - Struct `Account` field-by-field assertions (`id`, `balance`, `limit`): 2
  - Union `Reg` member-wise assertions (D7: `word`, `part[i]`): 2
  - Total real `assert()` calls $\rightarrow$ `num_assertions = 19`.

---

### `num_array_accesses`
- **Measured On**: Miter C file
- **Counting Rule (K21)**: Total count of `c_ast.ArrayRef` nodes in the miter AST.
- **Worked Example (`golden_program2.c`)**:
  - All valid array subscript expressions across copy 1, copy 2, helpers, and equivalence loops.
  - Total $\rightarrow$ `num_array_accesses = 23`.

---

## 3. Normalized Ratios (Miter-Side Internal Counters)

Per Decision D2 (K21), all ratios are computed using numerators and denominators measured on the **same file** (the miter) to strictly guarantee that all ratio values lie within $[0.0, 1.0]$:

### `taint_ratio`
$$\text{taint\_ratio} = \frac{\text{num\_information\_leak}}{\max(V_{\text{miter}}, 1)}$$
- Where $V_{\text{miter}}$ is the total number of variable declarations in the miter AST.
- If $V_{\text{miter}} = 0$, ratio is $0.0$.
- In `golden_program2`: $\frac{13}{54} \approx 0.2407 \in [0, 1]$.

### `secret_branch_ratio`
$$\text{secret\_branch\_ratio} = \frac{\text{num\_culprit\_blocks}}{\max(B_{\text{miter}}, 1)}$$
- Where $B_{\text{miter}}$ is the total number of branch constructs (`If`, `Switch`, `For`, `While`, `DoWhile`) in the miter AST.
- If $B_{\text{miter}} = 0$, ratio is $0.0$.
- In `golden_program2`: $\frac{3}{11} \approx 0.2727 \in [0, 1]$.

### `secret_memory_ratio`
$$\text{secret\_memory\_ratio} = \frac{\text{num\_secret\_indexed\_accesses}}{\max(\text{num\_array\_accesses}, 1)}$$
- Where $\text{num\_secret\_indexed\_accesses}$ is the count of `ArrayRef` nodes whose subscript index expression references a tainted variable, and $\text{num\_array\_accesses}$ is the total miter array access count.
- If $\text{num\_array\_accesses} = 0$, ratio is $0.0$.
- In `golden_program2`: $\frac{2}{23} \approx 0.0870 \in [0, 1]$.

---

## 4. Ground Truth Target Labels

- `actual_mqil_leakage`: Number of failed equivalence assertions reported by CBMC 6.6.0 (`[assertion.X] ... FAILURE`).
- `actual_mqil_assertions_total`: Total number of equivalence assertions verified by CBMC.
- `mqil_leak_ratio`: $\frac{\text{actual\_mqil\_leakage}}{\max(\text{actual\_mqil\_assertions\_total}, 1)}$.
