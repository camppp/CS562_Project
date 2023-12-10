python
def process_string(value, key):
    value = value.lower()  # Convert input string to lowercase
    if key < 10:
        result = value * key  # Concatenate the string with itself key times
        print(result)
    elif 10 <= key <= 20:
        result = value[::-1]  # Reverse the string
        print(result)
    else:
        print("Input out of range")

# Example usage
input_string = input("Enter a string: ")
input_unsigned_short = int(input("Enter an unsigned short: "))
process_string(input_string, input_unsigned_short)
