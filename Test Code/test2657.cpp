python
def countWays(n):
    if n <= 1:
        return 1
    elif n == 2:
        return 2
    else:
        ways = [0] * (n + 1)
        ways[0], ways[1], ways[2] = 1, 1, 2
        for i in range(3, n + 1):
            ways[i] = ways[i - 1] + ways[i - 2] + ways[i - 3]
        return ways[n]

# Test the function
print(countWays(3))  # Output: 4
print(countWays(4))  # Output: 7
print(countWays(5))  # Output: 13
