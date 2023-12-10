python
def print_pattern(len):
    for i in range(1, len + 1):
        print(chr(64 + i) * i)

# Test cases
print_pattern(1)
print("\n")
print_pattern(2)
print("\n")
print_pattern(3)
print("\n")
print_pattern(4)
