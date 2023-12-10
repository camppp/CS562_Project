python
def total_divisors(n: int) -> int:
    prime_factors = [0] * (n + 1)
    for i in range(2, n + 1):
        if prime_factors[i] == 0:
            for j in range(i, n + 1, i):
                count = 0
                temp = j
                while temp % i == 0:
                    temp //= i
                    count += 1
                prime_factors[i] += count

    total_divisors = 1
    for i in range(2, n + 1):
        if prime_factors[i] > 0:
            total_divisors *= (prime_factors[i] + 1)

    return total_divisors
