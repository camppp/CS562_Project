python
def sum_divisible(arr, divisor):
    return sum(num for num in arr if num % divisor == 0)
