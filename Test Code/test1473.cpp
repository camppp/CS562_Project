python
def count_word_occurrences(file_name, words_to_count):
    word_counts = {word: 0 for word in words_to_count}

    with open(file_name, 'r') as file:
        text = file.read()
        text = text.replace('\n', ' ')
        text = ''.join(e for e in text if e.isalnum() or e.isspace())
        words = text.split()

        for word in words:
            if word in word_counts:
                word_counts[word] += 1

    for word, count in word_counts.items():
        print(f"Occurrences of '{word}': {count}")

# Usage
file_name = "sample_text.txt"
words_to_count = ["License", "software", "distributed"]
count_word_occurrences(file_name, words_to_count)
