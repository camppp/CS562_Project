def total_divisors(n: int) -> int:
    product = 1
    for i in range(1, n+1):
        product *= i
    divisors = set()
    for i in range(1, product+1):
        if product % i == 0:
            divisors.add(i)
    return len(divisors)
