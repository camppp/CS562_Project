python
from typing import List, Dict

def countOccurrences(text: str, keywords: List[str]) -> Dict[str, int]:
    # Convert the text and keywords to lowercase for case-insensitive comparison
    text_lower = text.lower()
    keywords_lower = [keyword.lower() for keyword in keywords]
    
    # Initialize a dictionary to store the count of occurrences for each keyword
    occurrences_count = {keyword: 0 for keyword in keywords}
    
    # Count the occurrences of each keyword in the text
    for keyword in keywords_lower:
        occurrences_count[keyword] = text_lower.count(keyword)
    
    return occurrences_count
