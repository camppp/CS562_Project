import re
from collections import Counter

def count_comment_words(input_str: str) -> dict:
    # Extract comments
    comments = re.findall(r'#.*', input_str)

    # Flatten comments and split into words
    words = [word for comment in comments for word in comment.split()]

    # Count occurrences of each word
    word_counts = Counter(words)

    return word_counts