"""
Whole-Program Security and Structural Feature Extractor (Phase 4 / Parity Fix).
Extracts 22 features strictly based on MQIL specifications and parity rules:
  - Group A: Program Structure (measured on the SOURCE file, C1, D8, D9, K24)
  - Group B: Security & Taint Flow Features (measured on the MITER file, C2, C3, D1-D5, K6, K19, K21, K22, K25, K27)
  - Normalized Ratios: taint_ratio, secret_branch_ratio, secret_memory_ratio (measured on same file miter-side counters, D2, K21)
"""

from pathlib import Path
import re
import json
from typing import Dict, Any, Set, List, Optional, Union
from pycparser import c_parser, c_ast, parse_file

WORKSPACE_ROOT = Path(__file__).resolve().parent.parent.parent
FAKE_LIBC_DIR = WORKSPACE_ROOT / "tools" / "fake_libc"

# Single source of truth for the 29 feature column names (Frozen Interface, 22 existing + 7 new)
FEATURE_COLS: List[str] = [
    # 22 Existing Features
    "loc", "num_instructions", "num_branches", "num_loops", "num_functions",
    "num_variables", "num_arrays", "num_structure", "num_union",
    "num_high_inputs", "num_low_inputs",
    "num_explicit_flows", "num_culprit_blocks", "num_implicit_flows",
    "num_information_leak", "num_secret_dependent_prints",
    "num_assumptions", "num_assertions", "num_array_accesses",
    "taint_ratio", "secret_branch_ratio", "secret_memory_ratio",
    # New Flow & Verification Disambiguation Features
    "loop_to_unwind_ratio",
    "num_tainted_returns",
    "num_tainted_globals",
    "max_taint_depth",
    "num_secret_bitops"
]

PRINT_FUNCS = {"printf", "puts", "putchar", "fprintf", "sprintf", "snprintf"}
BITWISE_OPS = {">>", "<<", "&", "|", "^"}
BITWISE_ASSIGN_OPS = {">>=", "<<=", "&=", "|=", "^="}
LIBC_SYMBOLS = {
    "stdin_1", "stdin_2", "stdin", "stdout_1", "stdout_2", "stdout",
    "stderr_1", "stderr_2", "stderr"
}


# =============================================================================
# Helper Utilities: Code Cleaning, AST Parsing, D8 Variable Counting
# =============================================================================

def clean_c_code_for_pycparser(source_code: str) -> str:
    """Strips comments and preprocessor includes so pycparser parses cleanly without external CPP."""
    clean = re.sub(r'/\*.*?\*/', '', source_code, flags=re.DOTALL)
    clean = re.sub(r'//.*?\n', '\n', clean)
    clean = re.sub(r'#include\s*<[^>]+>', '', clean)
    clean = re.sub(r'#include\s*"[^"]+"', '', clean)
    return clean

def parse_c_ast(file_path: Path) -> c_ast.FileAST:
    """Parses a C file using pycparser with fake_libc CPP arguments, with robust fallback."""
    file_path = Path(file_path).resolve()
    assert file_path.exists(), f"File does not exist: {file_path}"

    if FAKE_LIBC_DIR.exists():
        cpp_args = ['-nostdinc', f'-I{FAKE_LIBC_DIR.resolve()}']
        try:
            return parse_file(str(file_path), use_cpp=True, cpp_args=cpp_args)
        except Exception:
            pass

    text = file_path.read_text(encoding="utf-8")
    clean = clean_c_code_for_pycparser(text)
    clean = re.sub(r'#define\s+\w+.*?\n', '\n', clean)
    parser = c_parser.CParser()
    return parser.parse(clean)

