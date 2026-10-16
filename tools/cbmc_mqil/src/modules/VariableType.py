from copy import deepcopy
from modules.ContainsFuncCall import ContainsFuncCall
from modules.Renamer import Renamer
from pycparser import c_ast as cast
import modules.globals as globals


class VariableType(cast.NodeVisitor):
    def __init__(self, all_decl=False) -> None:
        super().__init__()
        self.input_vars = globals.input_var_map['input_vars']
        self.all_decl = all_decl
        self.decl_map = {}

    def visit_Compound(self, node):
        if node.block_items:
            for item in node.block_items:
                if self.all_decl:
                    if isinstance(item, cast.Decl):
                        self.decl_map[item.name[:-2]] = deepcopy(item.type)
                else:
                    self.visit(item)

    def visit_FuncDef(self, node):
        if self.all_decl == False:
            globals.original_funcs.append(node.decl.type.type.declname)
            self.visit(node.body)

    def visit_Decl(self, node):
        if node.name in self.input_vars:
            globals.input_variable_types[node.name] = deepcopy(node.type)
