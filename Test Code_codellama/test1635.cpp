#include <cmath>

double maxMagnitude(const std::array<double, N>& realPart, const std::array<double, N>& imagPart) {
    double maxMagnitude = 0.0;
    for (int i = 0; i < N; i++) {
        double real = realPart[i];
        double imag = imagPart[i];
        double magnitude = std::sqrt(real * real + imag * imag);
        if (magnitude > maxMagnitude) {
            maxMagnitude = magnitude;
        }
    }
    return maxMagnitude;
}
