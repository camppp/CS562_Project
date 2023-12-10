python
import re
from collections import Counter

def topNWords(filename, N):
    with open(filename, 'r') as file:
        text = file.read().lower()
        words = re.findall(r'\b\w+\b', text)
        stop_words = {'the', 'and', 'is', 'a', 'this', 'of', 'in', 'to', 'for', 'with', 'on', 'at', 'an'}
        filtered_words = [word for word in words if word not in stop_words]
        word_counts = Counter(filtered_words)
        top_n_words = word_counts.most_common(N)
        top_n_words.sort(key=lambda x: (x[1], x[0]))  # Sort alphabetically if frequency is the same
        return top_n_words
