BigInteger sum_digits(const BigInteger& n) {
    BigInteger sum = 0;
    for (int i = 0; i < n.get_digits_count(); i++) {
        sum += n.get_digit(i);
    }
    return sum;
}
