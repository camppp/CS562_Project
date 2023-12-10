int iterativeFibonacci(int n, void *params) {
    int total = *(int *)params;
    int fib0 = 0, fib1 = 1, next;

    for (int i = 0; i < total; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = fib0 + fib1;
            fib0 = fib1;
            fib1 = next;
        }
    }

    return fib1;
}
