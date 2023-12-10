python
def count_disclaimers(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
        disclaimer_count = 0
        in_comment_block = False

        for line in content.split('\n'):
            if '/*' in line:
                in_comment_block = True
            if in_comment_block and 'DISCLAIMER' in line.upper():
                disclaimer_count += 1
            if '*/' in line:
                in_comment_block = False

        return disclaimer_count

file_path = 'source_code_file.txt'  # Replace with the actual file path
print(count_disclaimers(file_path))
