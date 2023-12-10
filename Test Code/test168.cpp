python
def convertToQuotedFormat(input_string: str) -> str:
    words = [word.strip() for word in input_string.split(',')]
    quoted_words = ['"' + word + '"' for word in words]
    return ', '.join(quoted_words)
