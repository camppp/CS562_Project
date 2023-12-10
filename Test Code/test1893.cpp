python
from collections import Counter
import re

# Read the input file
with open('input.txt', 'r') as file:
    text = file.read()

# Tokenize the words and count occurrences
words = re.findall(r'\b\w+\b', text.lower())
word_counts = Counter(words)

# Output the word counts in descending order
for word, count in word_counts.most_common():
    print(f"{word}: {count}")
