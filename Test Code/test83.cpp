python
import re
from collections import Counter

def get_top_n_words(file_path, n):
    with open(file_path, 'r') as file:
        text = file.read().lower()
        words = re.findall(r'\b\w+\b', text)
        stop_words = {'the', 'and', 'of', 'is', 'it', 'a', 'an', 'in', 'on', 'at', 'to', 'for', 'with', 'as', 'by', 'from'}
        filtered_words = [word for word in words if word not in stop_words]
        word_counts = Counter(filtered_words)
        top_n_words = word_counts.most_common(n)
        return top_n_words

file_path = "input.txt"
n = 5
top_words = get_top_n_words(file_path, n)
for word, count in top_words:
    print(f"{word}: {count}")
