import ast
from collections import Counter


def count_imports(file_path):
    with open(file_path, "r") as f:
        tree = ast.parse(f.read())

    imports = [node.names[0].name for node in tree.body if type(node) == ast.Import]
    imports += [node.names[0].asname for node in tree.body if type(node) == ast.Import]
    imports += [node.module for node in tree.body if type(node) == ast.ImportFrom]
    imports += [node.module for node in tree.body if type(node) == ast.ImportFrom]

    return Counter(imports)


print(count_imports("example.py"))