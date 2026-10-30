"""
Unit and regression tests for CBMC Execution Runner (Phase 1 / K1).
Verifies:
  - Acceptance of exit code 0 (VERIFICATION SUCCESSFUL) and 10 (VERIFICATION FAILED)
  - Loud failure on non-zero, non-10 exit codes (e.g. exit 6 on syntax error)
  - Loud failure if output lacks verification result line
  - Loud failure if 0 assertions parsed
  - Loud failure on timeout
"""

import subprocess
import tempfile
from pathlib import Path
from unittest.mock import patch, MagicMock
import pytest

from src.core.cbmc_runner import run_cbmc_verification

def test_cbmc_runner_mocked_success():
    mock_output = """
CBMC version 6.6.0 (cbmc-6.6.0) 64-bit x86_64 linux
[main.assertion.1] line 41 assertion v_1 == v_2: SUCCESS
** 0 of 1 failed (1 iterations)
VERIFICATION SUCCESSFUL
"""
    with patch("subprocess.run") as mock_run:
        mock_run.return_value = MagicMock(returncode=0, stdout=mock_output, stderr="")
        with tempfile.NamedTemporaryFile(suffix="_miter.c", delete=False) as f:
            f.write(b"// dummy")
            miter_path = Path(f.name)
        
        try:
            res = run_cbmc_verification(miter_path)
            assert res["actual_mqil_leakage"] == 0
            assert res["actual_mqil_assertions_total"] == 1
            assert res["mqil_leak_ratio"] == 0.0
            assert res["cbmc_exit_code"] == 0
            assert res["cbmc_status"] == "SUCCESSFUL"
            assert res["cbmc_verified"] is True
        finally:
            miter_path.unlink(missing_ok=True)

def test_cbmc_runner_mocked_failure():
    mock_output = """
CBMC version 6.6.0 (cbmc-6.6.0) 64-bit x86_64 linux
[main.assertion.1] line 41 assertion v_1 == v_2: FAILURE
** 1 of 1 failed (2 iterations)
VERIFICATION FAILED
"""
    with patch("subprocess.run") as mock_run:
        mock_run.return_value = MagicMock(returncode=10, stdout=mock_output, stderr="")
        with tempfile.NamedTemporaryFile(suffix="_miter.c", delete=False) as f:
            f.write(b"// dummy")
            miter_path = Path(f.name)
        
        try:
            res = run_cbmc_verification(miter_path)
            assert res["actual_mqil_leakage"] == 1
            assert res["actual_mqil_assertions_total"] == 1
            assert res["mqil_leak_ratio"] == 1.0
            assert res["cbmc_exit_code"] == 10
            assert res["cbmc_status"] == "FAILED"
            assert res["cbmc_verified"] is True
        finally:
            miter_path.unlink(missing_ok=True)

def test_cbmc_runner_mocked_syntax_error():
    mock_output = """
file miter.c line 5: syntax error before 'invalid'
PARSING ERROR
"""
    with patch("subprocess.run") as mock_run:
        mock_run.return_value = MagicMock(returncode=6, stdout="", stderr=mock_output)
        with tempfile.NamedTemporaryFile(suffix="_miter.c", delete=False) as f:
            f.write(b"// dummy")
            miter_path = Path(f.name)
        
        try:
            res = run_cbmc_verification(miter_path)
            assert res["dataset_status"] == "INVALID"
            assert res["cbmc_exit_code"] == 6
            assert "PARSING ERROR" in res["error"]
        finally:
            miter_path.unlink(missing_ok=True)

