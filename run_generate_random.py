import sys
import time
from pathlib import Path

# Add project root to path
sys.path.insert(0, str(Path(__file__).resolve().parent))

from src.generator.random_program_generator import run_random_dataset

if __name__ == "__main__":
    t0 = time.time()
    report = run_random_dataset(count=100, master_seed=42000, max_workers=6)
    t1 = time.time()
    print(f"\nExecution finished in {t1 - t0:.2f} seconds.")
