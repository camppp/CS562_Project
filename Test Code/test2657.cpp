int countWays(int n) {
    if (n == 0) {
        return 1;
    }
    int ways = 0;
    for (int i = 1; i <= 3; i++) {
        ways += countWays(n - i);
    }
    return ways;
}
