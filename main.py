"""
MQIL Information Leakage ML Prediction System
Master Command-Line Interface (CLI)

Usage Examples:
  python main.py --stage 1     # Run Stage 1 smoke test & canonical baseline (12 programs)
  python main.py --stage 2     # Run Stage 2 scaled benchmark synthesis (100 programs)
  python main.py --train       # Train supervised ML regression models
  python main.py --evaluate    # Execute 4-tier feature ablation study
  python main.py --explain     # Generate feature importance and explainability plots
  python main.py --ml          # Run complete ML workflow (train + evaluate + explain)
  python main.py --all         # Run entire end-to-end pipeline
"""

import sys
import argparse
from pathlib import Path

WORKSPACE = Path(__file__).resolve().parent
sys.path.insert(0, str(WORKSPACE))

from src.pipeline import run_stage1_smoke, run_stage2_pipeline, run_stage2_scaled, run_stage3_scaling, run_ml_pipeline
from src.models.train import train_and_evaluate_models
from src.models.evaluate import run_ablation_study
from src.models.explain import generate_explainability_artifacts

def main():
    parser = argparse.ArgumentParser(
        description="Predict Information Leakage in C Programs using Machine Learning (MQIL Framework)",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  python main.py --stage 1     # Run Stage 1 Smoke Test (12 canonical programs)
  python main.py --stage 2     # Run Stage 2 Pipeline Validation (50 diverse programs)
  python main.py --stage 3     # Run Stage 3 Core Benchmark Scaling (1,000 programs)
  python main.py --train       # Train Ridge, RF, SVR, MLP, and Gradient Boosting
  python main.py --evaluate    # Feature ablation (Group A vs B vs C vs Full)
  python main.py --explain     # Generate SHAP & Feature Importance plots
  python main.py --ml          # Run all ML steps (train, evaluate, explain)
  python main.py --all         # Full end-to-end system run
        """
    )
    parser.add_argument("--stage", choices=["1", "2", "3"], help="Run dataset generation stage (1=Smoke Test, 2=Pipeline Validation, 3=Core Benchmark Scaling 1,000)")
    parser.add_argument("--custom", nargs=2, metavar=("PROGRAM_C", "CONFIG_JSON"), help="Manually evaluate a custom C program and JSON config")
    parser.add_argument("--append", action="store_true", help="Append the evaluated custom program as a row into root dataset.csv")
    parser.add_argument("--train", action="store_true", help="Train regression models on scaled dataset")
    parser.add_argument("--evaluate", action="store_true", help="Run 4-tier feature ablation study")
    parser.add_argument("--explain", action="store_true", help="Generate feature importance and parity plots")
    parser.add_argument("--ml", action="store_true", help="Execute complete Person 2 ML pipeline (train + evaluate + explain)")
    parser.add_argument("--all", action="store_true", help="Run complete end-to-end pipeline (Data + ML)")

    args = parser.parse_args()

    if len(sys.argv) == 1:
        parser.print_help()
        sys.exit(0)

    if args.custom:
        from src.pipeline import evaluate_custom_program
        evaluate_custom_program(Path(args.custom[0]), Path(args.custom[1]), append_csv=args.append)
        return

    if args.stage == "1":
        run_stage1_smoke()
    elif args.stage == "2":
        run_stage2_pipeline()
    elif args.stage == "3":
        run_stage3_scaling()

    if args.train:
        train_and_evaluate_models()

    if args.evaluate:
        run_ablation_study()

    if args.explain:
        generate_explainability_artifacts()

    if args.ml:
        run_ml_pipeline()

    if args.all:
        print("\n>>> EXECUTING FULL END-TO-END PIPELINE <<<")
        run_stage1_smoke()
        run_stage2_scaled()
        run_ml_pipeline()

if __name__ == "__main__":
    main()
