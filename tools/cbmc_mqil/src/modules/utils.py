from copy import deepcopy
import json
import os
from pycparser import parse_file, c_generator
from pycparser import c_ast as cast
from modules.Renamer import Renamer
from modules.ReplaceID import ReplaceID
import modules.globals as globals


def file_exists(filename: str):
    """
    Check if a file exists and raise an exception if it doesn't.

    Args:
        filename: The name of the file to check.

    Raises:
        IOError: If the file does not exist.
    """
    if (not os.path.exists(filename)):
        raise IOError(f"File {filename} not found")


def read_json(filename: str) -> dict:
    """Read a JSON file and return the parsed content.

    Args:
        filename: The name of the JSON file to read.

    Returns:
        dict: The parsed content of the JSON file.

    Raises:
        IOError: If the file does not exist.
    """
    with open(filename) as file:
        json_map = json.load(file)
    return json_map


def read_json(filename: str) -> dict:
    """Read a JSON file and return the parsed content.

    Args:
        filename: The name of the JSON file to read.

    Returns:
        dict: The parsed content of the JSON file.

    Raises:
        IOError: If the file does not exist.
    """
    with open(filename) as file:
        json_map = json.load(file)
    return json_map


def generate_c_file(ast, output_path='../examples/output.c'):
    """
    Generate C code from the provided Abstract Syntax Tree (AST) using MyCGenerator,
    and save the generated code to the specified output file.

    Args:
        ast: The Abstract Syntax Tree (AST) to generate C code from.
        output_path: Path to the destination C file.
    """
    generator = c_generator.CGenerator()
    with open(output_path, 'w') as output_file:
        print(generator.visit(ast), file=output_file)


def get_global_vars(ast):
    globals = {}
    for item in ast.ext:
        if isinstance(item, cast.Decl) and isinstance(item.type, (cast.TypeDecl, cast.ArrayDecl)):
            globals[item.name] = deepcopy(item.type)
    return globals


def process_structs(ast):
    # Bug ID: K2 / K26 - Collect both struct and union definitions without corrupting globals
    for index, item in enumerate(ast.ext):
        if isinstance(item, cast.Decl):
            if isinstance(item.type, cast.Struct) and item.type.name and item.type.decls:
                globals.structs_declared[item.type.name] = deepcopy(item.type)
            elif isinstance(item.type, cast.TypeDecl) and isinstance(item.type.type, cast.Struct) and item.type.type.name and item.type.type.decls:
                globals.structs_declared[item.type.type.name] = deepcopy(item.type.type)
            elif isinstance(item.type, cast.Union) and item.type.name and item.type.decls:
                globals.unions_declared[item.type.name] = deepcopy(item.type)
            elif isinstance(item.type, cast.TypeDecl) and isinstance(item.type.type, cast.Union) and item.type.type.name and item.type.type.decls:
                globals.unions_declared[item.type.type.name] = deepcopy(item.type.type)


def for_loop_func_call(input_var, length, function_name, binary_op):
    idx_name = f"{input_var}_index"
    return cast.For(
        cast.DeclList(
            [
                cast.Decl(
                    idx_name, [], [], [], [],
                    cast.TypeDecl(
                        idx_name,
                        [],
                        None,
                        cast.IdentifierType(
                            ['int'],
                        )
                    ),
                    cast.Constant(
                        'int',
                        '0'
                    ),
                    None
                )
            ]
        ),
        cast.BinaryOp(
            '<',
            cast.ID(idx_name),
            cast.Constant(
                'int',
                f"{length}"
            )
        ),
        cast.UnaryOp(
            'p++',
            cast.ID(idx_name)
        ),
        cast.Compound([
            cast.FuncCall(
                cast.ID(function_name),
                cast.ExprList(
                    [
                        cast.BinaryOp(
                            binary_op,
                            cast.ArrayRef(
                                cast.ID(f"{input_var}_1"),
                                cast.ID(idx_name)
                            ),
                            cast.ArrayRef(
                                cast.ID(f"{input_var}_2"),
                                # Bug ID: K5 - cast.ID(idx_name) instead of string literal 'idx_name'
                                cast.ID(idx_name)
                            )
                        )
                    ]
                )
            )
        ])
    )


