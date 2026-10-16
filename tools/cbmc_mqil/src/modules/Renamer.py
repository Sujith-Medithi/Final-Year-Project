from pycparser import c_ast as cast


class Renamer(cast.NodeVisitor):
    def __init__(self, suffix, do_not_rename=[]) -> None:
        super().__init__()
        self.suffix = suffix
        self.no_rename = do_not_rename

    def new_name(self, old_name):
        return f"{old_name}_{self.suffix}"

    def visit_FuncCall(self, node):
        if node.args is not None:
            self.visit(node.args)

    def visit_StructRef(self, node):
        self.visit(node.name)

    def visit_Label(self, node):
        if (node.name not in self.no_rename):
            node.name = self.new_name(node.name)
        self.visit(node.stmt)

    def visit_Goto(self, node):
        if (node.name not in self.no_rename):
            node.name = self.new_name(node.name)

    def visit_Decl(self, node):
        if (node.name not in self.no_rename):
            node.name = self.new_name(node.name)
        self.visit(node.type)
        if (node.init is not None):
            self.visit(node.init)

    def visit_TypeDecl(self, node):
        if (node.declname not in self.no_rename):
            node.declname = self.new_name(node.declname)

    def visit_ID(self, node):
        if (node.name not in self.no_rename):
            node.name = self.new_name(node.name)
