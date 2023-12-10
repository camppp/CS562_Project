python
import re

def isValidVariableName(name):
    pattern = r'^[a-zA-Z_][a-zA-Z0-9_]*$'
    return bool(re.match(pattern, name))

# Test cases
print(isValidVariableName("variable"))  # Output: True
print(isValidVariableName("_variable123"))  # Output: True
print(isValidVariableName("123variable"))  # Output: False
print(isValidVariableName("var!able"))  # Output: False
