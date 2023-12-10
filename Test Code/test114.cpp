python
import re
from collections import Counter

def count_top_words(file_name, N):
    with open(file_name, 'r') as file:
        text = file.read().lower()
        words = re.findall(r'\b\w+\b', text)
        word_counts = Counter(words)
        top_words = word_counts.most_common(N)
        sorted_top_words = sorted(top_words, key=lambda x: (-x[1], x[0]))
        for word, count in sorted_top_words:
            print(f"{word}: {count}")

# Example usage
count_top_words("input.txt", 2)