def extract_d8_variables(ast: c_ast.FileAST) -> List[c_ast.Decl]:
    """
    Counts Decl nodes of kind TypeDecl/ArrayDecl/PtrDecl per D8:
      - Includes: globals, locals, loop-declared variables, parameters of function definitions,
        and struct/union members.
      - Excludes: parameters of prototypes (declaration only) and extern/typedef declarations.
    """
    counted_decls: List[c_ast.Decl] = []

    func_def_func_decls = set()
    for ext in ast.ext:
        if isinstance(ext, c_ast.FuncDef):
            if isinstance(ext.decl.type, c_ast.FuncDecl):
                func_def_func_decls.add(id(ext.decl.type))

    class VariableVisitor(c_ast.NodeVisitor):
        def __init__(self):
            self.in_prototype = False

        def visit_Decl(self, node):
            storage = node.storage or []
            if 'extern' in storage or 'typedef' in storage:
                return

            if isinstance(node.type, c_ast.FuncDecl):
                if id(node.type) not in func_def_func_decls:
                    old = self.in_prototype
                    self.in_prototype = True
                    self.generic_visit(node)
                    self.in_prototype = old
                    return

            if self.in_prototype:
                return

            t = node.type
            if isinstance(t, (c_ast.TypeDecl, c_ast.ArrayDecl, c_ast.PtrDecl)):
                if not isinstance(getattr(t, 'type', None), c_ast.FuncDecl):
                    counted_decls.append(node)

            self.generic_visit(node)

    v = VariableVisitor()
    v.visit(ast)
    return counted_decls

def extract_branch_count(ast: c_ast.FileAST) -> int:
    """Counts branch nodes: If, Switch, For, While, DoWhile per D9."""
    branches = 0
    class BranchVisitor(c_ast.NodeVisitor):
        def visit_If(self, node):
            nonlocal branches
            branches += 1
            self.generic_visit(node)
        def visit_Switch(self, node):
            nonlocal branches
            branches += 1
            self.generic_visit(node)
        def visit_For(self, node):
            nonlocal branches
            branches += 1
            self.generic_visit(node)
        def visit_While(self, node):
            nonlocal branches
            branches += 1
            self.generic_visit(node)
        def visit_DoWhile(self, node):
            nonlocal branches
            branches += 1
            self.generic_visit(node)
    BranchVisitor().visit(ast)
    return branches

def extract_loop_bound_from_ast(ast: c_ast.FileAST) -> int:
    """Extracts the largest constant upper bound across loop conditions in the AST."""
    bounds = []
    class LoopVisitor(c_ast.NodeVisitor):
        def _check_cond(self, cond):
            if cond is None:
                return
            if isinstance(cond, c_ast.BinaryOp):
                if cond.op in ('<', '<=', '!=', '=='):
                    if isinstance(cond.right, c_ast.Constant):
                        try:
                            bounds.append(int(cond.right.value, 0))
                        except Exception:
                            pass
                elif cond.op in ('>', '>='):
                    if isinstance(cond.left, c_ast.Constant):
                        try:
                            bounds.append(int(cond.left.value, 0))
                        except Exception:
                            pass
                elif cond.op in ('&&', '||'):
                    self._check_cond(cond.left)
                    self._check_cond(cond.right)

        def visit_For(self, node):
            self._check_cond(node.cond)
            self.generic_visit(node)

        def visit_While(self, node):
            self._check_cond(node.cond)
            self.generic_visit(node)

        def visit_DoWhile(self, node):
            self._check_cond(node.cond)
            self.generic_visit(node)

    LoopVisitor().visit(ast)
    return max(bounds) if bounds else 0


# =============================================================================
# 1. Group A Visitor (Source Program Structure - C1, D8, D9)
# =============================================================================

