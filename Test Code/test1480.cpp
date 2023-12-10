def find_second_largest(a, b, c):
    if a > b and a > c:
        return b
    elif b > a and b > c:
        return a
    else:
        return c
