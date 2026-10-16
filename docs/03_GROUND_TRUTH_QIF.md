# Phase 3 --- Ground-Truth Quantification via MQIL & CBMC Model Checking
**Responsible Role**: Person 1 (Data Engineering & Formal Verification)

---

## 1. Objective

Establish exact, reproducible ground-truth labels for quantitative information leakage (`#leak`) using the formal methodology described in the IEEE MQIL research paper:

> *Reference: P. Panigrahi and C. Karfa, "MQIL: Model Checking based Quantification of Information Leakage", IEEE Embedded Systems Letters, 2026.*

All toy Shannon mutual information enumeration with 16 hardcoded inputs is eliminated. The ground truth is computed via **self-composition miter generation and Bounded Model Checking with CBMC**.

---

## 2. Theoretical Foundation: Over-Tainting vs. Under-Tainting

Static taint analysis is widely used for tracking sensitive information flow, but suffers from two critical flaws:
1. **Under-tainting (False Negatives)**: Misses implicit flows where secret decisions control which conditional branch executes.
2. **Over-tainting (False Positives)**: If an analyzer flags all variables inside a secret-dependent branch as tainted, it produces false positives when parallel branches compute identical symbolic expressions (e.g. `b = x - y;` in both `if` and `else`).

**MQIL solves both problems** by reducing the quantification problem to a set of user-specified assertion verifications on a **miter program** verified by **CBMC**.

---

## 3. The MQIL Miter Transformation ($P_1 \times P_2$)

Given an entire C program $P(H, L, V, O)$, the tool [`cbmc-main/cbmc-main/src/main.py`](file:///c:/Users/sujit/OneDrive/Documents/FP/cbmc-main/cbmc-main/src/main.py) constructs two copies at the AST level:
$$P_1(H_1, L, V_1, O_1) \quad \text{and} \quad P_2(H_2, L, V_2, O_2)$$

### Key Construction Rules
1. **Low Inputs Shared**: Public inputs $L$ are shared and not duplicated.
2. **High Inputs Duplicated**: For each sensitive input $h \in H$, two symbolic copies $h_1, h_2$ are created.
3. **Assumptions on High Inputs**:
   ```c
   __CPROVER_assume(h1 != h2);
   ```
4. **Internal Variables & Outputs Duplicated**: Each variable $v \in V \cup O$ is duplicated into $v_1 \in V_1$ and $v_2 \in V_2$.
5. **Assertions Injected**: For all variables across all functions and `main()`:
   ```c
   assert(v1 == v2);
   assert(out1 == out2);
   ```

If sensitive input $h$ does **not** affect variable $v$, then $v_1 == v_2$ holds across all execution paths and the assertion **passes** (SUCCESS). If $h$ influences $v$ (either explicitly or implicitly), CBMC finds a counterexample and the assertion **fails** (FAILURE).

---

## 4. CBMC Execution & Tool Integration

The pipeline executes the official MQIL transpiler and CBMC:

```bash
# 1. Generate miter program output.c
python cbmc-main/cbmc-main/src/main.py benchmark.c input_args.json

# 2. Run CBMC with bounded loop unwinding
cbmc output.c --unwind 5
```

### Parsing CBMC Output
CBMC outputs per-assertion status:
```text
[fn_2.assertion.1] line 15 assertion y_1 == y_2: FAILURE
[fn_2.assertion.2] line 16 assertion z_1 == z_2: FAILURE
[main.assertion.1] line 41 assertion v_1 == v_2: FAILURE
** 3 of 3 failed
VERIFICATION FAILED
```

The pipeline extracts:
* **`actual_mqil_leakage` (`#leak`)**: Count of failed assertions (here = 3).
* **`actual_mqil_assertions_total`**: Total assertions evaluated (here = 3).
* **`mqil_leak_ratio`**: $\frac{\text{actual\_mqil\_leakage}}{\text{actual\_mqil\_assertions\_total}} = 1.0$.

---

## 5. Person 1 Deliverable Checkpoint

Person 1 produces:
1. Automated CBMC execution runner (`mqil_ml/core/cbmc_runner.py`).
2. Exact `#leak` labels recorded for all benchmarks in `mqil_dataset.csv`.
