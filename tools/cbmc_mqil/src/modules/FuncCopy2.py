from copy import deepcopy
from pycparser import c_ast as cast
import modules.globals as globals


class FuncCopy2Visitor(cast.NodeVisitor):
    def __init__(self) -> None:
        super().__init__()
        self.func_calls = []
        self.func_call_names = []

    def visit_FuncCall(self, node):
        if node.name.name in globals.original_funcs and node.name.name not in self.func_call_names:
            self.func_calls.append(deepcopy(node))
            self.func_call_names.append(node.name.name)

    def visit_FuncDef(self, node):
        self.func_calls.clear()
        self.visit(node.body)
        for func_call in self.func_calls:
            func_call.name.name = f"{func_call.name.name}_2"
            node.body.block_items.append(
                func_call
            )
