python
import re

# Read the input file and store its content in a string
with open('input.txt', 'r') as file:
    text = file.read()

# Convert the entire text to lowercase for case-insensitive comparison
text = text.lower()

# Use regular expression to find all words in the text
words = re.findall(r'\b\w+\b', text)

# Create a dictionary to store word frequencies
word_freq = {}
for word in words:
    if word in word_freq:
        word_freq[word] += 1
    else:
        word_freq[word] = 1

# Sort the word frequencies in descending order
sorted_word_freq = sorted(word_freq.items(), key=lambda x: x[1], reverse=True)

# Output the word frequencies to the console
for word, freq in sorted_word_freq:
    print(f"{word}: {freq}")
