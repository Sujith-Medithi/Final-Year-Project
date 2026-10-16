from copy import deepcopy
from modules.Renamer import Renamer
from pycparser import c_ast as cast


class ContainsFuncCall(cast.NodeVisitor):
    def __init__(self) -> None:
        super().__init__()
        self.func_calls = {}

    def visit_FuncCall(self, node):
        if node.name.name not in self.func_calls:
            self.func_calls[node.name.name] = node
