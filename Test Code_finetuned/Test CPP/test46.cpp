def sumOfPrimes(start, end):
    def is_prime(n):
        if n < 2:
            return False
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                return False
        return True

    return sum(i for i in range(start, end + 1) if is_prime(i))

print(sumOfPrimes(10, 20))  # Output: 60