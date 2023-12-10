python
import re

def extractCopyrightHolder(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
        match = re.search(r'Copyright \(c\) \d{4} (.+?) <(.+?)>', content)
        if match:
            return match.group(1), match.group(2)
    return None  # Handle case when no match is found
