python
import re

def count_unique_words(input_string: str) -> dict:
    words = re.findall(r'\b\w+\b', input_string.lower())
    word_count = {}
    for word in words:
        word_count[word] = word_count.get(word, 0) + 1
    return word_count
