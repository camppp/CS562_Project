python
import re

def extract_license_info(file_path):
    license_counts = {}
    with open(file_path, 'r') as file:
        for line in file:
            match = re.search(r'licensed under the (.+?) \(', line)
            if match:
                license_type = match.group(1)
                if license_type in license_counts:
                    license_counts[license_type] += 1
                else:
                    license_counts[license_type] = 1
    return license_counts

# Example usage
file_path = 'path_to_your_text_file.txt'
result = extract_license_info(file_path)
print(result)
