python
import re

def count_license_comments(file_path):
    pattern = r'/\*\s*"AS IS"\s*BASIS,\s*WITHOUT\s*WARRANTIES\s*OR\s*CONDITIONS\s*OF\s*ANY\s*KIND,\s*\*/'
    with open(file_path, 'r') as file:
        content = file.read()
        occurrences = re.findall(pattern, content)
        return len(occurrences)

# Example usage
file_path = 'sample_code_file.c'
print(count_license_comments(file_path))  # Output: 2
