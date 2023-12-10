#include <iostream>
#include <iomanip>
#include <cmath>

double harmonic_mean(double a, double b) {
    return 2.0 * a * b / (a + b);
}

int main() {
    double precision, recall, sum, score;
    std::cin >> precision >> recall >> sum >> score;

    std::cout << std::setprecision(9) << harmonic_mean(precision, recall) / sum << '\n'
              << score / sum << '\n';

    return 0;
}
