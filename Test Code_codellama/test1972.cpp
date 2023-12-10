long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    long long fibonacci_sum = 0;
    long long a = 0, b = 1;
    for (long long i = from; i <= to; i++) {
        fibonacci_sum += a;
        long long temp = a;
        a = b;
        b = temp + b;
    }
    return fibonacci_sum;
}
