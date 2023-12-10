python
import re

def extract_license_info(license_text):
    match = re.match(r'^(.*?) (\d{4})\n(http://.*?)\n\n(.*?) - (.*?).$', license_text, re.DOTALL)
    if match:
        return {
            "author": match.group(1),
            "year": int(match.group(2)),
            "website": match.group(3),
            "software_name": match.group(4),
            "license_type": match.group(5)
        }
    else:
        return None

# Test the function with the provided example
license_text = """
tmxlite 2016
http://trederia.blogspot.com

tmxlite - Zlib license.
"""
print(extract_license_info(license_text))
