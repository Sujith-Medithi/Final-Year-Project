from copy import deepcopy
from modules.Renamer import Renamer
from pycparser import c_ast as cast


class FuncDefHandler():
    def __init__(self, org, copy) -> None:
        self.org = org
        self.copy = copy
        self.rename_1 = Renamer(1).visit
        self.rename_2 = Renamer(2).visit

    def add_arguments(self):
        copy_paramlist = self.copy.decl.type.args.params
        org_paramlist = self.org.decl.type.args.params
        for item in copy_paramlist:
            self.rename_1(item)

        for item in org_paramlist:
            new_item = deepcopy(item)
            self.rename_2(new_item)
            copy_paramlist.append(new_item)

    def make_copy(self, node):
        copy1 = deepcopy(node)
        self.rename_1(copy1)
        copy2 = deepcopy(node)
        self.rename_2(copy2)
        self.copy.body.block_items.extend([copy1, copy2])

    def handle_func_call(self, func_call):
        copy_func = deepcopy(func_call)
        new_args = []
        for item in copy_func.args.exprs:
            new_item = deepcopy(item)
            self.rename_1(item)
            self.rename_2(new_item)
            new_args.append(new_item)
        copy_func.args.exprs.extend(new_args)
        self.copy.body.block_items.append(copy_func)
        print(func_call)

    def add_body_items(self):
        self.copy.body.block_items = []
        for item in self.org.body.block_items:
            if isinstance(item, cast.FuncCall):
                self.handle_func_call(item)
            else:
                self.make_copy(item)

    def process(self):
        self.add_arguments()
        self.add_body_items()
        pass
