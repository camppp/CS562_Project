python
import re
from collections import Counter

def analyze_word_frequency(file_path, N):
    with open(file_path, 'r') as file:
        text = file.read().lower()
        words = re.findall(r'\b\w+\b', text)
        word_counts = Counter(words)
        top_words = word_counts.most_common(N)
        for word, count in top_words:
            print(f"{word}: {count}")

# Example usage
analyze_word_frequency('sample.txt', 3)
