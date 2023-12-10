python
def sum_of_values(input_dict):
    # Initialize sum to 0
    sum = 0
    # Iterate through the key-value pairs in the input dictionary
    for key, value in input_dict.items():
        # Add the value to the sum
        sum += value
    return sum

# Test the function with the given example
input_dict = {
    'a': 5,
    'b': 3,
    'c': 7
}
result = sum_of_values(input_dict)
print(result)  # Output: 15
