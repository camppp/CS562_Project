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
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }
    return sum;
}
