python
def memoryMapping(condition):
    if condition:
        return "Program Memory Bank: 0x20\nCharacter Memory Bank: 0x00"
    else:
        return "Program Memory Bank: 0x07\nCharacter Memory Bank: 0x00"
