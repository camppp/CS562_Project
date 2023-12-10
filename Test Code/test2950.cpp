python
def word_frequency(text):
    # Remove punctuation and convert text to lowercase
    text = text.lower().replace('.', '').replace(',', '')
    words = text.split()
    
    word_count = {}
    for word in words:
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1
    
    # Sort the word_count dictionary by value in descending order
    sorted_word_count = sorted(word_count.items(), key=lambda x: x[1], reverse=True)
    
    # Print the sorted word frequencies
    for word, frequency in sorted_word_count:
        print(f"{word}: {frequency}")

# Example usage
input_text = "The quick brown fox jumps over the lazy dog. The dog barks, and the fox jumps."
word_frequency(input_text)
