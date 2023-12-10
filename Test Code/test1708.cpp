python
import re

def extractLicenseInfo(header: str) -> (str, str):
    copyright_match = re.search(r'Copyright : (.+)', header)
    license_match = re.search(r'SPDX-License-Identifier: (.+)', header)
    
    copyright_info = copyright_match.group(1)
    license_identifier = license_match.group(1)
    
    return (copyright_info, license_identifier)

# Test the function
header = """
  TTS - Tiny Test System
  Copyright : TTS Contributors & Maintainers
  SPDX-License-Identifier: MIT
**/
"""
print(extractLicenseInfo(header))  # Output: ("TTS Contributors & Maintainers", "MIT")
