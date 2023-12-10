std::vector<int> pollardsRho(int n) {
    std::vector<int> factors;
    if (n == 1) {
        factors.push_back(1);
        return factors;
    }
    if (n % 2 == 0) {
        factors.push_back(2);
        while (n % 2 == 0) {
            n /= 2;
        }
    }
    if (n == 1) return factors;

    int x = rand() % (n - 2) + 2;
    int y = x;
    int c = rand() % (n - 1) + 1;
    int d = 1;

    auto f = [n](int x) { return (x * x + 3) % n; };

    while (d == 1) {
        x = f(x);
        y = f(f(y));
        d = gcd(abs(x - y), n);
    }

    if (d == n) {
        do {
            y = (y * y + 3) % n;
            d = gcd(abs(x - y), n);
        } while (d == 1);
    }

    if (!prime(d)) {
        factors.push_back(d);
        factors.push_back(n / d);
    } else {
        factors.push_back(d);
    }

    return factors;
}
