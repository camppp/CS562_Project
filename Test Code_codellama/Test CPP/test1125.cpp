int sumOfThousandsAndHundreds(int n) {
    if (n < 1000) {
        return -1;
    }
    int thousands = n / 1000;
    int hundreds = n % 1000;
    return thousands + hundreds;
}
