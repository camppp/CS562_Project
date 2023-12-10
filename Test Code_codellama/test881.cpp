#include <iostream>
#include <cmath>

int sumOfPrimes(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }
    return sum;
}

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= std::sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int start = 10;
    int end = 20;
    int sum = sumOfPrimes(start, end);
    std::cout << "The sum of the prime numbers between " << start << " and " << end << " is " << sum << "." << std::endl;
    return 0;
}
