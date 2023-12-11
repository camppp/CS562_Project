import re

def extract_copyright_holder(file_path: str) -> str:
    with open(file_path, 'r') as f:
        text = f.read()
        match = re.search(r'Copyright \d{4} (.*)', text)
        if match:
            return match.group(1)
        else:
            return None