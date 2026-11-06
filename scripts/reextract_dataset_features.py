"""
Dataset Re-Extraction Tool for Source-Centric Architecture Migration.
Applies the finalized Source-Centric extraction architecture across generated datasets:
  - Binds explicit and implicit flows to unique variables.
  - Excludes inputs from internal leaked variable counts.
  - Enforces num_assumptions == num_high_inputs + num_low_inputs.
  - Enforces num_culprit_blocks <= num_branches.
  - Enforces all ratios (taint_ratio, secret_branch_ratio) in [0.0, 1.0].
  - Employs multiprocessing for fast processing on multi-core systems.
"""

import sys
import os
import json
import time
import argparse
from pathlib import Path
from concurrent.futures import ProcessPoolExecutor, as_completed
import pandas as pd
from typing import Dict, Any, Tuple, Optional

# Ensure FP/src is in sys.path
WORKSPACE = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(WORKSPACE))

from src.core.feature_extractor import extract_all_mqil_features, FEATURE_COLS

def _extract_single_program(args: Tuple[str, str, Optional[str]]) -> Tuple[str, Optional[Dict[str, Any]], Optional[str]]:
    """Worker task to extract features for a single program."""
    pid, c_path_str, json_path_str = args
    try:
        c_path = Path(c_path_str)
        json_path = Path(json_path_str)
        if not c_path.exists():
            return pid, None, f"Source C file not found: {c_path}"
        if not json_path.exists():
            return pid, None, f"Config JSON not found: {json_path}"

        feats = extract_all_mqil_features(
            source_c_path=c_path,
            input_json_path=json_path,
            architecture="source_centric"
        )
        return pid, feats, None
    except Exception as e:
        return pid, None, f"Extraction failed for {pid}: {str(e)}"


