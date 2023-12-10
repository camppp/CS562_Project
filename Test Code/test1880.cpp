python
def evenFibonacciSum(limit):
    # Initialize the first two Fibonacci numbers
    fib1, fib2 = 0, 1
    evenSum = 0

    # Calculate the Fibonacci sequence and sum the even numbers
    while fib2 <= limit:
        if fib2 % 2 == 0:
            evenSum += fib2
        fib1, fib2 = fib2, fib1 + fib2

    return evenSum
