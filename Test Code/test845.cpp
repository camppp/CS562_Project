python
def calculate_value(s, min1, min2_10, min11):
    for i in range(2, 11):
        if s < min1 + min2_10 * (i - 1):
            return i - 1
    return 10 + (s - min1 - min2_10 * 9) // min11
