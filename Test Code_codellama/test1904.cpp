c
#include <iostream>

using namespace std;

unsigned long long modularExponentiation(unsigned long long base, unsigned long long power, unsigned long long modulus) {
    unsigned long long res = 1;
    while (power > 0) {
        if (power % 2 == 1) {
            res = (res * base) % modulus;
        }
        power >>= 1;
        base = (base * base) % modulus;
    }
    return res;
}

int main() {
    unsigned long long base = 2;
    unsigned long long power = 1000000000;
    unsigned long long modulus = 1000000007;
    cout << modularExponentiation(base, power, modulus) << endl;
    return 0;
}
