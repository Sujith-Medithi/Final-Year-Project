# Phase 7 --- Model Explainability & Interpretability via SHAP
**Responsible Role**: Person 2 (Machine Learning Explainability)

---

## 1. Objective

Provide transparent, mathematically rigorous explanations of how the trained machine learning models make leakage predictions, utilizing **SHAP (SHapley Additive exPlanations)** based on cooperative game theory.

---

## 2. SHAP Analysis Pipeline

Person 2 runs `shap.TreeExplainer` on the best-performing tree-based model (Random Forest or Gradient Boosting / XGBoost):

```python
import shap

explainer = shap.TreeExplainer(best_model)
shap_values = explainer(X_test)
```

---

## 3. Required Interpretability Visualizations

### 1. Global Feature Importance Bar Plot (`shap.plots.bar`)
* Identifies which features have the greatest overall impact on predicted `#leak`.
* Validates whether top features match human security intuition (e.g. `num_explicit_flows`, `taint_ratio`, `num_assertions`).

### 2. Beeswarm Summary Plot (`shap.plots.beeswarm`)
* Displays feature value magnitude (high vs. low, red vs. blue) against its positive or negative effect on predicted leakage.
* *Expected Pattern*: Higher values of `num_explicit_flows` and `taint_ratio` shift predictions to the right (increasing predicted `#leak`).

### 3. Dependence Plots (`shap.plots.scatter`)
* Plots individual feature values on the X-axis against SHAP value on the Y-axis to discover non-linear thresholds:
  * **`taint_ratio` Dependence**: Illustrates how the fraction of tainted statements triggers sharp increases in predicted leakage.
  * **`num_culprit_blocks` Dependence**: Illustrates how sensitive conditional branches contribute to implicit leakage.
  * **`num_array_accesses` Dependence**: Illustrates memory-based side-channel leakage thresholds.

---

## 4. Person 2 Deliverable Checkpoint

Person 2 produces:
* `mqil_ml/models/explain.py`: Script generating SHAP explanation plots.
* Saved visual artifacts: `shap_summary.png`, `shap_importance.png`, `shap_dependence.png`.
