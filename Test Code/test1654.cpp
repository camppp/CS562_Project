python
# Open the text file and read its content
with open("sample_text.txt", "r") as file:
    text = file.read()

# Convert the entire text to lowercase for case-insensitive comparison
text = text.lower()

# Define the words to be counted
words_to_count = ["DAMAGES", "SERVICES", "PROFITS", "BUSINESS"]

# Initialize a dictionary to store the word counts
word_counts = {word: 0 for word in words_to_count}

# Split the text into words and count the occurrences of specified words
for word in text.split():
    if word in words_to_count:
        word_counts[word] += 1

# Output the word counts
for word, count in word_counts.items():
    print(f"{word}: {count}")
