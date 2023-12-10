double myPow(double x, int n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return x;
    } else if (n == -1) {
        return 1 / x;
    } else {
        double temp = myPow(x, n / 2);
        if (n % 2 == 0) {
            return temp * temp;
        } else {
            return n < 0 ? temp * temp * (1 / x) : temp * temp * x;
        }
    }
}
