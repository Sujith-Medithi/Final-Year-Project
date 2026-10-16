from copy import deepcopy
from modules.ContainsFuncCall import ContainsFuncCall
from modules.Renamer import Renamer
from pycparser import c_ast as cast
import modules.globals as globals


class IdentifiersUsed(cast.NodeVisitor):
    def __init__(self) -> None:
        super().__init__()
        self.declarations = set()
        self.unmodified_names = set()

    def visit_ID(self, node):
        if len(node.name) >= 3:
            # -2 since _x is added to all variables in generated C code
            self.declarations.add(node.name[:-2])
        else:
            self.declarations.add(node.name)
        self.unmodified_names.add(node.name)

    def visit_Decl(self, node):
        if node.name:
            if len(node.name) >= 3:
                self.declarations.add(node.name[:-2])
            else:
                self.declarations.add(node.name)
            self.unmodified_names.add(node.name)
        self.generic_visit(node)

