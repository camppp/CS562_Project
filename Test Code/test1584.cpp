#include <iostream>
#include <cmath>
#define PR_ARR 1000000 // Define the upper limit for prime number generation

bool b[PR_ARR+1] = {0}; // Initialize an array to mark non-prime numbers
__int64 a[PR_ARR+1] = {0}; // Initialize an array to store prime numbers
__int64 an = 0; // Initialize a variable to keep track of the number of prime numbers found

void generatePrimes() {
    for (__int64 i = 2; i < PR_ARR; i++) {
        if (!b[i]) {
            for (__int64 j = 2; j <= PR_ARR / i; j++) {
                if (i * j <= PR_ARR) {
                    b[i * j] = 1; // Mark non-prime numbers
                }
            }
            an++;
            a[an] = i; // Store prime numbers in the array a
        }
    }
}

__int64 findNthPrime(int n) {
    if (n <= an) {
        return a[n]; // If the nth prime number is already generated, return it directly
    } else {
        __int64 num = a[an]; // Start from the last generated prime number
        for (__int64 i = a[an] + 1; an < n; i++) {
            bool isPrime = true;
            for (__int64 j = 2; j <= sqrt(i); j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                an++;
                a[an] = i; // Store the newly found prime number
                num = i; // Update the current prime number
            }
        }
        return num;
    }
}

int main() {
    generatePrimes(); // Generate prime numbers up to PR_ARR
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    std::cout << "The " << n << "th prime number is: " << findNthPrime(n) << std::endl;
    return 0;
}
