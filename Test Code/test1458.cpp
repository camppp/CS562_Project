python
import re

def extract_license_info(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
        match = re.search(r'Copyright \(c\) (\d{4}) (.+)', content)
        if match:
            year = match.group(1)
            holder = match.group(2)
            print(f'Copyright Holder: {holder}')
            print(f'Year of Copyright: {year}')
        else:
            print('Copyright information not found in the file.')

# Example usage
extract_license_info('path_to_license_file.txt')
