python
def processText(text: str) -> str:
    # Remove leading and trailing whitespace
    text = text.strip()
    
    # Convert the text to lowercase
    text = text.lower()
    
    # Replace all occurrences of "apple" with "orange"
    text = text.replace("apple", "orange")
    
    return text
