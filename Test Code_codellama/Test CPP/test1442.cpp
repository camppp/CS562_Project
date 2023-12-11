#include <iostream>
#include <cmath>

int sum_of_primes(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            sum += i;
        }
    }
    return sum;
}

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int start = 10;
    int end = 20;
    int sum = sum_of_primes(start, end);
    std::cout << "The sum of the prime numbers from " << start << " to " << end << " is " << sum << std::endl;
    return 0;
}
