python
from typing import List

def extractCommentBlock(comment: str) -> List[str]:
    lines = comment[2:-2].strip().split('\n')  # Remove /* and */ and leading/trailing whitespace
    cleaned_lines = [line.strip() for line in lines]  # Remove leading and trailing whitespace from each line
    return cleaned_lines
