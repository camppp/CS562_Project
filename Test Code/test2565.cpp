python
def processCommands(commands):
    addy = [0] * 30000  # Initialize the array with 30000 zeros
    pointer = 0  # Initialize the pointer to point to the first position in the array
    output = ""  # Initialize the output string

    for command in commands:
        if command == '+':
            addy[pointer] += 1
        elif command == '-':
            addy[pointer] -= 1
        elif command == '>':
            pointer += 1
        elif command == '<':
            pointer -= 1
        elif command == '.':
            output += chr(addy[pointer])

    return output
