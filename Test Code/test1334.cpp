python
def process_string(input_string):
    j = len(input_string)  # Initialize j to the length of the input string
    for char in input_string:
        j -= 1  # Decrement j for each character processed
    if j == 0 and input_string[-1].isdigit():  # Check if the last character was a digit
        print("Last character was a digit")
    else:
        print("Last character was not a digit")

# Example usage
input_str = "abc123"
process_string(input_str)
