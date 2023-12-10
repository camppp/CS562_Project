#include <iostream>

int gcd(int x, int y) {
    if (x == 0) {
        return y;
    } else if (y == 0) {
        return x;
    } else {
        while (x != y) {
            if (x > y) {
                x = x - y;
            } else {
                y = y - x;
            }
        }
        return x;
    }
}

int lcm(int x, int y) {
    return (x * y) / gcd(x, y);
}

int main() {
    int x = 12;
    int y = 15;
    std::cout << "GCD of " << x << " and " << y << " is " << gcd(x, y) << std::endl;
    std::cout << "LCM of " << x << " and " << y << " is " << lcm(x, y) << std::endl;
    return 0;
}
