python
def isPerfectPower(n):
    if n == 1:
        return (1, 1)

    for base in range(2, int(n ** 0.5) + 1):
        exponent = 2
        while base ** exponent <= n:
            if base ** exponent == n:
                return (base, exponent)
            exponent += 1

    if n < 0:
        for base in range(2, int(abs(n) ** (1/3)) + 1):
            if base ** 3 == abs(n):
                return (-base, 3)

    return None
