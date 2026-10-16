from copy import deepcopy
from modules.ContainsFuncCall import ContainsFuncCall
from modules.Renamer import Renamer
from pycparser import c_ast as cast
from modules.IdentifiersUsed import IdentifiersUsed
import modules.globals as globals
from modules.utils import assert_assume_calls, for_loop_func_call, generate_empty_for_loop


class AddAssumeCalls(cast.NodeVisitor):
    def get_assume_loop(self, var_name, var_type, bin_op, indices):
        if isinstance(var_type, cast.TypeDecl):
            return assert_assume_calls(var_name, '__CPROVER_assume', bin_op, indices)
        elif isinstance(var_type, cast.ArrayDecl):
            curr_idx = f"i_{len(indices)}"
            indices.append(curr_idx)
            curr_loop = generate_empty_for_loop(
                curr_idx, var_type.dim)
            curr_loop.stmt.block_items.append(
                self.get_assume_loop(var_name, var_type.type, bin_op, indices)
            )
            return curr_loop
        elif isinstance(var_type, cast.PtrDecl):
            # TODO: What if the pointer is a pointer to a struct
            assume_ptr = self.get_assume_loop(
                var_name, var_type.type, bin_op, indices)
            assume_ptr.args.exprs[0].left = cast.UnaryOp(
                "*", assume_ptr.args.exprs[0].left)
            assume_ptr.args.exprs[0].right = cast.UnaryOp(
                "*", assume_ptr.args.exprs[0].right)
            return assume_ptr
        else:
            raise Exception("Unhandled assume loop")

    def __init__(self) -> None:
        super().__init__()
        self.input_vars = set(globals.input_var_map['input_vars'])
        self.global_inputs = set(globals.input_var_map['input_vars']) & set(
            globals.global_variables)

    def visit_FuncDef(self, node):
        if node.decl.type.type.declname == 'main':
            for global_high in self.global_inputs:
                if global_high in globals.input_var_map['high_vars']:
                    bin_op = '!='
                else:
                    bin_op = '=='
                node.body.block_items.append(
                    self.get_assume_loop(
                        global_high,
                        globals.global_var_types[global_high],
                        bin_op,
                        []
                    )
                )

        # if node.decl.type.type.declname in globals.original_funcs and node.decl.type.type.declname != 'main':
        #     return
        vars_decl_visitor = IdentifiersUsed()
        vars_decl_visitor.visit(node)
        inputs_in_func = []
        try:
            func_arguments = [
                arg.name for arg in node.decl.type.args.params]
        except:
            func_arguments = []
        for var in self.input_vars:
            if f"{var}_1" in vars_decl_visitor.unmodified_names and f"{var}_2" in vars_decl_visitor.unmodified_names:
                if var in self.global_inputs and f"{var}_1" not in func_arguments and f"{var}_2" not in func_arguments:
                    print(
                        f"Found a global input {var} that is not an argument. So won't add assume in {node.decl.type.type.declname}")
                    continue
                inputs_in_func.append(var)

        for input_var in inputs_in_func:
            if input_var in globals.input_var_map['high_vars']:
                bin_op = '!='
            else:
                bin_op = '=='
            node.body.block_items.append(
                self.get_assume_loop(
                    input_var,
                    globals.input_variable_types[input_var],
                    bin_op,
                    []
                )
            )
