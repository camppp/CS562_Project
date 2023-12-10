import re

def count_word_occurrences(file_name):
    with open(file_name, 'r') as f:
        text = f.read()

    # Remove punctuation and convert to lowercase
    text = re.sub(r'[^\w\s]', '', text.lower())

    # Split the text into individual words
    words = text.split()

    # Create a dictionary to store the word counts
    word_counts = {}

    # Iterate over the words and increment the count for each unique word
    for word in words:
        if word not in word_counts:
            word_counts[word] = 1
        else:
            word_counts[word] += 1

    return word_counts