class SourceStructureVisitor(c_ast.NodeVisitor):
    def __init__(self, trace_list: Optional[List[Dict[str, Any]]] = None):
        self.num_instructions = 0
        self.num_branches = 0
        self.num_loops = 0
        self.num_functions = 0
        self.num_arrays = 0
        self.num_structure = 0
        self.num_union = 0
        self.trace_list = trace_list

    def _record(self, feature: str, node: Any):
        if self.trace_list is not None:
            coord = getattr(node, 'coord', None)
            line = coord.line if coord else -1
            self.trace_list.append({
                "feature": feature,
                "node_type": type(node).__name__,
                "line": line
            })

    def visit_FuncDef(self, node):
        self.num_functions += 1
        self._record("num_functions", node)
        self.generic_visit(node)

    def visit_Decl(self, node):
        storage = node.storage or []
        if 'extern' in storage or 'typedef' in storage:
            return

        if isinstance(node.type, c_ast.ArrayDecl):
            self.num_arrays += 1
            self._record("num_arrays", node)
        elif isinstance(node.type, c_ast.TypeDecl):
            if isinstance(node.type.type, c_ast.Struct):
                self.num_structure += 1
                self._record("num_structure", node)
            elif isinstance(node.type.type, c_ast.Union):
                self.num_union += 1
                self._record("num_union", node)
        elif isinstance(node.type, c_ast.Struct):
            self.num_structure += 1
            self._record("num_structure", node)
        elif isinstance(node.type, c_ast.Union):
            self.num_union += 1
            self._record("num_union", node)

        self.generic_visit(node)

    def visit_Assignment(self, node):
        self.num_instructions += 1
        self._record("num_instructions", node)
        self.generic_visit(node)

    def visit_FuncCall(self, node):
        self.num_instructions += 1
        self._record("num_instructions", node)
        self.generic_visit(node)

    def visit_If(self, node):
        self.num_branches += 1
        self.num_instructions += 1
        self._record("num_branches", node)
        self._record("num_instructions", node)
        self.generic_visit(node)

    def visit_Switch(self, node):
        self.num_branches += 1
        self._record("num_branches", node)
        self.generic_visit(node)

    def visit_For(self, node):
        self.num_loops += 1
        self.num_branches += 1
        self._record("num_loops", node)
        self._record("num_branches", node)
        self.generic_visit(node)

    def visit_While(self, node):
        self.num_loops += 1
        self.num_branches += 1
        self._record("num_loops", node)
        self._record("num_branches", node)
        self.generic_visit(node)

    def visit_DoWhile(self, node):
        self.num_loops += 1
        self.num_branches += 1
        self._record("num_loops", node)
        self._record("num_branches", node)
        self.generic_visit(node)

    def visit_Return(self, node):
        self.num_instructions += 1
        self._record("num_instructions", node)
        self.generic_visit(node)


def extract_group_a_features(source_c_path: Path, debug: bool = False) -> Dict[str, Any]:
    """
    Extracts Group A features from the SOURCE C file (C1).
    Applies D8 variable filtering (excluding prototypes/extern, including libc exclusion).
    """
    source_c_path = Path(source_c_path).resolve()
    assert source_c_path.exists(), f"Source file does not exist: {source_c_path}"

    text = source_c_path.read_text(encoding="utf-8")
    loc = len(text.splitlines())

    ast = parse_c_ast(source_c_path)

    trace_records: List[Dict[str, Any]] = [] if debug else None
    visitor = SourceStructureVisitor(trace_list=trace_records)
    visitor.visit(ast)

    vars_counted = extract_d8_variables(ast)
    num_variables = len(vars_counted)

    max_loop_bound = extract_loop_bound_from_ast(ast)
    loop_to_unwind_ratio = round(max_loop_bound / 5.0, 4)

    res = {
        "loc": loc,
        "num_instructions": visitor.num_instructions,
        "num_branches": visitor.num_branches,
        "num_loops": visitor.num_loops,
        "num_functions": visitor.num_functions,
        "num_variables": num_variables,
        "num_arrays": visitor.num_arrays,
        "num_structure": visitor.num_structure,
        "num_union": visitor.num_union,
        "loop_to_unwind_ratio": loop_to_unwind_ratio,
    }
    if debug:
        res["_trace"] = trace_records
    return res


# =============================================================================
# 2. Group B Extraction (Miter AST Security & Taint Propagation - C2, C3, D1-D5)
# =============================================================================

