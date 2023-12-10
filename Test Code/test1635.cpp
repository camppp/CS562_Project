#include <array>
#include <cmath>

template <std::size_t N>
double maxMagnitude(const std::array<double, N>& realPart, const std::array<double, N>& imagPart) {
    double maxMag = 0.0;
    for (std::size_t i = 0; i < N; ++i) {
        double mag = std::sqrt(realPart[i] * realPart[i] + imagPart[i] * imagPart[i]);
        if (mag > maxMag) {
            maxMag = mag;
        }
    }
    return maxMag;
}
