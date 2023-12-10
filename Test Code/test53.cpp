python
import re

def extract_copyright_holder(file_path):
    with open(file_path, 'r') as file:
        content = file.read()

    # Define regular expressions to match different styles of copyright comments
    single_line_comment_pattern = r'\/\/.*Copyright.*\n'
    multi_line_comment_pattern = r'\/\*.*?Copyright.*?\*\/'

    # Search for copyright holder's name in the file content
    single_line_match = re.search(single_line_comment_pattern, content)
    multi_line_match = re.search(multi_line_comment_pattern, content, re.DOTALL)

    if single_line_match:
        return single_line_match.group(0).split('Copyright')[1].strip()
    elif multi_line_match:
        return multi_line_match.group(0).split('Copyright')[1].strip()
    else:
        return "Unknown"
