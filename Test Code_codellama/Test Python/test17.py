import re
from collections import defaultdict

def count_comment_words(input_str: str) -> dict:
    comments = re.findall(r'#.*?\n', input_str)
    word_counts = defaultdict(int)
    for comment in comments:
        words = comment.strip().split()
        for word in words:
            word_counts[word] += 1
    return dict(word_counts)