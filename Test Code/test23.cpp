python
def reverseWords(s: str) -> str:
    # Split the input string into individual words
    words = s.split()
    
    # Reverse the order of words
    reversed_words = words[::-1]
    
    # Join the reversed words back into a single string
    reversed_string = ' '.join(reversed_words)
    
    return reversed_string
