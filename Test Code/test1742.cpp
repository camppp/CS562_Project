python
import re

def extract_license_version(code_snippet):
    match = re.search(r'Boost Software License, Version (\d+\.\d+)', code_snippet)
    if match:
        return f"Version {match.group(1)}"
    else:
        return "License information not found"

# Test the function with the provided examples
code_snippet1 = """
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
"""
print(extract_license_version(code_snippet1))  # Output: Version 1.0

code_snippet2 = """
//
//  Distributed under the Some Other License
"""
print(extract_license_version(code_snippet2))  # Output: License information not found
