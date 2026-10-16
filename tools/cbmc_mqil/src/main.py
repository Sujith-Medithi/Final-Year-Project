import argparse
from copy import deepcopy
import os
from pycparser import parse_file, c_generator
from pycparser import c_ast as cast
from modules.AddAssertCalls import AddAssertCalls
from modules.AddAssumeCalls import AddAssumeCalls
from modules.AddNonDetCalls import AddNonDetCalls
from modules.FuncCopy2 import FuncCopy2Visitor
from modules.Renamer import Renamer
from modules.VariableType import VariableType
import modules.globals as globals
from modules.utils import add_nd_functions, file_exists, generate_c_file, get_global_vars, process_structs, read_json
from modules.FuncDefHandler2 import FuncDefHandler


if __name__ == "__main__":
    argparser = argparse.ArgumentParser()
    argparser.add_argument('filename',
                           default='../examples/test.c',
                           nargs='?',
                           help='name of file to parse')
    argparser.add_argument('input_args',
                           default='../examples/input_args.json',
                           nargs='?',
                           help='name of the json file containing input variables and high variables')
    argparser.add_argument('output_file',
                           default='../examples/output.c',
                           nargs='?',
                           help='name of destination output file')
    args = argparser.parse_args()
    file_exists(args.filename)
    file_exists(args.input_args)

    globals.input_var_map = read_json(args.input_args)

    fake_libc = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..', 'fake_libc'))
    cpp_args = []
    if os.path.isdir(fake_libc):
        cpp_args = ['-nostdinc', f'-I{fake_libc}']

    ast = parse_file(args.filename, use_cpp=True, cpp_args=cpp_args if cpp_args else None)
    globals.global_var_types = get_global_vars(ast)
    globals.global_variables = list(globals.global_var_types.keys())

    process_structs(ast)
    var_type_visitor = VariableType()
    var_type_visitor.visit(ast)

    copy_ast = deepcopy(ast)
    copy_ast_index = 0

    input_var_names = globals.input_var_map['high_vars']
    global_high_inputs = list(set(input_var_names) &
                              set(globals.global_variables))

    for index, item in enumerate(ast.ext):
        if isinstance(item, cast.FuncDef):
            handler = FuncDefHandler(
                item, copy_ast.ext[copy_ast_index], 2)
            handler.process()
            if (item.decl.type.type.declname != 'main'):
                # copy_ast_index += 1
                # handler = FuncDefHandler(item, deepcopy(item), 2)
                # handler.process()
                # copy_ast.ext.insert(copy_ast_index, handler.copy)
                copy_ast_index += 1
                # Add original function code (fn1)
                copy_ast.ext.insert(copy_ast_index, deepcopy(item))
        elif isinstance(item, (cast.Struct, cast.Union)):
            # Bug ID: K2 - Keep single definition of struct/union
            pass
        elif isinstance(item, cast.Decl):
            if isinstance(item.type, cast.FuncDecl):
                pass
            # Bug ID: K2 - Top-level struct/union definitions without variable declarations: keep exactly 1 copy
            elif isinstance(item.type, (cast.Struct, cast.Union)) and item.name is None:
                pass
            elif isinstance(item.type, cast.TypeDecl) and isinstance(item.type.type, (cast.Struct, cast.Union)) and item.name is None:
                pass
            else:
                copy_global_decl = deepcopy(item)
                renamer = Renamer('1')
                renamer.visit(copy_ast.ext[copy_ast_index])
                renamer.suffix = '2'
                renamer.visit(copy_global_decl)
                copy_ast_index += 1
                copy_ast.ext.insert(copy_ast_index, copy_global_decl)
                copy_ast_index += 1
                copy_global_decl = deepcopy(item)
                copy_ast.ext.insert(copy_ast_index, copy_global_decl)
        copy_ast_index += 1

    # func_copy_2_adder = FuncCopy2Visitor()
    # func_copy_2_adder.visit(copy_ast)

    assume_call_adder = AddAssumeCalls()
    assume_call_adder.visit(copy_ast)

    assert_call_adder = AddAssertCalls()
    assert_call_adder.visit(copy_ast)

    add_nd_functions(copy_ast, global_high_inputs)
    nd_call_adder = AddNonDetCalls(global_high_inputs)
    nd_call_adder.visit(copy_ast)

    generate_c_file(copy_ast, args.output_file)
