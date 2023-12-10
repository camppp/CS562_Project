#include <stdio.h>

const double EXCHANGE_RATE_EUR_TO_PLN = 4.55;

double convertEURtoPLN(double amountInEUR) {
    return amountInEUR * EXCHANGE_RATE_EUR_TO_PLN;
}

int main() {
    double amountInEUR = 100.0;
    double amountInPLN = convertEURtoPLN(amountInEUR);
    printf("%.2f EUR is equal to %.2f PLN\n", amountInEUR, amountInPLN);
    return 0;
}
