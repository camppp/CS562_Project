python
import re
from collections import Counter

def count_words_in_license(file_name, n):
    with open(file_name, 'r') as file:
        text = file.read()
        words = re.findall(r'\b\w+\b', text)
        word_counts = Counter(words)
        top_n_words = word_counts.most_common(n)
        sorted_top_n_words = sorted(top_n_words, key=lambda x: (-x[1], x[0]))
        for word, count in sorted_top_n_words:
            print(f"{word}: {count}")

# Example usage
count_words_in_license("license.txt", 5)
