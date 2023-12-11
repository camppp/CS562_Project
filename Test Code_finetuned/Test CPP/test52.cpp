import re

def get_copyright_holder(file_path):
    with open(file_path, 'r') as file:
        for line in file:
            if re.search(r'Copyright\s*\(?C?\)?', line):
                return re.search(r'Copyright\s*\(?C?\)?\s*(\w+\s*\w+)', line).group(1)
    return "Unknown"