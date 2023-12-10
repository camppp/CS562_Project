python
import re
from collections import Counter

def count_word_occurrences(file_path):
    try:
        with open(file_path, 'r') as file:
            text = file.read().lower()  # Read the file and convert text to lowercase
            words = re.findall(r'\b\w+\b', text)  # Extract words ignoring punctuation
            word_counts = Counter(words)  # Count occurrences of each word
            sorted_word_counts = sorted(word_counts.items(), key=lambda x: x[1], reverse=True)  # Sort by word counts
            for word, count in sorted_word_counts:
                print(f"{word}: {count}")
    except FileNotFoundError:
        print("File not found")
    except Exception as e:
        print(f"An error occurred: {e}")

# Example usage
count_word_occurrences('sample_text.txt')
