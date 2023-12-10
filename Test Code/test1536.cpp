#include <vector>
#include <cmath>

std::vector<int> findPrimes(int N) {
    std::vector<bool> flags(N, true);  // Initialize all numbers as potential primes
    flags[0] = flags[1] = false;  // 0 and 1 are not prime numbers

    for (int i = 2; i <= std::sqrt(N); ++i) {
        if (flags[i]) {
            for (int j = i * i; j < N; j += i) {
                flags[j] = false;  // Mark multiples of prime numbers as non-prime
            }
        }
    }

    std::vector<int> primes;
    for (int i = 2; i < N; ++i) {
        if (flags[i]) {
            primes.push_back(i);  // Add prime numbers to the result vector
        }
    }

    return primes;
}
