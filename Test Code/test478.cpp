python
def count_word_occurrences(file_path, words):
    # Read the contents of the specified file
    with open(file_path, 'r') as file:
        text = file.read().lower()  # Convert the text to lowercase for case-insensitive comparison

    word_counts = {}
    for word in words:
        count = text.count(word.lower())  # Count the occurrences of each word in the text
        word_counts[word] = count

    return word_counts

# Example usage
file_path = input("Enter the file path: ")
search_words = input("Enter the list of words to search for (separated by spaces): ").split()
occurrences = count_word_occurrences(file_path, search_words)
for word, count in occurrences.items():
    print(f"{word}: {count}")
