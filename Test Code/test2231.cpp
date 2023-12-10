python
import re

def count_word_occurrences(comment_block):
    words = re.findall(r'\b\w+\b', comment_block.lower())
    word_count = {}
    for word in words:
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1
    return word_count
