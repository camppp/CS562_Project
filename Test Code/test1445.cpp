python
import difflib

def generate_edit_script(file1_path, file2_path, edit_script_path):
    with open(file1_path, 'r') as file1:
        file1_content = file1.readlines()
    with open(file2_path, 'r') as file2:
        file2_content = file2.readlines()

    differ = difflib.Differ()
    diff = list(differ.compare(file1_content, file2_content))

    edit_script = []
    line_num = 1
    for line in diff:
        if line.startswith('- '):
            edit_script.append(f"Delete line {line_num}: {line[2:]}")
        elif line.startswith('+ '):
            edit_script.append(f"Insert line {line_num}: {line[2:]}")
        elif line.startswith('? '):
            edit_script.append(f"Replace line {line_num}: {line[2:]}")
        line_num += 1

    with open(edit_script_path, 'w') as edit_script_file:
        edit_script_file.write('\n'.join(edit_script))

# Example usage
generate_edit_script('file1.txt', 'file2.txt', 'edit_script.txt')
