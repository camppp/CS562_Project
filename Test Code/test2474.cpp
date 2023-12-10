python
from typing import List, Dict

def parse_http_response(response: str, fields: List[str]) -> Dict[str, str]:
    header_lines = response.split("\r\n")[1:-1]  # Split the response into lines and exclude the status line
    header_dict = {}
    for line in header_lines:
        field, value = line.split(": ", 1)  # Split each line into field and value
        if field in fields:
            header_dict[field] = value  # Add the field and value to the dictionary
    return header_dict
