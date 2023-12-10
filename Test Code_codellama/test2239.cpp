#include <iostream>

const double EXCHANGE_RATE_EUR_TO_PLN = 4.55;

double convertEURtoPLN(double amount) {
    return amount * EXCHANGE_RATE_EUR_TO_PLN;
}

int main() {
    double amount = 100.0; // Amount in Euros
    double plnAmount = convertEURtoPLN(amount);
    std::cout << "The equivalent amount in Polish Zloty is: " << plnAmount << std::endl;
    return 0;
}
