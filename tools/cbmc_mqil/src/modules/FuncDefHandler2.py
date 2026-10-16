from copy import deepcopy
from modules.ContainsFuncCall import ContainsFuncCall
from modules.Renamer import Renamer
from pycparser import c_ast as cast
import modules.globals as globals


class FuncDefHandler(cast.NodeVisitor):
    def __init__(self, org, copy, copy_type) -> None:
        super().__init__()
        self.org = org
        self.copy = copy
        if copy_type == 2:
            # func_arguments = [
            #     arg.name for arg in self.org.decl.type.args.params]
            func_arguments = []
        elif copy_type == None:
            func_arguments = []
        else:
            raise Exception("Undefined copy type")
        print(f"Creating {org.decl.type.type.declname}_{copy_type}")
        self.renamer_avoided_ids = func_arguments
        self.rename_1 = Renamer(1, func_arguments).visit
        self.rename_2 = Renamer(2, func_arguments).visit
        self.copy_type = copy_type

    def is_loop(self, item):
        return isinstance(item, (cast.While, cast.DoWhile, cast.For))

    def generate_loop_copy(self, item):
        new_cond = self.merged_cond(item)
        new_body = deepcopy(item.stmt)
        self.visit(new_body)
        new_loop = deepcopy(item)
        new_loop.cond = new_cond
        new_loop.stmt = new_body
        if isinstance(item, cast.For):
            for_update = self.make_copy(item.next)
            new_loop.next = cast.ExprList(exprs=for_update)
            new_init = self.make_copy(item.init)
            new_decls = []
            for decl in new_init:
                if isinstance(decl, cast.DeclList):
                    # Ex: for (int i=0,j=0; ...)
                    new_decls.extend(decl.decls)
                elif isinstance(decl, cast.ExprList):
                    # Ex: for (i=0,j=2; ...)
                    new_decls.extend(decl.exprs)
                else:
                    # Ex: for (int i = 0) or for (i = 2)
                    # Case 1: cast.Decl,  Case 2: cast.Assignment
                    new_decls.append(decl)
            new_loop.init = cast.DeclList(decls=new_decls) if isinstance(
                item.init, (cast.Decl, cast.DeclList)) else cast.ExprList(exprs=new_decls)
        return new_loop

    def add_arguments(self):
        # Bug ID: K3 - main in miter is parameterless / void
        fn_name = getattr(self.copy.decl, 'name', None) or getattr(getattr(self.copy.decl.type, 'type', None), 'declname', None)
        if fn_name == 'main':
            self.copy.decl.type.type.type.names[0] = 'void'
            self.copy.decl.type.args = None
            return

        self.copy.decl.type.type.type.names[0] = 'void'
        try:
            copy_paramlist = self.copy.decl.type.args.params
            org_paramlist = self.org.decl.type.args.params
        except AttributeError:
            copy_paramlist = []
            org_paramlist = []

        # If parameter list is just (void), do not duplicate or rename to None_1, None_2
        if len(org_paramlist) == 1:
            p = org_paramlist[0]
            if isinstance(p, cast.Typename) and getattr(getattr(p, 'type', None), 'type', None) and p.type.type.names == ['void']:
                return
            if isinstance(p, cast.Decl) and isinstance(p.type, cast.TypeDecl) and getattr(p.type, 'declname', None) is None and getattr(getattr(p.type, 'type', None), 'names', None) == ['void']:
                return

        for item in copy_paramlist:
            self.rename_1(item)

        for item in org_paramlist:
            new_item = deepcopy(item)
            self.rename_2(new_item)
            copy_paramlist.append(new_item)

    def make_copy(self, node):
        for attr_name in dir(node):
            if isinstance(node, cast.If):
                break
            elif isinstance(node, cast.Switch):
                break
            if isinstance(getattr(node, attr_name), cast.Compound):
                self.visit(node)
                return [node]
        copy1 = deepcopy(node)
        self.rename_1(copy1)
        copy2 = deepcopy(node)
        self.rename_2(copy2)
        return [copy1, copy2]

    def handle_func_call(self, func_call):
        call_1 = deepcopy(func_call)
        renamer = Renamer(1, [func_call.name.name]+self.renamer_avoided_ids)
        renamer.visit(call_1)
        call_2 = deepcopy(func_call)
        renamer = Renamer(2, [func_call.name.name]+self.renamer_avoided_ids)
        renamer.visit(call_2)

        # Bug ID: K4 (D6) - No undefined printf_2 / assert_2 / scanf_2 / exit_2 helper calls
        fn_name = func_call.name.name
        EXTERNAL_CALLS = {
            'printf', 'scanf', 'exit', 'assert', 'puts', 'putchar', 'getchar',
            'fprintf', 'sprintf', 'snprintf', 'malloc', 'calloc', 'realloc', 'free',
            'abort', 'abs', 'labs', 'rand', 'srand'
        }
        if fn_name in EXTERNAL_CALLS or fn_name not in globals.original_funcs:
            return [call_1, call_2]

        call_3 = deepcopy(func_call)
        new_args = []
        if call_3.args is not None:
            for item in call_3.args.exprs:
                new_item = deepcopy(item)
                self.rename_1(item)
                self.rename_2(new_item)
                new_args.append(new_item)
            call_3.args.exprs.extend(new_args)
        call_3.name.name = f"{func_call.name.name}_2"
        return [call_1, call_2, call_3]

    def merged_cond(self, node):
        old_cond = node.cond
        cond1 = deepcopy(old_cond)
        cond2 = deepcopy(old_cond)
        self.rename_1(cond1)
        self.rename_2(cond2)
        return cast.BinaryOp(op='&&', left=cond1, right=cond2)

    def visit_Compound(self, node):
        original_block_items = node.block_items or []
        node.block_items = []
        for item in original_block_items:
            func_call_check = ContainsFuncCall()
            func_call_check.visit(item)
            if isinstance(item, cast.FuncCall):
                node.block_items.extend(self.handle_func_call(item))
                continue
            elif isinstance(item, cast.Return):
                continue
            elif self.is_loop(item):
                new_loop = self.generate_loop_copy(item)
                node.block_items.append(new_loop)
                continue
            else:
                copy_items = self.make_copy(item)
                node.block_items.extend(copy_items)
            if len(func_call_check.func_calls) != 0:
                for _, call in func_call_check.func_calls.items():
                    func_call_2 = self.make_func_call_2(call)
                    node.block_items.append(func_call_2)

    def make_func_call_2(self, func_call):
        new_call = deepcopy(func_call)
        new_call.name.name = f"{new_call.name.name}_2"
        if new_call.args is not None:
            self.rename_1(new_call.args)
            new_args = deepcopy(func_call.args)
            self.rename_2(new_args)
            for argument in new_args.exprs:
                new_call.args.exprs.append(argument)
        return new_call

    def add_body_items(self):
        self.visit(self.copy)

    def suffix_function_name(self, suffix):
        self.copy.decl.type.type.declname += suffix

    def process(self):
        if (self.copy_type == 3):
            raise Exception("No fn3 type")
            self.add_arguments()
            self.add_body_items()
        elif (self.copy_type == 2):
            self.add_arguments()
            self.add_body_items()
            # Make the return type void
            self.copy.decl.type.type.type.names.clear()
            self.copy.decl.type.type.type.names.append('void')
        if (self.org.decl.type.type.declname != 'main'):
            self.suffix_function_name(f'_{self.copy_type}')
