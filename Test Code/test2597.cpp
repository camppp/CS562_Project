python
import re

def extract_license_info(comment_block):
    license_type_pattern = r'(?<=terms of the )(.+?)(?= License)'
    license_version_pattern = r'(?<=version )\d+'
    
    license_type_match = re.search(license_type_pattern, comment_block)
    license_version_match = re.search(license_version_pattern, comment_block)
    
    if license_type_match and license_version_match:
        license_type = license_type_match.group(0)
        license_version = license_version_match.group(0)
        return f"License Type: {license_type}\nLicense Version: {license_version}"
    else:
        return "License information not found."

comment_block = """
 * This file is part of LSPosed.
 *
 * LSPosed is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
"""

print(extract_license_info(comment_block))
