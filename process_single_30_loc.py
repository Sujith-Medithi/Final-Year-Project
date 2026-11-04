import io
import json
import csv
from pathlib import Path

from src.core.transpiler import generate_miter_program
from src.core.cbmc_runner import run_cbmc_verification
from src.core.feature_extractor import parse_c_ast, extract_all_mqil_features

WORKSPACE = Path(__file__).resolve().parent

# 1. Define 30-line C code
C_CODE = """#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int g_sink = 0;

int security_kernel(int sec, int pub) {
    int mask = (sec ^ 0x3F) & 15;
    int acc = pub * 3;
    if (mask > 8) {
        acc += (mask * 2);
    } else {
        acc -= (mask + 1);
    }
    return acc;
}

int main()
{
    int secret_val;
    int public_val;
    __CPROVER_assume(public_val >= -1000 && public_val <= 1000);
    __CPROVER_assume(secret_val >= 0 && secret_val <= 255);
    int intermediate;
    intermediate = security_kernel(secret_val, public_val);
    int status = 0;
    status = status + 1;
    g_sink = intermediate + status;
    return 0;
}"""

prog_id = "BENCHMARK_30_LOC"
family_id = "mixed_control_data"

source_path = WORKSPACE / f"{prog_id.lower()}.c"
config_path = WORKSPACE / f"{prog_id.lower()}.json"
miter_path = WORKSPACE / f"{prog_id.lower()}_miter.c"

source_ast_path = WORKSPACE / f"{prog_id.lower()}.ast"
source_ast_txt = WORKSPACE / f"{prog_id.lower()}_ast.txt"
miter_ast_path = WORKSPACE / f"{prog_id.lower()}_miter.ast"
miter_ast_txt = WORKSPACE / f"{prog_id.lower()}_miter_ast.txt"

# Save C program
source_path.write_text(C_CODE, encoding="utf-8")
loc = len(C_CODE.splitlines())
print(f"1. Saved source file: {source_path} (LOC: {loc})")
assert loc == 30, f"Expected 30 lines, got {loc}"

# Save companion config JSON
config_data = {
    "input_vars": ["secret_val", "public_val"],
    "high_vars": ["secret_val"],
    "low_vars": ["public_val"]
}
with open(config_path, "w", encoding="utf-8") as f:
    json.dump(config_data, f, indent=2)
print(f"2. Saved config file: {config_path}")

# 2. Transpile to 2-safety Miter
print("3. Transpiling to 2-safety miter...")
generate_miter_program(source_path, config_path, miter_path)
print(f"   Generated miter: {miter_path} (LOC: {len(miter_path.read_text(encoding='utf-8').splitlines())})")

# 3. Parse ASTs and dump .ast and .txt representations
print("4. Parsing and dumping ASTs...")
ast_source = parse_c_ast(source_path)
buf_s = io.StringIO()
ast_source.show(buf=buf_s, offset=0, attrnames=True, nodenames=True)
source_ast_txt.write_text(buf_s.getvalue(), encoding="utf-8")
source_ast_path.write_text(buf_s.getvalue(), encoding="utf-8")

ast_miter = parse_c_ast(miter_path)
buf_m = io.StringIO()
ast_miter.show(buf=buf_m, offset=0, attrnames=True, nodenames=True)
miter_ast_txt.write_text(buf_m.getvalue(), encoding="utf-8")
miter_ast_path.write_text(buf_m.getvalue(), encoding="utf-8")
print(f"   Saved source AST: {source_ast_path}")
print(f"   Saved miter AST: {miter_ast_path}")

# 4. Run CBMC Formal Verification
print("5. Running CBMC formal verification...")
cbmc_res = run_cbmc_verification(miter_path, unwind=5, timeout=60)
print(f"   CBMC status: {cbmc_res.get('cbmc_status')} (exit code: {cbmc_res.get('cbmc_exit_code')})")
print(f"   Actual MQIL Leakage: {cbmc_res.get('actual_mqil_leakage')} / {cbmc_res.get('actual_mqil_assertions_total')}")

# 5. Extract all features
print("6. Extracting all Whole-Program Security Features...")
feats = extract_all_mqil_features(source_path, config_path, miter_path)
print("   Features extracted successfully:")
for k in ["loc", "num_instructions", "num_branches", "num_loops", "num_variables",
          "num_high_inputs", "num_low_inputs", "num_explicit_flows", "num_culprit_blocks",
          "num_implicit_flows", "num_assumptions", "num_assertions", "taint_ratio",
          "secret_branch_ratio", "num_secret_bitops"]:
    print(f"     {k}: {feats.get(k)}")

# 6. Append to dataset.csv
csv_path = WORKSPACE / "dataset.csv"
print(f"7. Appending to {csv_path}...")

with open(csv_path, "r", encoding="utf-8") as f:
    reader = csv.reader(f)
    header = next(reader)

row_dict = {
    "program_id": prog_id,
    "family_id": family_id,
    "source_file": source_path.name,
    "miter_file": miter_path.name,
    "all_inputs": "secret_val,public_val",
    "high_inputs": "secret_val",
    "low_inputs": "public_val",
    "actual_mqil_leakage": cbmc_res.get("actual_mqil_leakage", 0),
    "leakage_value": cbmc_res.get("actual_mqil_leakage", 0),
    "actual_mqil_assertions_total": cbmc_res.get("actual_mqil_assertions_total", 0),
}

# Merge extracted features
row_dict.update(feats)

new_row = [row_dict.get(col, "") for col in header]

with open(csv_path, "a", newline="", encoding="utf-8") as f:
    writer = csv.writer(f)
    writer.writerow(new_row)

print("Successfully appended new row to dataset.csv!")
print("Header columns:", len(header))
print("Row values:", len(new_row))

