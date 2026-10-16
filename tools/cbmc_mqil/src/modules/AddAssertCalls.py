from copy import deepcopy
from modules.ContainsFuncCall import ContainsFuncCall
from modules.Renamer import Renamer
from pycparser import c_ast as cast
from modules.IdentifiersUsed import IdentifiersUsed
from modules.VariableType import VariableType
import modules.globals as globals
from modules.utils import assert_assume_calls, assert_assume_ptr_calls, for_loop_func_call, generate_empty_for_loop, struct_assert, union_assert


class AddAssertCalls(cast.NodeVisitor):
    def get_assert_loop(self, var_name, var_type, indices):
        if isinstance(var_type, cast.TypeDecl):
            if isinstance(var_type.type, cast.Struct):
                return struct_assert(var_name, var_type.type.name)
            elif isinstance(var_type.type, cast.Union):
                # Bug ID: K26 (D7) - Member-wise comparison for union variables
                return union_assert(var_name, var_type.type.name)
            return [assert_assume_calls(var_name, 'assert', '==', indices)]
        elif isinstance(var_type, cast.ArrayDecl):
            curr_idx = f"i_{len(indices)}"
            indices.append(curr_idx)
            curr_loop = generate_empty_for_loop(
                curr_idx, var_type.dim)
            curr_loop.stmt.block_items.extend(
                self.get_assert_loop(var_name, var_type.type, indices)
            )
            return [curr_loop]
        elif isinstance(var_type, cast.PtrDecl):
            return [assert_assume_ptr_calls(var_name, 'assert', '==')]

    def visit_FuncDef(self, node):
        if node.decl.type.type.declname in globals.original_funcs and node.decl.type.type.declname != 'main':
            return
        print(f"Adding assert calls in {node.decl.type.type.declname}")
        decl_var_types = VariableType(True)
        decl_var_types.visit(node.body)
        # Global vars that are not inputs might be used in the function,
        # hence add assert for them too
        ids_used = IdentifiersUsed()
        ids_used.visit(node)
        assert_vars = {}
        for global_var in globals.global_variables:
            if f"{global_var}_1" in ids_used.unmodified_names and f"{global_var}_2" in ids_used.unmodified_names:
                assert_vars[global_var] = globals.global_var_types[global_var]
        assert_vars = {**assert_vars, **(decl_var_types.decl_map)}
        for var_name, var_type in assert_vars.items():
            if var_name not in globals.input_var_map['input_vars']:
                node.body.block_items.extend(
                    self.get_assert_loop(
                        var_name, var_type, []
                    )
                )


# 'state': PtrDecl(quals=[
#               ],
#         type=TypeDecl(declname='state_2',
#                       quals=[
#                             ],
#                       align=None,
#                       type=Struct(name='buffer_state',
#                                   decls=None
#                                   )
#                       )
#         )}

# StructRef(name=UnaryOp(op='*',
#                        expr=ID(name='x')
#                        ),
#           type='.',
#           field=ID(name='len')
#           ),
#  rvalue=Constant(type='int',
#                  value='10'
#                  )
#  )
