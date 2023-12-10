python
def dropWhile(sequence, predicate):
    result = []
    drop = True
    for item in sequence:
        if drop and predicate(item):
            continue
        else:
            drop = False
            result.append(item)
    return result

# Test the dropWhile function
input_sequence = [1, 2, 1, 1]
predicate_function = lambda x: x == 1
result_sequence = dropWhile(input_sequence, predicate_function)
print(result_sequence)  # Output: [2, 1, 1]
