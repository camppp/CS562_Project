python
import re

def extract_license_sections(file_path):
    with open(file_path, 'r') as file:
        content = file.read()

    sections = re.findall(r'(?<=\n)([A-Z\s]+:)\n(.*?)(?=\n\n)', content, re.DOTALL)

    extracted_sections = {}
    for section in sections:
        section_name = section[0].strip(':')
        section_text = section[1].strip()
        extracted_sections[section_name] = section_text

    return extracted_sections

# Example usage
file_path = 'path_to_license_file.txt'
extracted_sections = extract_license_sections(file_path)
for section_name, section_text in extracted_sections.items():
    print(f"{section_name}:\n- {section_text}\n")
