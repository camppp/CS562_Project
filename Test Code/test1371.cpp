python
def calculateFactorial(n):
    if n < 0:
        raise ValueError("Input must be a non-negative integer")
    if n == 0 or n == 1:
        return 1
    total = 1
    for i in range(2, n + 1):
        total *= i
    return total
