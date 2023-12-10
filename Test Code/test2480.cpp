python
from typing import List, Dict
import re

def count_keyword_occurrences(file_path: str, keywords: List[str]) -> Dict[str, int]:
    keyword_counts = {keyword: 0 for keyword in keywords}
    with open(file_path, 'r') as file:
        text = file.read().upper()  # Convert the text to uppercase for case-insensitive matching
        for keyword in keywords:
            occurrences = len(re.findall(r'\b' + re.escape(keyword) + r'\b', text))
            keyword_counts[keyword] = occurrences
    return keyword_counts
