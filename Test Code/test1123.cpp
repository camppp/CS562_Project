python
def count_word_occurrences(file_name, words_to_search):
    word_counts = {}
    
    with open(file_name, 'r') as file:
        content = file.read().lower()  # Convert the content to lowercase for case-insensitive comparison
    
    for word in words_to_search:
        count = content.count(word.lower())  # Count the occurrences of the word in the content
        word_counts[word] = count
    
    return word_counts

file_name = "sample.txt"
words_to_search = input("Enter the words to search (comma-separated): ").split(',')
word_occurrences = count_word_occurrences(file_name, words_to_search)

for word, count in word_occurrences.items():
    print(f"Word '{word.strip()}' occurs {count} times.")
