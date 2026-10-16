import tkinter as tk
from tkinter import filedialog
from pycparser import parse_file, c_generator
from tabulate import tabulate

from modules.Counters import FuncCallCounter, LoopCounter, VarCounter


root = tk.Tk()
root.withdraw()

initial_dir = "../examples"
file_path = filedialog.askopenfilename(initialdir=initial_dir)

print("Selected file:", file_path)

ast = parse_file(file_path, use_cpp=True)

var_counter = VarCounter()
var_counter.visit(ast)

loop_counter = LoopCounter()
loop_counter.visit(ast)

func_counter = FuncCallCounter()
func_counter.visit(ast)

with open(file_path, "rb") as f:
    num_lines = sum(1 for _ in f)

data = [[num_lines, var_counter.count, loop_counter.count, func_counter.count]]
headers = ["LOC", "Variables", "Loops", "Func Calls"]
table = tabulate(data, headers=headers, tablefmt="grid")
print(table)
# print(f"LOC\t\t\t{num_lines}")
# print(f"Variables\t\t{var_counter.count}")
# print(f"Loops\t\t\t{loop_counter.count}")
# print(f"Func Calls\t\t{func_counter.count}")