def validate_miter(miter_c_path: Optional[Path], high_vars: Set[str]) -> c_ast.FileAST:
    """
    Validates miter file per Phase 1:
      - Must exist and not be empty
      - Must parse successfully
      - Must declare suffixed seed variables (_1, _2) for every high_var
    Raises FileNotFoundError, ValueError, or RuntimeError on failure.
    """
    if miter_c_path is None:
        raise FileNotFoundError("Miter file path must be provided (no silent fallback).")
    miter_path = Path(miter_c_path).resolve()
    if not miter_path.exists():
        raise FileNotFoundError(f"Miter file does not exist: {miter_path}")
    if miter_path.stat().st_size == 0:
        raise ValueError(f"Miter file is empty: {miter_path}")

    try:
        miter_ast = parse_c_ast(miter_path)
    except Exception as e:
        raise RuntimeError(f"Failed to parse miter file {miter_path.name}: {e}")

    # Collect all declared variable names in the miter AST
    declared = set()
    class DeclCollector(c_ast.NodeVisitor):
        def visit_Decl(self, node):
            if node.name:
                declared.add(node.name)
            self.generic_visit(node)
    DeclCollector().visit(miter_ast)

    for hv in high_vars:
        for suffix in ("_1", "_2"):
            expected = f"{hv}{suffix}"
            if expected not in declared:
                raise ValueError(
                    f"Miter file {miter_path.name} does not declare suffixed seed variable '{expected}' for high variable '{hv}'"
                )

    return miter_ast

def extract_ids(expr_node: Any) -> Set[str]:
    """
    Extracts variable IDs from an expression per D1:
      - Field-insensitive: StructRef extracts the base struct variable, NOT the field name.
      - Function calls: extracts argument IDs, NOT the function name.
    """
    ids: Set[str] = set()
    if expr_node is None:
        return ids
    if isinstance(expr_node, c_ast.ID):
        ids.add(expr_node.name)
    elif isinstance(expr_node, c_ast.StructRef):
        ids |= extract_ids(expr_node.name)
    elif isinstance(expr_node, c_ast.ArrayRef):
        ids |= extract_ids(expr_node.name)
        ids |= extract_ids(expr_node.subscript)
    elif isinstance(expr_node, c_ast.UnaryOp):
        ids |= extract_ids(expr_node.expr)
    elif isinstance(expr_node, c_ast.BinaryOp):
        ids |= extract_ids(expr_node.left)
        ids |= extract_ids(expr_node.right)
    elif isinstance(expr_node, c_ast.FuncCall):
        if expr_node.args:
            for a in expr_node.args.exprs:
                ids |= extract_ids(a)
    elif isinstance(expr_node, c_ast.Cast):
        ids |= extract_ids(expr_node.expr)
    elif isinstance(expr_node, c_ast.ExprList):
        for e in expr_node.exprs:
            ids |= extract_ids(e)
    elif isinstance(expr_node, c_ast.TernaryOp):
        ids |= extract_ids(expr_node.cond)
        ids |= extract_ids(expr_node.iftrue)
        ids |= extract_ids(expr_node.iffalse)
    return ids

def get_lvalue_base(lval: Any) -> Optional[str]:
    """Extracts the root base identifier of an lvalue (K25, D1)."""
    if isinstance(lval, c_ast.ID):
        return lval.name
    elif isinstance(lval, c_ast.StructRef):
        return get_lvalue_base(lval.name)
    elif isinstance(lval, c_ast.ArrayRef):
        return get_lvalue_base(lval.name)
    elif isinstance(lval, c_ast.UnaryOp):
        return get_lvalue_base(lval.expr)
    return None


