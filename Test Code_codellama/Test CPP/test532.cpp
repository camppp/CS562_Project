#include <iostream>
#include <vector>
#include <array>
#include <cmath>

double calculateMSD(const std::vector<std::array<double, 3>>& positions) {
    double msd = 0;
    int N = positions.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                double rij = sqrt(pow(positions[i][0] - positions[j][0], 2) +
                                  pow(positions[i][1] - positions[j][1], 2) +
                                  pow(positions[i][2] - positions[j][2], 2));
                msd += rij * rij;
            }
        }
    }
    msd /= N * (N - 1);
    return msd;
}