def composite_assert(var_name, comp_def):
    """
    Bug ID: K26 (D7) - Assert equality for struct or union member-wise.
    For array members, compare element-by-element; for pointers, dereference; for scalars, compare with ==.
    """
    assert_calls = []
    if not comp_def or not comp_def.decls:
        return assert_calls

    for member in comp_def.decls:
        m_name = member.name
        m_type = member.type

        if isinstance(m_type, cast.ArrayDecl):
            # Element by element comparison for arrays
            dim = m_type.dim
            loop_idx = f"i_{m_name}"
            arr_assert = cast.FuncCall(
                cast.ID('assert'),
                cast.ExprList([
                    cast.BinaryOp(
                        '==',
                        cast.ArrayRef(
                            cast.StructRef(cast.ID(f"{var_name}_1"), '.', cast.ID(m_name)),
                            cast.ID(loop_idx)
                        ),
                        cast.ArrayRef(
                            cast.StructRef(cast.ID(f"{var_name}_2"), '.', cast.ID(m_name)),
                            cast.ID(loop_idx)
                        )
                    )
                ])
            )
            loop = generate_empty_for_loop(loop_idx, dim)
            loop.stmt.block_items.append(arr_assert)
            assert_calls.append(loop)
        elif isinstance(m_type, cast.PtrDecl):
            assert_statement = cast.FuncCall(
                cast.ID('assert'),
                cast.ExprList([
                    cast.BinaryOp(
                        '==',
                        cast.UnaryOp('*', cast.StructRef(cast.ID(f"{var_name}_1"), '.', cast.ID(m_name))),
                        cast.UnaryOp('*', cast.StructRef(cast.ID(f"{var_name}_2"), '.', cast.ID(m_name)))
                    )
                ])
            )
            assert_calls.append(assert_statement)
        else:
            assert_statement = cast.FuncCall(
                cast.ID('assert'),
                cast.ExprList([
                    cast.BinaryOp(
                        '==',
                        cast.StructRef(cast.ID(f"{var_name}_1"), '.', cast.ID(m_name)),
                        cast.StructRef(cast.ID(f"{var_name}_2"), '.', cast.ID(m_name))
                    )
                ])
            )
            assert_calls.append(assert_statement)
    return assert_calls


def struct_assert(var_name, struct_name):
    struct_def = globals.structs_declared.get(struct_name)
    return composite_assert(var_name, struct_def)


def union_assert(var_name, union_name):
    # Bug ID: K26 (D7) - Member-wise comparison for unions
    union_def = globals.unions_declared.get(union_name)
    return composite_assert(var_name, union_def)



def assert_assume_ptr_calls(input_var, function_name, binary_op):
    return cast.FuncCall(
        cast.ID(function_name),
        cast.ExprList(
            [
                cast.BinaryOp(
                    binary_op,
                    cast.UnaryOp('*', cast.ID(f"{input_var}_1")),
                    cast.UnaryOp('*', cast.ID(f"{input_var}_2"))
                )
            ]
        )
    )


def assert_assume_calls(input_var, function_name, binary_op, indices=[]):
    if len(indices) != 0:
        nested_arr_ref = cast.ID(input_var)
        for i in indices:
            nested_arr_ref = cast.ArrayRef(nested_arr_ref, cast.ID(i))
        renamer = ReplaceID(input_var, f"{input_var}_2")
        nested_arr_ref2 = deepcopy(nested_arr_ref)
        renamer.visit(nested_arr_ref2)
        renamer.replace = f"{input_var}_1"
        renamer.visit(nested_arr_ref)
        return cast.FuncCall(
            cast.ID(function_name),
            cast.ExprList(
                [
                    cast.BinaryOp(
                        binary_op,
                        nested_arr_ref,
                        nested_arr_ref2
                    )
                ]
            )
        )
    return cast.FuncCall(
        cast.ID(function_name),
        cast.ExprList(
            [
                cast.BinaryOp(
                    binary_op,
                    cast.ID(f"{input_var}_1"),
                    cast.ID(f"{input_var}_2")
                )
            ]
        )
    )


def add_nd_functions(copy_ast, global_high_inputs):
    index = 0
    for i, item in enumerate(copy_ast.ext):
        if isinstance(item, cast.FuncDef):
            index = i
            break
    for global_high in global_high_inputs:
        global_type = globals.input_variable_types[global_high]
        while not isinstance(global_type, cast.TypeDecl):
            global_type = global_type.type
        # if isinstance(global_type, cast.TypeDecl):
        global_type.declname = f"nd_{global_high}"
        # elif isinstance(global_type, cast.ArrayDecl):
        #     global_type.type.declname = f"nd_{global_high}"
        #     global_type = global_type.type
        # else:
        # raise Exception("Unknown global type")
        copy_ast.ext.insert(index, cast.Decl(
            f"nd_{global_high}", [], [], [], [],
            cast.FuncDecl(
                None,
                global_type
            ),
            None,
            None
        ))


def generate_empty_for_loop(idx_name, length):
    return cast.For(
        cast.DeclList(
            [
                cast.Decl(
                    idx_name, [], [], [], [],
                    cast.TypeDecl(
                        idx_name,
                        [],
                        None,
                        cast.IdentifierType(
                            ['int'],
                        )
                    ),
                    cast.Constant(
                        'int',
                        '0'
                    ),
                    None
                )
            ]
        ),
        cast.BinaryOp(
            '<',
            cast.ID(idx_name),
            length
            # cast.ID("something")
        ),
        cast.UnaryOp(
            'p++',
            cast.ID(idx_name)
        ),
        cast.Compound([])
    )
