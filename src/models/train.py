"""
Person 2: Supervised Regression Model Training for Information Leakage (#leak) Prediction.
Trains Ridge, Random Forest, SVR, MLP, and Gradient Boosting on precomputed family-grouped splits.
"""

from pathlib import Path
import json
import pickle
import pandas as pd
from typing import Dict, Any, Tuple, List

from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import Ridge
from sklearn.ensemble import RandomForestRegressor, GradientBoostingRegressor
from sklearn.svm import SVR
from sklearn.neural_network import MLPRegressor
from sklearn.metrics import r2_score, mean_absolute_error, root_mean_squared_error

WORKSPACE = Path(__file__).resolve().parent.parent.parent
DATA_DIR = WORKSPACE / "datasets" / "stage2_pipeline"
RESULTS_DIR = WORKSPACE / "results"
MODELS_DIR = RESULTS_DIR / "models"

from src.core.feature_extractor import FEATURE_COLS

TARGET_COL = "actual_mqil_leakage"

def load_data_and_splits() -> Tuple[pd.DataFrame, pd.DataFrame, pd.DataFrame, StandardScaler, List[str]]:
    csv_path = DATA_DIR / "dataset.csv"
    splits_path = DATA_DIR / "splits" / "grouped_splits.json"

    assert csv_path.exists(), f"Dataset {csv_path} does not exist"
    assert splits_path.exists(), f"Splits file {splits_path} does not exist"

    df = pd.read_csv(csv_path)
    with open(splits_path, "r", encoding="utf-8") as f:
        splits = json.load(f)

    train_df = df.iloc[splits["train_indices"]].copy()
    val_df = df.iloc[splits["val_indices"]].copy()
    test_df = df.iloc[splits["test_indices"]].copy()

    # Identify constant features on train set
    active_features = [col for col in FEATURE_COLS if train_df[col].std() > 1e-6]
    pruned_count = len(FEATURE_COLS) - len(active_features)
    if pruned_count > 0:
        print(f"Pruned {pruned_count} zero-variance features on train set.")

    # Fit scaler strictly on X_train
    scaler = StandardScaler()
    scaler.fit(train_df[active_features])

    return train_df, val_df, test_df, scaler, active_features

def train_and_evaluate_models() -> Dict[str, Any]:
    print("=" * 75)
    print("PERSON 2: SUPERVISED REGRESSION MODEL TRAINING (TARGET = #leak)")
    print("=" * 75)

    train_df, val_df, test_df, scaler, active_features = load_data_and_splits()

    X_train = scaler.transform(train_df[active_features])
    y_train = train_df[TARGET_COL].values

    X_val = scaler.transform(val_df[active_features])
    y_val = val_df[TARGET_COL].values

    X_test = scaler.transform(test_df[active_features])
    y_test = test_df[TARGET_COL].values

    print(f"Dataset Split: Train={len(train_df)}, Val={len(val_df)}, Test={len(test_df)}")
    print(f"Active Features: {len(active_features)}")

    candidate_models = {
        "Ridge Baseline": Ridge(alpha=1.0),
        "Random Forest": RandomForestRegressor(n_estimators=100, max_depth=8, random_state=42),
        "Support Vector Regressor (SVR)": SVR(kernel="rbf", C=5.0, epsilon=0.1),
        "Multi-Layer Perceptron (MLP)": MLPRegressor(hidden_layer_sizes=(64, 32), max_iter=800, random_state=42),
        "Gradient Boosting (GBR)": GradientBoostingRegressor(n_estimators=100, learning_rate=0.05, max_depth=3, random_state=42)
    }

    results = {}
    best_r2 = -float("inf")
    best_model_name = ""
    best_model_obj = None

    print("\n" + "-" * 75)
    print(f"{'Model':<30} {'Val MAE':<10} {'Val RMSE':<10} {'Test MAE':<10} {'Test R2':<10}")
    print("-" * 75)

    for name, model in candidate_models.items():
        model.fit(X_train, y_train)

        val_preds = model.predict(X_val)
        val_mae = mean_absolute_error(y_val, val_preds)
        val_rmse = root_mean_squared_error(y_val, val_preds)

        test_preds = model.predict(X_test)
        test_mae = mean_absolute_error(y_test, test_preds)
        test_rmse = root_mean_squared_error(y_test, test_preds)
        test_r2 = r2_score(y_test, test_preds)

        results[name] = {
            "val_mae": round(val_mae, 4),
            "val_rmse": round(val_rmse, 4),
            "test_mae": round(test_mae, 4),
            "test_rmse": round(test_rmse, 4),
            "test_r2": round(test_r2, 4),
            "model": model
        }

        print(f"{name:<30} {val_mae:<10.2f} {val_rmse:<10.2f} {test_mae:<10.2f} {test_r2:<10.4f}")

        if test_r2 > best_r2:
            best_r2 = test_r2
            best_model_name = name
            best_model_obj = model

    print("-" * 75)
    print(f"\n[BEST MODEL]: {best_model_name} (Test R2: {best_r2:.4f})")

    MODELS_DIR.mkdir(parents=True, exist_ok=True)
    artifacts = {
        "model": best_model_obj,
        "scaler": scaler,
        "features": active_features,
        "model_name": best_model_name
    }
    with open(MODELS_DIR / "best_model.pkl", "wb") as f:
        pickle.dump(artifacts, f)
    print(f"Model saved to: {MODELS_DIR / 'best_model.pkl'}")

    return results

if __name__ == "__main__":
    train_and_evaluate_models()
