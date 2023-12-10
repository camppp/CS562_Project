python
def count_word_occurrences(file_name, words):
    word_counts = {word: 0 for word in words}

    with open(file_name, 'r') as file:
        for line in file:
            for word in words:
                word_counts[word] += line.lower().count(word)

    for word, count in word_counts.items():
        print(f"Word '{word}' occurs {count} time(s).")

# Usage
file_name = "sample.txt"
words_to_count = ["disclaimer", "institute"]
count_word_occurrences(file_name, words_to_count)
