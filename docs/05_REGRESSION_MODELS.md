# Phase 5 --- Supervised Regression Models for Information Leakage Prediction
**Responsible Role**: Person 2 (Machine Learning Modeling)

---

## 1. Objective

Train and fine-tune supervised regression models to predict quantitative information leakage (`#leak` = number of failed assertions in CBMC) directly from the extracted source code features without running CBMC.

---

## 2. Regression Model Architectures

Person 2 implements and compares five distinct model architectures:

### 1. Linear Baseline (Ridge Regression)
* **Purpose**: Establish linear interpretability baseline.
* **Regularization**: L2 penalty (`alpha=1.0`).

### 2. Random Forest Regressor
* **Purpose**: Primary tree-based ensemble capturing non-linear feature interactions and threshold effects.
* **Hyperparameters**: `n_estimators=100`, `max_depth=6..12`, `min_samples_split=2`.
* **Advantages**: Robust to feature scaling, provides feature importances, immune to outliers.

### 3. Support Vector Regressor (SVR)
* **Purpose**: Non-linear kernel regression mapping features to high-dimensional space.
* **Kernel**: Radial Basis Function (`rbf`), `C=1.0..10.0`, `gamma='scale'`.
* **Requirement**: Requires `StandardScaler` normalized inputs.

### 4. Multi-Layer Perceptron (MLP / ANN)
* **Purpose**: Feedforward neural network capturing complex compositional representations.
* **Architecture**: 2 hidden layers: `hidden_layer_sizes=(64, 32)`, `activation='relu'`, `optimizer='adam'`.
* **Regularization**: `early_stopping=True`, L2 penalty `alpha=0.001`.

### 5. Gradient Boosting / XGBoost Regressor
* **Purpose**: Sequential gradient-boosted decision trees minimizing residual prediction error.
* **Hyperparameters**: `n_estimators=100`, `learning_rate=0.05`, `max_depth=3..5`.

---

## 3. Training Protocol

1. **Load Precomputed Splits**:
   Load `X_train`, `y_train`, `X_val`, `y_val` from `mqil_ml/data/splits/grouped_splits.json`.
2. **Train & Tune on Validation Set**:
   Fit candidate models on `X_train` and tune hyperparameters against `X_val`.
3. **Select Best Model**:
   Select the top-performing model based on validation Mean Absolute Error (MAE) and $R^2$.
4. **Final Test Evaluation**:
   Evaluate once on the completely held-out `X_test` (families the model has never seen).

---

## 4. Person 2 Deliverable Checkpoint

Person 2 produces:
* `mqil_ml/models/train.py`: Automated multi-model training script.
* Serialized best model (`best_model.joblib`) ready for fast inference.
