python
from typing import List, Dict
import re

def count_phrase_occurrences(license_text: str, phrases: List[str]) -> Dict[str, int]:
    occurrences = {}
    license_text_lower = license_text.lower()
    
    for phrase in phrases:
        occurrences[phrase] = len(re.findall(phrase.lower(), license_text_lower))
    
    return occurrences
