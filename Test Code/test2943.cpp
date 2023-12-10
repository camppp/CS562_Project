python
def word_frequency(text):
    # Remove punctuation and convert to lowercase
    text = ''.join(char.lower() if char.isalnum() or char.isspace() else ' ' for char in text)
    
    # Split the text into words
    words = text.split()
    
    # Count the frequency of each word
    frequency = {}
    for word in words:
        frequency[word] = frequency.get(word, 0) + 1
    
    # Print the frequency of each word
    for word, count in frequency.items():
        print(f"{word}: {count}")

# Test the function with the given input
input_text = "This code is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or"
word_frequency(input_text)
