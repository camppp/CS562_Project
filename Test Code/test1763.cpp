python
import random

def generateRandomSequence(n):
    if n % 2 == 0:
        symbols = ['!', '@', '#', '$', '%']
        return ''.join(random.choice(symbols) for _ in range(n))
    else:
        return ''.join(str(random.randint(0, 9)) for _ in range(n))

# Example usage
print(generateRandomSequence(5))  # Possible output: "@#%$!"
print(generateRandomSequence(6))  # Possible output: "##$@!@"
print(generateRandomSequence(7))  # Possible output: "1234567"
