python
def word_frequency(text):
    # Remove punctuation and convert text to lowercase
    text = ''.join(char if char.isalnum() or char.isspace() else ' ' for char in text).lower()
    
    # Split the text into words
    words = text.split()
    
    # Create a dictionary to store word frequencies
    word_freq = {}
    for word in words:
        word_freq[word] = word_freq.get(word, 0) + 1
    
    # Sort the word frequencies in descending order
    sorted_word_freq = sorted(word_freq.items(), key=lambda x: x[1], reverse=True)
    
    # Print the word frequencies
    for word, freq in sorted_word_freq:
        print(f"{word}: {freq}")
    
# Test the function with the given input
text = "The quick brown fox jumps over the lazy dog. The dog barks, and the fox jumps."
word_frequency(text)