def extract_group_b_features(
    source_c_path: Path,
    input_json_path: Path,
    miter_c_path: Path,
    debug: bool = False
) -> Dict[str, Any]:
    """
    Extracts Group B features from the MITER C file (C2, C3, D1-D5).
    Seeds taint from suffixed copies of high_vars.
    Propagates taint to fixpoint across all FuncDefs with call-argument binding.
    """
    with open(input_json_path, "r", encoding="utf-8") as f:
        meta = json.load(f)

    input_vars = set(meta.get("input_vars", []))
    high_vars = set(meta.get("high_vars", []))
    low_vars = set(meta.get("low_vars", [v for v in input_vars if v not in high_vars]))

    # Phase 1: Validate miter strictly (loud failures, no silent fallback)
    ast_miter = validate_miter(miter_c_path, high_vars)

    # 1. Map function definitions and parameter lists for call-argument binding (D1, K6)
    func_param_map: Dict[str, List[str]] = {}
    func_defs: List[c_ast.FuncDef] = []
    func_returns: Dict[str, List[Any]] = {}
    for ext in ast_miter.ext:
        if isinstance(ext, c_ast.FuncDef):
            func_defs.append(ext)
            fn_name = ext.decl.name
            params = []
            if ext.decl.type and ext.decl.type.args:
                for p in ext.decl.type.args.params:
                    if isinstance(p, c_ast.Decl) and p.name:
                        params.append(p.name)
            func_param_map[fn_name] = params

            rets = []
            class RetCollector(c_ast.NodeVisitor):
                def visit_Return(self, node):
                    if node.expr:
                        rets.append(node.expr)
                    self.generic_visit(node)
            RetCollector().visit(ext)
            func_returns[fn_name] = rets

    miter_global_vars = set()
    for ext in ast_miter.ext:
        if isinstance(ext, c_ast.Decl) and ext.name and ext.name not in LIBC_SYMBOLS:
            if not isinstance(ext.type, c_ast.FuncDecl):
                miter_global_vars.add(ext.name)

    formal_params: Set[str] = set()
    for p_list in func_param_map.values():
        formal_params.update(p_list)

    # 2. Initialize seeds: suffixed copies of high_vars (C2, D1)
    seeds: Set[str] = set()
    for hv in high_vars:
        seeds.add(f"{hv}_1")
        seeds.add(f"{hv}_2")

    tainted_vars: Set[str] = set(seeds)
    dep_graph: Dict[str, Set[str]] = {}

    def add_dep(dest: str, sources: List[str]):
        if not dest:
            return
        if dest not in dep_graph:
            dep_graph[dest] = set()
        for s in sources:
            if s and s != dest:
                dep_graph[dest].add(s)

    # 3. Fixpoint Taint Propagation Loop (D1)
    while True:
        before = set(tainted_vars)

        class TaintPropagator(c_ast.NodeVisitor):
            def visit_Assignment(self, node):
                rhs_ids = extract_ids(node.rvalue)
                is_compound = node.op != '='
                lhs_ids = extract_ids(node.lvalue) if is_compound else set()
                used_ids = rhs_ids | lhs_ids
                base = get_lvalue_base(node.lvalue)
                tainted_used = [v for v in used_ids if v in tainted_vars]
                if tainted_used:
                    if base:
                        tainted_vars.add(base)
                        add_dep(base, tainted_used)

                if isinstance(node.rvalue, c_ast.FuncCall):
                    called_fn = node.rvalue.name.name if isinstance(node.rvalue.name, c_ast.ID) else None
                    if called_fn and called_fn in func_returns:
                        for ret_expr in func_returns[called_fn]:
                            ret_ids = extract_ids(ret_expr)
                            tainted_ret = [v for v in ret_ids if v in tainted_vars]
                            if tainted_ret and base:
                                tainted_vars.add(base)
                                add_dep(base, tainted_ret)

                self.generic_visit(node)

            def visit_Decl(self, node):
                if node.init:
                    rhs_ids = extract_ids(node.init)
                    tainted_rhs = [v for v in rhs_ids if v in tainted_vars]
                    if tainted_rhs and node.name:
                        tainted_vars.add(node.name)
                        add_dep(node.name, tainted_rhs)
                    if isinstance(node.init, c_ast.FuncCall):
                        called_fn = node.init.name.name if isinstance(node.init.name, c_ast.ID) else None
                        if called_fn and called_fn in func_returns:
                            for ret_expr in func_returns[called_fn]:
                                ret_ids = extract_ids(ret_expr)
                                tainted_ret = [v for v in ret_ids if v in tainted_vars]
                                if tainted_ret and node.name:
                                    tainted_vars.add(node.name)
                                    add_dep(node.name, tainted_ret)
                self.generic_visit(node)

            def visit_FuncCall(self, node):
                # Formal parameter binding by position (D1)
                fn_name = node.name.name if isinstance(node.name, c_ast.ID) else None
                if fn_name and fn_name in func_param_map:
                    params = func_param_map[fn_name]
                    if node.args and node.args.exprs:
                        for idx, arg in enumerate(node.args.exprs):
                            if idx < len(params):
                                arg_ids = extract_ids(arg)
                                tainted_arg_ids = [v for v in arg_ids if v in tainted_vars]
                                if tainted_arg_ids:
                                    param_name = params[idx]
                                    tainted_vars.add(param_name)
                                    add_dep(param_name, tainted_arg_ids)
                self.generic_visit(node)

        for fd in func_defs:
            TaintPropagator().visit(fd)

        if tainted_vars == before:
            break

    # 4. Counting Pass using fixpoint tainted_vars
    num_explicit_flows = 0
    clean_vars_tainted: Set[str] = set()
    num_culprit_blocks = 0
    num_implicit_flows = 0
    num_secret_dependent_prints = 0
    num_array_accesses = 0
    secret_indexed_array_accesses = 0
    num_assumptions = 0
    num_assertions = 0
    num_tainted_returns = 0
    num_secret_bitops = 0

    class FinalCounterVisitor(c_ast.NodeVisitor):
        def visit_Assignment(self, node):
            nonlocal num_explicit_flows, num_secret_bitops
            rhs_ids = extract_ids(node.rvalue)
            is_compound = node.op != '='
            lhs_ids = extract_ids(node.lvalue) if is_compound else set()
            if any(v in tainted_vars for v in rhs_ids) or any(v in tainted_vars for v in lhs_ids):
                num_explicit_flows += 1
                base = get_lvalue_base(node.lvalue)
                if base and base not in seeds and base not in formal_params:
                    clean_vars_tainted.add(base)
            if node.op in BITWISE_ASSIGN_OPS and (any(v in tainted_vars for v in lhs_ids) or any(v in tainted_vars for v in rhs_ids)):
                num_secret_bitops += 1
            self.generic_visit(node)

        def visit_Decl(self, node):
            nonlocal num_explicit_flows
            if node.init:
                rhs_ids = extract_ids(node.init)
                if any(v in tainted_vars for v in rhs_ids):
                    num_explicit_flows += 1
                    if node.name and node.name not in seeds and node.name not in formal_params:
                        clean_vars_tainted.add(node.name)
            self.generic_visit(node)

        def visit_Return(self, node):
            nonlocal num_tainted_returns
            if node.expr:
                ret_ids = extract_ids(node.expr)
                if any(v in tainted_vars for v in ret_ids):
                    num_tainted_returns += 1
            self.generic_visit(node)

        def visit_BinaryOp(self, node):
            nonlocal num_secret_bitops
            if node.op in BITWISE_OPS:
                left_ids = extract_ids(node.left)
                right_ids = extract_ids(node.right)
                if any(v in tainted_vars for v in left_ids) or any(v in tainted_vars for v in right_ids):
                    num_secret_bitops += 1
            self.generic_visit(node)

        def _count_implicit_statements(self, block_node) -> int:
            """Counts simple statements inside culprit blocks per D3."""
            count = 0
            if block_node is None:
                return 0
            items = block_node.block_items or [] if isinstance(block_node, c_ast.Compound) else [block_node]
            for item in items:
                if isinstance(item, c_ast.Assignment):
                    count += 1
                elif isinstance(item, c_ast.UnaryOp) and item.op in ('++', '--', 'p++', 'p--'):
                    count += 1
                elif isinstance(item, c_ast.Return):
                    count += 1
                elif isinstance(item, c_ast.FuncCall):
                    fn_name = item.name.name if isinstance(item.name, c_ast.ID) else ""
                    if fn_name not in ("assert", "__CPROVER_assume"):
                        count += 1
                elif isinstance(item, c_ast.If):
                    count += 1 + self._count_implicit_statements(item.iftrue) + self._count_implicit_statements(item.iffalse)
                elif isinstance(item, (c_ast.While, c_ast.DoWhile, c_ast.For)):
                    count += 1 + self._count_implicit_statements(item.stmt)
            return count

        def visit_If(self, node):
            nonlocal num_culprit_blocks, num_implicit_flows
            cond_ids = extract_ids(node.cond)
            if any(v in tainted_vars for v in cond_ids):
                num_culprit_blocks += 1
                num_implicit_flows += self._count_implicit_statements(node.iftrue)
                if node.iffalse:
                    num_implicit_flows += self._count_implicit_statements(node.iffalse)
            self.generic_visit(node)

        def visit_While(self, node):
            nonlocal num_culprit_blocks, num_implicit_flows
            cond_ids = extract_ids(node.cond)
            if any(v in tainted_vars for v in cond_ids):
                num_culprit_blocks += 1
                num_implicit_flows += self._count_implicit_statements(node.stmt)
            self.generic_visit(node)

        def visit_DoWhile(self, node):
            nonlocal num_culprit_blocks, num_implicit_flows
            cond_ids = extract_ids(node.cond)
            if any(v in tainted_vars for v in cond_ids):
                num_culprit_blocks += 1
                num_implicit_flows += self._count_implicit_statements(node.stmt)
            self.generic_visit(node)

        def visit_For(self, node):
            nonlocal num_culprit_blocks, num_implicit_flows
            cond_ids = extract_ids(node.cond)
            if any(v in tainted_vars for v in cond_ids):
                num_culprit_blocks += 1
                num_implicit_flows += self._count_implicit_statements(node.stmt)
            self.generic_visit(node)

        def visit_Switch(self, node):
            nonlocal num_culprit_blocks, num_implicit_flows
            cond_ids = extract_ids(node.cond)
            if any(v in tainted_vars for v in cond_ids):
                num_culprit_blocks += 1
                num_implicit_flows += self._count_implicit_statements(node.stmt)
            self.generic_visit(node)

        def visit_FuncCall(self, node):
            nonlocal num_secret_dependent_prints, num_assumptions, num_assertions
            fn_name = node.name.name if isinstance(node.name, c_ast.ID) else ""
            if fn_name == "assert":
                num_assertions += 1
            elif fn_name == "__CPROVER_assume":
                num_assumptions += 1
            elif fn_name in PRINT_FUNCS:
                arg_ids = set()
                if node.args and node.args.exprs:
                    for a in node.args.exprs:
                        arg_ids |= extract_ids(a)
                if any(v in tainted_vars for v in arg_ids):
                    num_secret_dependent_prints += 1
            self.generic_visit(node)

        def visit_ArrayRef(self, node):
            nonlocal num_array_accesses, secret_indexed_array_accesses
            num_array_accesses += 1
            sub_ids = extract_ids(node.subscript)
            if any(v in tainted_vars for v in sub_ids):
                secret_indexed_array_accesses += 1
            self.generic_visit(node)

    FinalCounterVisitor().visit(ast_miter)

    # 5. Calculate max_taint_depth (longest acyclic path from seeds in dep_graph)
    depth_memo: Dict[str, int] = {}
    def get_depth(node: str, visited_path: Set[str]) -> int:
        if node in seeds:
            return 0
        if node in depth_memo:
            return depth_memo[node]
        if node not in dep_graph or not dep_graph[node]:
            return 0
        max_d = 0
        for parent in dep_graph[node]:
            if parent in visited_path:
                continue
            d = get_depth(parent, visited_path | {parent})
            if d + 1 > max_d:
                max_d = d + 1
        depth_memo[node] = max_d
        return max_d

    non_seed_tainted = [v for v in tainted_vars if v not in seeds]
    max_taint_depth = max([get_depth(v, {v}) for v in non_seed_tainted]) if non_seed_tainted else 0

    # 6. Global variables tainted
    tainted_miter_globals = {g for g in miter_global_vars if g in tainted_vars}
    unique_base_globals = {re.sub(r'_[12]$', '', g) for g in tainted_miter_globals}
    num_tainted_globals = len(unique_base_globals)

    # 7. Internal miter-side counters for D2 ratios
    miter_variables = len(extract_d8_variables(ast_miter))
    miter_branches = extract_branch_count(ast_miter)

    return {
        "num_high_inputs": len(high_vars),
        "num_low_inputs": len(low_vars),
        "num_explicit_flows": num_explicit_flows,
        "num_culprit_blocks": num_culprit_blocks,
        "num_implicit_flows": num_implicit_flows,
        "num_information_leak": len(clean_vars_tainted),
        "num_secret_dependent_prints": num_secret_dependent_prints,
        "num_assumptions": num_assumptions,
        "num_assertions": num_assertions,
        "num_array_accesses": num_array_accesses,
        "num_tainted_returns": num_tainted_returns,
        "num_tainted_globals": num_tainted_globals,
        "max_taint_depth": max_taint_depth,
        "num_secret_bitops": num_secret_bitops,
        # Internal counters for ratio calculation (D2)
        "_miter_variables": miter_variables,
        "_miter_branches": miter_branches,
        "_secret_indexed_array_accesses": secret_indexed_array_accesses,
        "_tainted_vars": list(tainted_vars)
    }


