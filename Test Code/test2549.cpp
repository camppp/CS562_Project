python
import base64
from typing import List, Tuple

def parseSoftwareVersions(pairs: List[Tuple[str, str]]) -> List[Tuple[str, str]]:
    result = []
    for version, encoded_str in pairs:
        version = version.strip()
        encoded_str = encoded_str.strip()
        decoded_str = ""
        if encoded_str:
            try:
                decoded_str = base64.b64decode(encoded_str).decode('utf-8')
            except:
                decoded_str = "Invalid Base64 encoding"
        result.append((version, decoded_str))
    return result
