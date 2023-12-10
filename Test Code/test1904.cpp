unsigned long long modularExponentiation(unsigned long long base, unsigned long long power, unsigned long long modulus) {
    unsigned long long res = 1;
    base = base % modulus; // Ensure base is within the range of modulus

    while (power > 0) {
        if (power & 1) {
            res = (res * base) % modulus;
        }
        power = power >> 1;
        base = (base * base) % modulus;
    }
    return res;
}
