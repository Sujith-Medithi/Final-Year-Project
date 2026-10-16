# Phase 4 --- Preprocessing, Family-Grouped Splitting, and Handover
**Responsible Roles**: Person 1 (Dataset Assembly & Handover) $\to$ Person 2 (Preprocessing & Modeling)

---

## 1. Objective

Assemble the complete, verified dataset `mqil_dataset.csv`, create leak-free train/validation/test splits grouped by architectural family, and execute the formal handover from Person 1 to Person 2.

---

## 2. Leak-Free Family-Grouped Splitting

### The Risk of Random Splitting
If a dataset of C programs is split randomly, syntactically similar program variants will appear across both the training set and the test set. The machine learning model will achieve deceptively high accuracy by simply **memorizing syntax patterns** rather than learning generalizable information flow rules.

### Grouped Splitting Strategy
Programs are partitioned strictly by **family ID** (`seed=42`):
* **Train Set (70%)**: 7 families.
* **Validation Set (10%)**: 1 family.
* **Test Set (20%)**: 2 completely held-out families.

$$\text{Train Families} \cap \text{Val Families} = \emptyset, \quad \text{Train Families} \cap \text{Test Families} = \emptyset, \quad \text{Val Families} \cap \text{Test Families} = \emptyset$$

The test set evaluates true **out-of-distribution generalization** on program architectures the model has never encountered during training.

---

## 3. Preprocessing Rules (Person 2 Responsibilities)

When Person 2 receives the frozen dataset and precomputed splits:

### Rule 1: Fit Scaler Strictly on `X_train`
```python
from sklearn.preprocessing import StandardScaler

scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_val_scaled = scaler.transform(X_val)      # Transform only!
X_test_scaled = scaler.transform(X_test)    # Transform only!
```
Never fit the scaler on the entire dataset. Fitting on the full dataset causes **data snooping / data leakage**.

### Rule 2: Constant Feature Pruning
Identify any feature columns with zero variance on `X_train` (e.g. if all training programs have identical input counts) and prune them from the feature matrix before training.

---

## 4. Formal Handover Checkpoint: Person 1 $\to$ Person 2

Person 1 provides the complete handover package:
1. **`mqil_ml/data/mqil_dataset.csv`**: The frozen dataset containing all features and target `#leak`.
2. **`mqil_ml/data/splits/grouped_splits.json`**: Precomputed indices for train, val, and test.
3. **`mqil_ml/data/splits/split_ids.json`**: Mapping of program IDs for each split.
4. **`mqil_ml/data/feature_dict.md`**: Column definitions matching the handwritten reference sheet.
5. **`HANDOVER_PERSON1_TO_PERSON2.md`**: Complete signoff and verification report.

Once handed over, Person 2 can begin machine learning modeling immediately without needing CBMC, GCC, or C parser tools!
