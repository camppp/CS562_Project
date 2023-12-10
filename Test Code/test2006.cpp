#include <iostream>
#include <cmath>

bool isPrime(int n) {
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

long long sumOfPrimes(int start, int end) {
    long long sum = 0;
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int start = 5, end = 15;
    std::cout << "Sum of primes between " << start << " and " << end << " is: " << sumOfPrimes(start, end) << std::endl;
    return 0;
}
