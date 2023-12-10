python
def find_first(collection, condition, default):
    for element in collection:
        if condition(element):
            return element
    return default

# Test the function
collection = [2, 4, 6, 8, 10]
condition = lambda x: x % 2 != 0
default = -1
print(find_first(collection, condition, default))  # Output: -1
