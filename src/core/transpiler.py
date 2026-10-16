"""
MQIL Miter Transpiler.
Wraps the official MQIL AST generator (tools/cbmc_mqil/src/main.py) to transform
any whole C program and its companion input JSON into a 2-safety self-composition miter.
"""

from pathlib import Path
import subprocess
import sys

WORKSPACE_ROOT = Path(__file__).resolve().parent.parent.parent
CBMC_SRC_DIR = WORKSPACE_ROOT / "tools" / "cbmc_mqil" / "src"
PYTHON_EXE = sys.executable

def generate_miter_program(source_c_path: Path, input_json_path: Path, output_miter_path: Path) -> Path:
    """
    Executes the official MQIL transpiler on source_c_path with input_json_path
    and saves the generated self-composition miter program to output_miter_path.
    """
    assert source_c_path.exists(), f"Source file {source_c_path} does not exist"
    assert input_json_path.exists(), f"Input JSON {input_json_path} does not exist"
    
    output_miter_path.parent.mkdir(parents=True, exist_ok=True)
    
    cmd = [
        PYTHON_EXE,
        str(CBMC_SRC_DIR / "main.py"),
        str(source_c_path.resolve()),
        str(input_json_path.resolve()),
        str(output_miter_path.resolve())
    ]
    
    proc = subprocess.run(
        cmd,
        cwd=str(CBMC_SRC_DIR),
        capture_output=True,
        text=True
    )
    
    if proc.returncode != 0:
        raise RuntimeError(f"MQIL miter generation failed for {source_c_path}:\n{proc.stderr}\n{proc.stdout}")
        
    if not output_miter_path.exists():
        raise FileNotFoundError(f"Expected generated miter at {output_miter_path}, but file was not found.")
        
    return output_miter_path
