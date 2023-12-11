std::vector<int> findPrimes(int N) {
    std::vector<int> primes;
    for (int i = 2; i <= N; i++) {
        bool isPrime = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes.push_back(i);
        }
    }
    return primes;
}