# =============================================================================
# 3. Unified Extractor & Ratio Computation (D2)
# =============================================================================

def extract_all_mqil_features(
    source_c_path: Path,
    input_json_path: Path,
    miter_c_path: Path,
    debug: bool = False
) -> Dict[str, Any]:
    """
    Extracts the complete frozen 22-feature vector:
      - Group A measured on SOURCE
      - Group B measured on MITER
      - Ratios computed from miter-side internal counters per D2
    """
    source_c_path = Path(source_c_path).resolve()
    input_json_path = Path(input_json_path).resolve()
    miter_c_path = Path(miter_c_path).resolve()

    group_a = extract_group_a_features(source_c_path, debug=debug)
    group_b_full = extract_group_b_features(source_c_path, input_json_path, miter_c_path, debug=debug)

    miter_vars = max(group_b_full["_miter_variables"], 1)
    miter_branches = max(group_b_full["_miter_branches"], 1)
    arr_acc_count = max(group_b_full["num_array_accesses"], 1)

    # Ratios per D2 (guaranteed in [0, 1])
    taint_ratio = round(group_b_full["num_information_leak"] / miter_vars, 4)
    secret_branch_ratio = round(group_b_full["num_culprit_blocks"] / miter_branches, 4)
    secret_memory_ratio = round(group_b_full["_secret_indexed_array_accesses"] / arr_acc_count, 4)

    # Clean internal keys
    group_b = {k: v for k, v in group_b_full.items() if not k.startswith("_")}

    result = {
        **group_a,
        **group_b,
        "taint_ratio": taint_ratio,
        "secret_branch_ratio": secret_branch_ratio,
        "secret_memory_ratio": secret_memory_ratio
    }

    # Ensure exact frozen ordering and schema
    ordered_features = {k: result[k] for k in FEATURE_COLS}
    return ordered_features


