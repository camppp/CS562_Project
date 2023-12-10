python
def analyze_license(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
        licenses = content.split()
        total_licenses = len(licenses)
        dual_licenses = []

        if 'GPLv3' in licenses:
            dual_licenses.append('GPLv3')
        if 'commercial' in licenses:
            dual_licenses.append('commercial')

        return total_licenses, dual_licenses
