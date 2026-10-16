# MQIL Miter Transpiler Patches Log

This document records all modifications made to `tools/cbmc_mqil/src/` to ensure valid C miter emission and compliance with project invariants.

---

### Patch 1: `modules/globals.py`
- **Line**: 18-22
- **What**: Added `global unions_declared` and initialized `unions_declared = {}`.
- **Why**: Union type definitions must be tracked across modules to allow member-wise equality assertions.
- **Bug ID**: K26 (D7)

---

### Patch 2: `modules/utils.py`
- **Line**: 81-96 (`process_structs`)
  - **What**: Populated both `structs_declared` and `unions_declared` from AST definitions.
  - **Why**: Ensured all declared struct and union types have their member declarations preserved for subsequent assertion generation.
  - **Bug ID**: K2, K26
- **Line**: 146 (`for_loop_func_call`)
  - **What**: Replaced `cast.ID('idx_name')` with `cast.ID(idx_name)`.
  - **Why**: Fixed typo where `'idx_name'` was stringified as a string literal instead of using the loop index variable name.
  - **Bug ID**: K5
- **Line**: 154-228 (`composite_assert`, `struct_assert`, `union_assert`)
  - **What**: Implemented member-wise assertion comparison: scalar members compared with `==`, pointer members dereferenced (`*ptr`), and array members compared element-by-element inside a generated for-loop.
  - **Why**: Direct comparison of unions (`reg_1 == reg_2`) and arrays is illegal C syntax.
  - **Bug ID**: K26 (D7)

---

### Patch 3: `main.py`
- **Line**: 70-79
  - **What**: Skipped duplication for top-level `cast.Struct` and `cast.Union` definitions (and `cast.Decl` whose type is a struct/union with `item.name is None`).
  - **Why**: Top-level struct and union types were previously duplicated three times in the translation unit, causing invalid C redefinition errors.
  - **Bug ID**: K2

---

### Patch 4: `modules/FuncDefHandler2.py`
- **Line**: 58-75 (`add_arguments`)
  - **What**: Handled `main` function to ensure it has return type `void` and `type.args = None` (parameterless). Also handled single `(void)` parameter in functions to avoid renaming `void` to `None_1, None_2`.
  - **Why**: `main(void)` was previously transpiled into `void main(void None_1, void None_2)`, which is illegal C syntax.
  - **Bug ID**: K3
- **Line**: 100-112 (`handle_func_call`)
  - **What**: Restricted helper emission so that external calls (`printf`, `scanf`, `exit`, `assert`, etc.) emit only the two renamed calls (`call_1`, `call_2`) and no combined `call_3` (`*_2`).
  - **Why**: libc does not contain combined functions like `printf_2` or `assert_2`.
  - **Bug ID**: K4 (D6)

---

### Patch 5: `modules/AddAssertCalls.py`
- **Line**: 8, 17-18 (`get_assert_loop`)
  - **What**: Imported and dispatched `union_assert(var_name, var_type.type.name)` when encountering a `cast.Union` type in declarations.
  - **Why**: Dispatched member-wise assertion comparison for union variables instead of falling back to scalar `assert(u_1 == u_2)`.
  - **Bug ID**: K26 (D7)