class ProgramFeatureExtractor:
    """High-level interface for extracting program security features for ML models."""
    def __init__(self, fake_libc_dir: Optional[Path] = None):
        self.fake_libc_dir = fake_libc_dir or FAKE_LIBC_DIR

    def extract_features(
        self,
        source_c_path: Union[str, Path],
        input_json_path: Optional[Union[str, Path]] = None,
        miter_c_path: Optional[Union[str, Path]] = None
    ) -> Dict[str, Any]:
        source_path = Path(source_c_path).resolve()
        assert source_path.exists(), f"Source file does not exist: {source_path}"

        if input_json_path is None:
            candidate = source_path.with_suffix(".json")
            if candidate.exists():
                json_path = candidate
            elif (source_path.parent / "custom.json").exists():
                json_path = source_path.parent / "custom.json"
            else:
                json_path = source_path.parent / "input_args.json"
        else:
            json_path = Path(input_json_path).resolve()

        assert json_path.exists(), f"Input specification JSON does not exist: {json_path}"

        if miter_c_path is None:
            candidates = [
                source_path.with_name(f"{source_path.stem}_miter.c"),
                source_path.parent / "custom_miter.c",
                source_path.parent / "o_miter.c"
            ]
            miter_path = None
            for c in candidates:
                if c.exists():
                    miter_path = c
                    break
            if miter_path is None:
                from src.core.transpiler import generate_miter_program
                miter_path = source_path.parent / f"{source_path.stem}_miter.c"
                generate_miter_program(source_path, json_path, miter_path)
        else:
            miter_path = Path(miter_c_path).resolve()

        assert miter_path.exists(), f"Miter file does not exist: {miter_path}"

        return extract_all_mqil_features(source_path, json_path, miter_path)
