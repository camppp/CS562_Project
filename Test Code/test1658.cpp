python
import re
from collections import Counter

def word_frequency_analysis(file_path, top_n):
    # Read the text file
    with open(file_path, 'r') as file:
        text = file.read()

    # Tokenize the words and count their occurrences
    words = re.findall(r'\b\w+\b', text.lower())
    stop_words = {'the', 'and', 'is', 'to', 'of', 'in', 'a', 'for', 'on', 'this', 'with', 'it', 'that'}
    filtered_words = [word for word in words if word not in stop_words]
    word_counts = Counter(filtered_words)

    # Output the top N most frequent words and their counts
    top_words = word_counts.most_common(top_n)
    for word, count in top_words:
        print(f"{word}: {count}")

# Example usage
word_frequency_analysis('sample.txt', 3)
