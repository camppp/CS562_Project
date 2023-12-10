python
def max_contiguous_sum(sequence):
    max_sum = current_sum = sequence[0]
    
    for num in sequence[1:]:
        current_sum = max(num, current_sum + num)
        max_sum = max(max_sum, current_sum)
    
    return max_sum

sequence = [int(x) for x in sequence.split(',')]
result = max_contiguous_sum(sequence)
print(result)
