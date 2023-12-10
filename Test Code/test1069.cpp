python
# Read the content of the text file
with open("sample_text.txt", "r") as file:
    text = file.read()

# Define the list of specific words to count
specific_words = ["dolor", "ut", "in", "aliqua"]

# Create a dictionary to store the word counts
word_counts = {word: text.lower().count(word) for word in specific_words}

# Output the word counts
for word, count in word_counts.items():
    print(f"Word '{word}' occurs {count} times.")
