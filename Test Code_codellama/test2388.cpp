# Open the text file
with open("sample.txt", "r") as f:
    # Read the file contents
    contents = f.read()

# Split the contents into individual words
words = contents.split()

# Initialize the counts for the two words
disclaimer_count = 0
institute_count = 0

# Iterate over the words and count the occurrences of each word
for word in words:
    if word == "disclaimer":
        disclaimer_count += 1
    elif word == "institute":
        institute_count += 1

# Print the counts for each word
print(f"Word 'disclaimer' occurs {disclaimer_count} time(s).")
print(f"Word 'institute' occurs {institute_count} time(s).")
