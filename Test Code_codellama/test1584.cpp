#include <iostream>
#include <cmath>

using namespace std;

const int MAX_PRIMES = 1000000;

int a[MAX_PRIMES];
int b[MAX_PRIMES];
int an = 0;

void sieve() {
    for (int i = 2; i < MAX_PRIMES; i++) {
        if (a[i] == 0) {
            a[i] = i;
            b[i] = 1;
        } else {
            b[i] = 0;
        }
    }
}

int findNthPrime(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 2;
    }
    if (n > an) {
        sieve();
        an = n;
    }
    return a[n];
}

int main() {
    int n = 10;
    cout << "The " << n << "th prime number is " << findNthPrime(n) << endl;
    return 0;
}
