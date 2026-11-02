import sys
import time
from pathlib import Path

# Add project root to path
sys.path.insert(0, str(Path(__file__).resolve().parent))

from src.generator.random_program_generator_v3 import run_random_3_dataset

if __name__ == "__main__":
    count = 100
    if len(sys.argv) > 1:
        count = int(sys.argv[1])

    workspace = Path(__file__).resolve().parent
    dest_dir = workspace / "datasets" / "random_3"

    t0 = time.time()
    report = run_random_3_dataset(
        dest_dir=dest_dir,
        count=count,
        min_loc=2000,
        max_loc=2500,
        master_seed=99000,
        max_workers=8
    )
    t1 = time.time()
    print(f"\nExecution finished in {t1 - t0:.2f} seconds.")

