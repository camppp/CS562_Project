# Open the text file
with open("sample_text.txt", "r") as f:
    # Read the content of the file
    content = f.read()

# Split the content into individual words
words = content.split()

# Create a dictionary to store the word counts
word_counts = {}

# Iterate over the words and increment the count for each word in the list
for word in words:
    if word in ["dolor", "ut", "in", "aliqua"]:
        if word not in word_counts:
            word_counts[word] = 1
        else:
            word_counts[word] += 1

# Print the word counts
for word, count in word_counts.items():
    print(f"Word '{word}' occurs {count} times.")
