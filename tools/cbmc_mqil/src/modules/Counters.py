from pycparser import c_ast as cast


class VarCounter(cast.NodeVisitor):
    def __init__(self) -> None:
        super().__init__()
        self.count = 0

    def visit_Decl(self, node):
        if isinstance(node.type, (cast.TypeDecl, cast.ArrayDecl, cast.PtrDecl)):
            self.count += 1


class FuncCallCounter(cast.NodeVisitor):
    def __init__(self) -> None:
        super().__init__()
        self.count = 0

    def visit_FuncCall(self, node):
        self.count += 1
        if node.args is not None:
            self.visit(node.args)


class LoopCounter(cast.NodeVisitor):
    def __init__(self) -> None:
        super().__init__()
        self.count = 0

    def visit_For(self, node):
        self.count += 1
        self.visit(node.stmt)

    def visit_While(self, node):
        self.count += 1
        self.visit(node.stmt)

    def visit_DoWhile(self, node):
        self.count += 1
        self.visit(node.stmt)
