#include <iostream>
#include <vector>

bool check_primes(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> prime_numbers;
    for (int i = 1; i <= 100; i++) {
        if (check_primes(i)) {
            prime_numbers.push_back(i);
        }
    }
    for (int i = 0; i < prime_numbers.size(); i++) {
        std::cout << prime_numbers[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
