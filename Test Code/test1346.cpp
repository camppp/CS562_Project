python
def jump(ident):
    return "jump to " + "_l" + ident

# Example usage
identifier = "3"
generated_code = jump(identifier)
print(generated_code)  # Output: jump to _l3
