python
import re
import sys
from collections import Counter

def count_word_frequency(file_path):
    try:
        with open(file_path, 'r') as file:
            text = file.read()
            words = re.findall(r'\b\w+\b', text.lower())
            word_counts = Counter(words)
            sorted_word_counts = dict(sorted(word_counts.items(), key=lambda item: item[1], reverse=True))
            for word, count in sorted_word_counts.items():
                print(f"{word}: {count}")
    except FileNotFoundError:
        print("File not found.")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python word_frequency_counter.py <input_file>")
    else:
        count_word_frequency(sys.argv[1])
