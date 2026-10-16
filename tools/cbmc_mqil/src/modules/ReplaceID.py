from pycparser import c_ast as cast


class ReplaceID(cast.NodeVisitor):
    def __init__(self, find, replace) -> None:
        super().__init__()
        self.find = find
        self.replace = replace

    def visit_ID(self, node):
        if node.name == self.find:
            node.name = self.replace
