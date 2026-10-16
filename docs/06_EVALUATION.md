# Phase 6 --- Model Evaluation, Cross-Validation, and Feature Ablation Studies
**Responsible Role**: Person 2 (Machine Learning Evaluation)

---

## 1. Objective

Evaluate trained models on unseen test families and perform a rigorous **Feature Ablation Study** to quantify the predictive contribution of each feature group from the handwritten specification sheet.

---

## 2. Evaluation Metrics

Model performance is measured on the test set ($y_{\text{true}} = \text{actual\_mqil\_leakage}$, $\hat{y} = \text{predicted\_leakage}$):

1. **Mean Absolute Error (MAE)**:
   $$\text{MAE} = \frac{1}{N} \sum_{i=1}^N |y_i - \hat{y}_i|$$
   Average deviation in predicted failed assertions.

2. **Root Mean Squared Error (RMSE)**:
   $$\text{RMSE} = \sqrt{\frac{1}{N} \sum_{i=1}^N (y_i - \hat{y}_i)^2}$$
   Penalizes large outlier errors heavily.

3. **Coefficient of Determination ($R^2$)**:
   $$R^2 = 1 - \frac{\sum (y_i - \hat{y}_i)^2}{\sum (y_i - \bar{y})^2}$$
   Proportion of variance in information leakage explained by the model.

---

## 3. Feature Ablation Study

To confirm the research hypothesis that **security and taint features are fundamentally necessary** to predict information leakage, Person 2 trains and compares models across 4 distinct feature subsets:

| Feature Subset | Features Included | Scientific Hypothesis |
| :--- | :--- | :--- |
| **Set 1: Structural Only (Group A)** | `loc`, `num_instructions`, `num_branches`, `num_loops`, `num_functions`, `num_variables`, `num_arrays`, `num_structure`, `num_union` | *Expected Low $R^2$*: Code size alone cannot determine whether code leaks secrets or operates on public data. |
| **Set 2: Security Features Only (Group B)** | `num_high_inputs`, `num_low_inputs`, `num_explicit_flows`, `num_culprit_blocks`, `num_implicit_flows`, `num_information_leak`, `num_assumptions`, `num_assertions`, `num_array_accesses` | *Expected High $R^2$*: Taint and dependency tracking capture actual leakage pathways directly. |
| **Set 3: Normalized Ratios Only** | `taint_ratio`, `secret_branch_ratio`, `secret_memory_ratio` | *Compact Baseline*: Scale-invariant summary of program vulnerability. |
| **Set 4: Full Feature Set (All Features)** | Group A + Group B + Normalized Ratios | *Optimal Performance*: Combines structural complexity with precise security flow semantics. |

---

## 4. Person 2 Deliverable Checkpoint

Person 2 produces:
* `mqil_ml/models/evaluate.py`: Evaluation script computing metrics and running automated ablation.
* Comprehensive performance table comparing all 5 models and 4 feature sets.
