"""
Regression test suite for Miter Transpiler fixes (Phase 2):
  - K2: Struct/union body re-definition (must define once, not 3 times)
  - K3: main(void) parameter handling (must not produce void None_1, void None_2)
  - K4 (D6): No undefined printf_2 / assert_2 / scanf_2 / exit_2 helper calls
  - K5: Typo 'idx_name' instead of idx_name in array loop
  - K26 (D7): Union equality replaced with member-wise comparison
"""

import json
import tempfile
from pathlib import Path
import pytest
from src.core.transpiler import generate_miter_program
from src.core.cbmc_runner import run_cbmc_verification

def test_k3_main_void_regression():
    c_code = """
int main(void) {
    int x;
    x = 10;
    return 0;
}
"""
    cfg = {"input_vars": ["x"], "high_vars": ["x"], "low_vars": []}
    with tempfile.TemporaryDirectory() as tmpdir:
        td = Path(tmpdir)
        c_path = td / "prog.c"
        json_path = td / "prog.json"
        miter_path = td / "miter.c"
        c_path.write_text(c_code)
        json_path.write_text(json.dumps(cfg))

        generate_miter_program(c_path, json_path, miter_path)
        miter_text = miter_path.read_text()
        assert "None_1" not in miter_text, "Miter contains 'None_1' from broken main(void) handling"
        assert "None_2" not in miter_text, "Miter contains 'None_2' from broken main(void) handling"

def test_k4_no_undefined_printf2_assert2_regression():
    c_code = """
#include <stdio.h>
#include <assert.h>

int main(void) {
    int x;
    assert(x >= 0);
    printf("%d\\n", x);
    return 0;
}
"""
    cfg = {"input_vars": ["x"], "high_vars": ["x"], "low_vars": []}
    with tempfile.TemporaryDirectory() as tmpdir:
        td = Path(tmpdir)
        c_path = td / "prog.c"
        json_path = td / "prog.json"
        miter_path = td / "miter.c"
        c_path.write_text(c_code)
        json_path.write_text(json.dumps(cfg))

        generate_miter_program(c_path, json_path, miter_path)
        miter_text = miter_path.read_text()
        assert "printf_2" not in miter_text, "Miter contains undefined 'printf_2' call"
        assert "assert_2" not in miter_text, "Miter contains undefined 'assert_2' call"

def test_k2_k26_union_single_def_and_member_equality_regression():
    c_code = """
union Reg {
    int word;
    unsigned char part[2];
};

int main(void) {
    union Reg reg;
    reg.word = 42;
    return 0;
}
"""
    cfg = {"input_vars": [], "high_vars": [], "low_vars": []}
    with tempfile.TemporaryDirectory() as tmpdir:
        td = Path(tmpdir)
        c_path = td / "prog.c"
        json_path = td / "prog.json"
        miter_path = td / "miter.c"
        c_path.write_text(c_code)
        json_path.write_text(json.dumps(cfg))

        generate_miter_program(c_path, json_path, miter_path)
        miter_text = miter_path.read_text()

        # K2: union Reg must be defined once, not 3 times
        assert miter_text.count("union Reg\n{") <= 1 and miter_text.count("union Reg {") <= 1

        # K26: must not compare union directly (assert(reg_1 == reg_2))
        assert "reg_1 == reg_2" not in miter_text
        # Must compare members: word and part element-by-element
        assert "reg_1.word == reg_2.word" in miter_text
        assert "reg_1.part[i_part] == reg_2.part[i_part]" in miter_text or "reg_1.part[0] == reg_2.part[0]" in miter_text

        # CBMC must type-check and verify successfully
        res = run_cbmc_verification(miter_path)
        assert res["cbmc_verified"] is True

def test_k5_array_input_idx_name():
    # 1. Direct AST verification of for_loop_func_call
    import sys
    sys.path.insert(0, str(Path("tools/cbmc_mqil/src").resolve()))
    from modules.utils import for_loop_func_call
    from pycparser import c_generator

    ast_loop = for_loop_func_call("arr", 4, "assert", "==")
    loop_str = c_generator.CGenerator().visit(ast_loop)
    assert "[idx_name]" not in loop_str, "Literal 'idx_name' string found in for_loop_func_call output!"
    assert "arr_2[arr_index]" in loop_str

    # 2. Program-level verification
    c_code = """
int main(void) {
    int arr[4];
    arr[0] = 1;
    return 0;
}
"""
    cfg = {"input_vars": ["arr"], "high_vars": [], "low_vars": ["arr"]}
    with tempfile.TemporaryDirectory() as tmpdir:
        td = Path(tmpdir)
        c_path = td / "prog.c"
        json_path = td / "prog.json"
        miter_path = td / "miter.c"
        c_path.write_text(c_code)
        json_path.write_text(json.dumps(cfg))

        generate_miter_program(c_path, json_path, miter_path)
        miter_text = miter_path.read_text()
        assert "[idx_name]" not in miter_text
        assert "arr_1[i_0] == arr_2[i_0]" in miter_text or "arr_1[arr_index] == arr_2[arr_index]" in miter_text


