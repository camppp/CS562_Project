double myPow(double x, int n) {
    if (n == 0) {
        return 1;
    } else if (n < 0) {
        return 1 / myPow(x, -n);
    } else {
        double temp = myPow(x, n/2);
        if (n % 2 == 0) {
            return temp * temp;
        } else {
            return temp * temp * (n < 0 ? 1/x : x);
        }
    }
}
