python
def count_custom_code_lines(file_content):
    custom_code_count = 0
    within_custom_area = False

    for line in file_content.split('\n'):
        line = line.strip()

        if line.startswith("//") and "custom code" in line.lower():
            within_custom_area = True
        elif line.startswith("//") and "automatically filled" in line.lower():
            within_custom_area = False
        elif within_custom_area and line:
            custom_code_count += 1

    return custom_code_count
