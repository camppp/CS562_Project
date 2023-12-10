#include <iostream>
#include <vector>

bool check_primes(const std::vector<int>& primes, int number) {
    for (int prime : primes) {
        if (number % prime == 0) {
            return false;  // Not a prime number
        }
    }
    return true;  // Prime number
}

int main() {
    std::vector<int> prime_numbers;
    for (int i = 2; i <= 100; ++i) {
        if (check_primes(prime_numbers, i)) {
            prime_numbers.push_back(i);
        }
    }

    std::cout << "Prime numbers between 1 and 100:" << std::endl;
    for (int prime : prime_numbers) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}
