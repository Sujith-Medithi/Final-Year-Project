from copy import deepcopy
from modules.ContainsFuncCall import ContainsFuncCall
from modules.Renamer import Renamer
from pycparser import c_ast as cast
from modules.IdentifiersUsed import IdentifiersUsed
from modules.ReplaceID import ReplaceID
from modules.VariableType import VariableType
import modules.globals as globals
from modules.utils import assert_assume_calls, for_loop_func_call, generate_empty_for_loop


class AddNonDetCalls(cast.NodeVisitor):
    def __init__(self, global_high_inputs) -> None:
        super().__init__()
        self.global_high_inputs = global_high_inputs
        self.loop_idx = []

    def get_for_loop(self, var_type, var_name):
        if isinstance(var_type, cast.ArrayDecl):
            curr_idx = f"i_{len(self.loop_idx)}"
            self.loop_idx.append(curr_idx)
            curr_loop = generate_empty_for_loop(
                curr_idx, var_type.dim)
            curr_loop.stmt.block_items.append(
                self.get_for_loop(var_type.type, var_name))
            return curr_loop
        elif isinstance(var_type, cast.TypeDecl):
            if len(self.loop_idx) == 0:
                return cast.Assignment(
                    '=',
                    cast.ID(var_name),
                    cast.FuncCall(
                        cast.ID(f"nd_{var_name}"),
                        cast.ExprList([])
                    )
                )
            else:
                nested_arr_ref = cast.ID(var_name)
                for i in self.loop_idx:
                    nested_arr_ref = cast.ArrayRef(nested_arr_ref, cast.ID(i))
                return cast.Assignment(
                    '=',
                    nested_arr_ref,
                    cast.FuncCall(
                        cast.ID(f"nd_{var_name}"),
                        cast.ExprList([])
                    )
                )
        else:
            raise Exception("Unhandled type in AddNonDetCalls.py")

    def visit_FuncDef(self, node):
        self.loop_idx.clear()
        # Only _2 func copies or main function can contain copies of global variables
        # is_valid = ((node.decl.type.type.declname not in globals.original_funcs and node.decl.type.type.declname.endswith("_2"))
        #             or node.decl.type.type.declname == 'main')
        is_valid = node.decl.type.type.declname == 'main'
        if is_valid:
            id_finder = IdentifiersUsed()
            id_finder.visit(node)
            for global_high in self.global_high_inputs:
                self.loop_idx.clear()
                if True:
                    print(self.global_high_inputs)
                    # if global_high in id_finder.declarations:
                    global_type = globals.input_variable_types[global_high]
                    loop_2 = self.get_for_loop(global_type, global_high)
                    loop_1 = deepcopy(loop_2)
                    replacer = ReplaceID(global_high, f"{global_high}_2")
                    replacer.visit(loop_2)
                    replacer.replace = f"{global_high}_1"
                    replacer.visit(loop_1)
                    node.body.block_items.insert(
                        0, loop_2)
                    node.body.block_items.insert(
                        0, loop_1)
