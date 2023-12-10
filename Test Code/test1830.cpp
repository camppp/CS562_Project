python
import re
import os

def extract_header_info(header_file_path):
    header_info = {
        "license_identifier": "",
        "component_name": "",
        "included_files": []
    }

    with open(header_file_path, 'r') as file:
        content = file.read()

        # Extract license identifier
        license_match = re.search(r'/\*\*\s*\n\s*\*\s*SPDX-License-Identifier:\s*(.*?)\s*\n\s*\*/', content)
        if license_match:
            header_info["license_identifier"] = license_match.group(1)

        # Extract component name
        header_info["component_name"] = os.path.splitext(os.path.basename(header_file_path))[0]

        # Extract included files
        include_matches = re.findall(r'#include\s+"(.*?)"', content)
        header_info["included_files"] = include_matches

    return header_info

header_file_path = "path_to_your_header_file.h"
result = extract_header_info(header_file_path)
print(result)
