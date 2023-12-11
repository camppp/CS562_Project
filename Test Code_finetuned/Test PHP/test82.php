class TextModifier:
    def __init__(self):
        pass

    def overwrite(self, text):
        # Convert all characters to uppercase
        text = text.upper()
        # Replace all spaces with underscores
        text = text.replace(' ', '_')
        return text

# Example usage
tm = TextModifier()
print(tm.overwrite("Hello, World!"))  # Expected output: "HELLO,_WORLD!"