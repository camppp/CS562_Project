int power(int a, int b)
{
    int res = 1;
    int base = a;
    int exponent = b;

    if (exponent < 0) {
        base = 1 / base;
        exponent = -exponent;
    }

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            res *= base;
        }
        base *= base;
        exponent /= 2;
    }

    return res;
}
