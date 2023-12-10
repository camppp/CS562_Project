python
def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True

def sum_of_primes(start, end):
    prime_sum = 0
    for num in range(max(2, start), end + 1):
        if is_prime(num):
            prime_sum += num
    return prime_sum

# Test the function
start = 10
end = 20
print(sum_of_primes(start, end))  # Output: 60
