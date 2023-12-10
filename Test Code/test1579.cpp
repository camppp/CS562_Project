python
def reverse_sequence(input_sequence, axis):
    if axis == 0:
        return input_sequence[::-1]
    elif axis == 1:
        return [seq[::-1] for seq in input_sequence]
    else:
        raise ValueError("Invalid axis value. Axis should be 0 or 1.")
