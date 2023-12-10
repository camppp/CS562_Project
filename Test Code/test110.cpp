python
def extract_license_info(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()
        license_info = ""
        in_license_block = False

        for line in lines:
            if line.strip().lower().startswith('//') and ("license" in line.lower() or "licence" in line.lower()):
                in_license_block = True
                license_info += line.lstrip('//').strip() + "\n"
            elif in_license_block and line.strip().lower().startswith('//'):
                license_info += line.lstrip('//').strip() + "\n"
            elif in_license_block and not line.strip().lower().startswith('//'):
                in_license_block = False
                break

        return license_info

file_path = 'example.txt'  # Replace with the actual file path
print(extract_license_info(file_path))
