#include <vector>

class SieveOfEratosthenes {
public:
    SieveOfEratosthenes(int n) : primes(n + 1, true) {
        sieve();
    }

    bool is_prime(int n) {
        if (n < 2) {
            return false;
        }
        return primes[n];
    }

private:
    std::vector<bool> primes;

    void sieve() {
        primes[0] = primes[1] = false;
        for (int p = 2; p * p <= primes.size(); ++p) {
            if (primes[p]) {
                for (int i = p * p; i < primes.size(); i += p) {
                    primes[i] = false;
                }
            }
        }
    }
};

// Test cases
TEST_F(sieve_of_eratosthenes_tester, tests_checking_prime_numbers)
{
    SieveOfEratosthenes sieve(6);
    // when and then
    EXPECT_FALSE(sieve.is_prime(0));
    EXPECT_FALSE(sieve.is_prime(1));
    EXPECT_TRUE(sieve.is_prime(2));
    EXPECT_TRUE(sieve.is_prime(3));
    EXPECT_FALSE(sieve.is_prime(4));
    EXPECT_TRUE(sieve.is_prime(5));
    EXPECT_FALSE(sieve.is_prime(6));
}
