python
def isPrime(n: int) -> bool:
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def sumOfPrimes(start: int, end: int) -> int:
    prime_sum = 0
    for num in range(max(2, start), end + 1):
        if isPrime(num):
            prime_sum += num
    return prime_sum