def test_cbmc_runner_mocked_missing_result_line():
    mock_output = """
CBMC version 6.6.0 (cbmc-6.6.0)
[main.assertion.1] line 41 assertion v_1 == v_2: SUCCESS
"""
    with patch("subprocess.run") as mock_run:
        mock_run.return_value = MagicMock(returncode=0, stdout=mock_output, stderr="")
        with tempfile.NamedTemporaryFile(suffix="_miter.c", delete=False) as f:
            f.write(b"// dummy")
            miter_path = Path(f.name)
        
        try:
            res = run_cbmc_verification(miter_path)
            assert res["dataset_status"] == "INVALID"
            assert res["cbmc_verified"] is False
        finally:
            miter_path.unlink(missing_ok=True)

def test_cbmc_runner_mocked_zero_assertions():
    mock_output = """
CBMC version 6.6.0 (cbmc-6.6.0)
VERIFICATION SUCCESSFUL
"""
    with patch("subprocess.run") as mock_run:
        mock_run.return_value = MagicMock(returncode=0, stdout=mock_output, stderr="")
        with tempfile.NamedTemporaryFile(suffix="_miter.c", delete=False) as f:
            f.write(b"// dummy")
            miter_path = Path(f.name)
        
        try:
            res = run_cbmc_verification(miter_path)
            assert res["dataset_status"] == "INVALID"
            assert res["actual_mqil_assertions_total"] == 0
        finally:
            miter_path.unlink(missing_ok=True)

def test_cbmc_runner_mocked_timeout():
    with patch("subprocess.run", side_effect=subprocess.TimeoutExpired(cmd=["cbmc"], timeout=5)):
        with tempfile.NamedTemporaryFile(suffix="_miter.c", delete=False) as f:
            f.write(b"// dummy")
            miter_path = Path(f.name)
        
        try:
            res = run_cbmc_verification(miter_path, timeout=5)
            assert res["dataset_status"] == "INVALID"
            assert res["overall_cbmc_status"] == "TIMEOUT"
            assert res["actual_mqil_leakage"] is None
        finally:
            miter_path.unlink(missing_ok=True)

def test_cbmc_runner_real_broken_c_raises():
    with tempfile.NamedTemporaryFile(suffix="_miter.c", mode="w", delete=False) as f:
        f.write("int main() { syntax error here !@#$ }\n")
        miter_path = Path(f.name)

    try:
        res = run_cbmc_verification(miter_path)
        assert res["dataset_status"] == "INVALID"
        assert res["cbmc_verified"] is False
    finally:
        miter_path.unlink(missing_ok=True)

def test_feature_extraction_miter_validation():
    from src.core.feature_extractor import validate_miter
    
    # 1. Missing miter raises FileNotFoundError
    with pytest.raises(FileNotFoundError):
        validate_miter(Path("non_existent_miter.c"), {"pin"})

    # 2. Empty miter raises ValueError
    with tempfile.NamedTemporaryFile(suffix="_miter.c", delete=False) as f:
        miter_empty = Path(f.name)
    try:
        with pytest.raises(ValueError) as exc:
            validate_miter(miter_empty, {"pin"})
        assert "empty" in str(exc.value)
    finally:
        miter_empty.unlink(missing_ok=True)

    # 3. Unparseable miter raises RuntimeError
    with tempfile.NamedTemporaryFile(suffix="_miter.c", mode="w", delete=False) as f:
        f.write("int main() { syntax error !@#$ }\n")
        miter_bad = Path(f.name)
    try:
        with pytest.raises(RuntimeError) as exc:
            validate_miter(miter_bad, {"pin"})
        assert "Failed to parse" in str(exc.value)
    finally:
        miter_bad.unlink(missing_ok=True)

    # 4. Miter missing suffixed seed variable raises ValueError
    with tempfile.NamedTemporaryFile(suffix="_miter.c", mode="w", delete=False) as f:
        f.write("int pin_1; int main() { return 0; }\n")
        miter_missing_seed = Path(f.name)
    try:
        with pytest.raises(ValueError) as exc:
            validate_miter(miter_missing_seed, {"pin"})
        assert "does not declare suffixed seed variable 'pin_2'" in str(exc.value)
    finally:
        miter_missing_seed.unlink(missing_ok=True)

