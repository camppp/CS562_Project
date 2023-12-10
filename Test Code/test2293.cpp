python
import re
from collections import Counter

def count_word_frequency(file_name, n):
    with open(file_name, 'r') as file:
        text = file.read().lower()
        words = re.findall(r'\b\w+\b', text)
        word_counts = Counter(words)
        top_n_words = word_counts.most_common(n)
        for word, count in top_n_words:
            print(f"{word}: {count}")

count_word_frequency("input.txt", 10)  # Replace 10 with the desired value of N
