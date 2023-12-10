int evenFibonacciSum(int limit) {
    int fib1 = 0, fib2 = 1, sum = 0;
    while (fib1 <= limit) {
        if (fib1 % 2 == 0) {
            sum += fib1;
        }
        int temp = fib1;
        fib1 = fib2;
        fib2 = temp + fib2;
    }
    return sum;
}
