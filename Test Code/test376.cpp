python
def extract_license_info(license_file_path):
    with open(license_file_path, 'r') as file:
        content = file.read()
        organization = content.split('Copyright (c) ')[1].split('\n')[0]
        with open('LICENSE', 'r') as license_file:
            license_type = license_file.read().strip()

    print(f'Organization: {organization}')
    print(f'License Type: {license_type}')

# Example usage
extract_license_info('path_to_license_file')
