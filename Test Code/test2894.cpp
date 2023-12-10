python
import re

def check_apache_license(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
        apache_license_pattern = r"Licensed under the Apache License, Version 2.0"
        license_url_pattern = r"http://www.apache.org/licenses/LICENSE-2.0"
        copyright_pattern = r"Copyright \d{4} .+"
        
        if (re.search(apache_license_pattern, content) and
            re.search(license_url_pattern, content) and
            re.search(copyright_pattern, content)):
            return True
        else:
            return False
