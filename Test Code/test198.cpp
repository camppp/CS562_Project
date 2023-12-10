#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findDivisors(int n) {
    std::vector<int> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    std::sort(divisors.begin(), divisors.end());
    return divisors;
}

int main() {
    int n = 12;
    std::vector<int> result = findDivisors(n);
    std::cout << "Divisors of " << n << " are: ";
    for (int divisor : result) {
        std::cout << divisor << " ";
    }
    return 0;
}
