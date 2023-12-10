#include <iostream>

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
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int result1 = sumOfPrimes(1, 10);
    std::cout << "The sum of the prime numbers within the range [1, 10] is: " << result1 << std::endl;

    int result2 = sumOfPrimes(20, 30);
    std::cout << "The sum of the prime numbers within the range [20, 30] is: " << result2 << std::endl;

    return 0;
}
