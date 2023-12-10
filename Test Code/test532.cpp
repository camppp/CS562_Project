#include <vector>
#include <array>
#include <numeric>

double calculateMSD(const std::vector<std::array<double, 3>>& positions) {
    size_t N = positions.size();
    if (N < 2) {
        throw std::invalid_argument("At least two positions are required to calculate MSD.");
    }

    std::array<double, 3> r0 = positions[0];
    double sumSquaredDistances = 0.0;
    for (size_t i = 1; i < N; ++i) {
        double squaredDistance = 0.0;
        for (size_t j = 0; j < 3; ++j) {
            double diff = positions[i][j] - r0[j];
            squaredDistance += diff * diff;
        }
        sumSquaredDistances += squaredDistance;
    }

    return sumSquaredDistances / N;
}
