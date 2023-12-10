python
import string

def count_word_occurrences(file_name):
    word_counts = {}
    with open(file_name, 'r') as file:
        for line in file:
            words = line.lower().translate(str.maketrans('', '', string.punctuation)).split()
            for word in words:
                if word in word_counts:
                    word_counts[word] += 1
                else:
                    word_counts[word] = 1
    return word_counts
