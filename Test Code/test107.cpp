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

int sumOfPrimes(int start, int end) {
    int sum = 0;
    for (int num = start; num <= end; num++) {
        if (isPrime(num)) {
            sum += num;
        }
    }
    return sum;
}

int main() {
    int start = 10;
    int end = 20;
    std::cout << "Sum of primes between " << start << " and " << end << " is: " << sumOfPrimes(start, end) << std::endl;
    return 0;
}