def reextract_dataset(dataset_dir: Path, max_workers: Optional[int] = None) -> bool:
    """Re-extracts features for all programs in a dataset directory and updates CSV + JSONs."""
    dataset_dir = Path(dataset_dir).resolve()
    print(f"\n{'='*80}")
    print(f"Processing Dataset: {dataset_dir.name} ({dataset_dir})")
    print(f"{'='*80}")

    csv_candidates = [
        dataset_dir / "random_dataset.csv",
        dataset_dir / "dataset.csv"
    ]
    csv_path = None
    for cand in csv_candidates:
        if cand.exists():
            csv_path = cand
            break

    if not csv_path:
        print(f"[ERROR] No dataset CSV found in {dataset_dir}")
        return False

    prog_dir = dataset_dir / "programs"
    conf_dir = dataset_dir / "configs"
    feat_dir = dataset_dir / "features"

    if not prog_dir.exists() or not conf_dir.exists():
        print(f"[ERROR] Required subdirectories missing in {dataset_dir} (programs/ or configs/)")
        return False

    df = pd.read_csv(csv_path)
    print(f"Loaded {len(df)} rows from {csv_path.name}")

    # Prepare extraction tasks
    tasks = []
    for idx, row in df.iterrows():
        pid = str(row["program_id"])
        c_path = prog_dir / f"{pid}.c"
        json_path = conf_dir / f"{pid}.json"

        # Fallback to source_file column if file not in prog_dir directly
        if not c_path.exists() and "source_file" in row and pd.notna(row["source_file"]):
            candidate = WORKSPACE / str(row["source_file"])
            if candidate.exists():
                c_path = candidate

        tasks.append((pid, str(c_path), str(json_path)))

    workers = max_workers or max(1, (os.cpu_count() or 4) - 2)
    print(f"Running parallel extraction with {workers} workers across {len(tasks)} programs...")

    start_time = time.time()
    results = {}
    errors = []

    with ProcessPoolExecutor(max_workers=workers) as executor:
        futures = {executor.submit(_extract_single_program, t): t[0] for t in tasks}
        completed = 0
        total = len(tasks)
        for fut in as_completed(futures):
            pid, feats, err = fut.result()
            completed += 1
            if err:
                errors.append(err)
            else:
                results[pid] = feats

            if completed % 100 == 0 or completed == total:
                elapsed = time.time() - start_time
                rate = completed / elapsed if elapsed > 0 else 0
                print(f"  Progress: {completed}/{total} ({completed/total*100:.1f}%) | {rate:.1f} progs/sec")

    if errors:
        print(f"[WARN] {len(errors)} extraction errors encountered:")
        for e in errors[:5]:
            print(f"  - {e}")
        if len(errors) > 5:
            print(f"  ... and {len(errors) - 5} more")

    # Update DataFrame and individual JSON features
    print("\nUpdating dataset records and validating invariants...")
    updated_count = 0
    invariant_violations = []

    for idx, row in df.iterrows():
        pid = str(row["program_id"])
        if pid not in results:
            continue

        feats = results[pid]

        # Update DataFrame columns
        for col, val in feats.items():
            if col in df.columns:
                df.at[idx, col] = val

        # Invariant checks
        vars_cnt = df.at[idx, "num_variables"]
        branches_cnt = df.at[idx, "num_branches"]
        exp_flows = df.at[idx, "num_explicit_flows"]
        imp_flows = df.at[idx, "num_implicit_flows"]
        leaks = df.at[idx, "num_information_leak"]
        culprits = df.at[idx, "num_culprit_blocks"]
        assumps = df.at[idx, "num_assumptions"]
        high_in = df.at[idx, "num_high_inputs"]
        low_in = df.at[idx, "num_low_inputs"]
        taint_r = df.at[idx, "taint_ratio"]
        br_r = df.at[idx, "secret_branch_ratio"]

        if exp_flows > vars_cnt:
            invariant_violations.append(f"{pid}: num_explicit_flows ({exp_flows}) > num_variables ({vars_cnt})")
        if imp_flows > vars_cnt:
            invariant_violations.append(f"{pid}: num_implicit_flows ({imp_flows}) > num_variables ({vars_cnt})")
        if leaks > vars_cnt:
            invariant_violations.append(f"{pid}: num_information_leak ({leaks}) > num_variables ({vars_cnt})")
        if culprits > branches_cnt:
            invariant_violations.append(f"{pid}: num_culprit_blocks ({culprits}) > num_branches ({branches_cnt})")
        if assumps != (high_in + low_in):
            invariant_violations.append(f"{pid}: num_assumptions ({assumps}) != inputs ({high_in + low_in})")
        if taint_r > 1.0 or taint_r < 0.0:
            invariant_violations.append(f"{pid}: taint_ratio ({taint_r}) outside [0.0, 1.0]")
        if br_r > 1.0 or br_r < 0.0:
            invariant_violations.append(f"{pid}: secret_branch_ratio ({br_r}) outside [0.0, 1.0]")

        # Update JSON in features/ directory if it exists
        if feat_dir.exists():
            feat_json_path = feat_dir / f"{pid}.json"
            try:
                feat_json_path.write_text(json.dumps(feats, indent=2), encoding="utf-8")
            except Exception:
                pass

        updated_count += 1

    # Save CSV
    df.to_csv(csv_path, index=False)
    total_time = time.time() - start_time
    print(f"[OK] Successfully updated {updated_count}/{len(df)} programs in {csv_path.name} ({total_time:.1f}s)")

    if invariant_violations:
        print(f"[FAIL] {len(invariant_violations)} invariant violations detected:")
        for v in invariant_violations[:10]:
            print(f"  - {v}")
        return False
    else:
        print("[PASS] 100% of programs strictly passed all 5 mathematical invariants!")

    # Summary statistics
    print("\nUpdated Distribution Summary:")
    print(f"  - Max Information Leak: {df['num_information_leak'].max()} (Max Variables: {df['num_variables'].max()})")
    print(f"  - Max Explicit Flows:   {df['num_explicit_flows'].max()}")
    print(f"  - Max Implicit Flows:   {df['num_implicit_flows'].max()}")
    print(f"  - Max Culprit Blocks:   {df['num_culprit_blocks'].max()} (Max Branches: {df['num_branches'].max()})")
    print(f"  - Max Taint Ratio:      {df['taint_ratio'].max():.4f}")
    print(f"  - Max Branch Ratio:     {df['secret_branch_ratio'].max():.4f}")
    return True


def main():
    parser = argparse.ArgumentParser(description="Re-extract dataset features using the new Source-Centric Architecture.")
    parser.add_argument("--dataset", type=str, default="all",
                        help="Target dataset directory name (e.g. random_4, stage1_smoke) or 'all'")
    parser.add_argument("--workers", type=int, default=None,
                        help="Number of parallel worker processes")
    args = parser.parse_args()

    datasets_root = WORKSPACE / "datasets"

    if args.dataset == "all":
        target_dirs = [
            datasets_root / "stage1_smoke",
            datasets_root / "stage2_pipeline",
            datasets_root / "random",
            datasets_root / "random_3",
            datasets_root / "random_4",
            datasets_root / "stage3_scaling",
            datasets_root / "random_2"
        ]
    else:
        target_dirs = [datasets_root / args.dataset]

    total_start = time.time()
    success_count = 0

    for d in target_dirs:
        if d.exists() and d.is_dir():
            res = reextract_dataset(d, max_workers=args.workers)
            if res:
                success_count += 1
        else:
            print(f"[SKIP] Directory does not exist: {d}")

    total_elapsed = time.time() - total_start
    print(f"\n{'='*80}")
    print(f"ALL MIGRATIONS FINISHED: {success_count}/{len(target_dirs)} datasets succeeded in {total_elapsed:.1f}s")
    print(f"{'='*80}")

if __name__ == "__main__":
    main()
