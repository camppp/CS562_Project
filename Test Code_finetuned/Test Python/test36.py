import re
from collections import Counter

def count_imports(file_path: str) -> dict:
    with open(file_path, 'r') as file:
        content = file.read()

    # Find all import statements
    import_statements = re.findall(r'import\s+([\w\.]+)', content)

    # Count the number of times each module is imported
    import_counts = Counter(import_statements)

    return import_counts