python
from typing import List, Dict
import re

def wordFrequency(text: str, stopWords: List[str]) -> Dict[str, int]:
    # Remove punctuation and convert text to lowercase
    text = re.sub(r'[^\w\s]', '', text).lower()
    
    # Split the text into words
    words = text.split()
    
    # Remove stop words
    words = [word for word in words if word not in stopWords]
    
    # Count the frequency of each word
    frequency = {}
    for word in words:
        frequency[word] = frequency.get(word, 0) + 1
    
    return frequency
