python
from typing import List

def formatText(text: str, operations: List[str]) -> str:
    formatted_text = text
    for operation in operations:
        if operation == "bold":
            formatted_text = f"**{formatted_text}**"
        elif operation == "italic":
            formatted_text = f"_{formatted_text}_"
        elif operation == "underline":
            formatted_text = f"~{formatted_text}~"
    return formatted_text
