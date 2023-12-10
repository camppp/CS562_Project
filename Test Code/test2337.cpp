#include <vector>
#include <cmath>

int sumAbsoluteDifferences(const std::vector<std::vector<int>>& matrixA, const std::vector<std::vector<int>>& matrixB) {
    int sum = 0;
    for (size_t i = 0; i < matrixA.size(); ++i) {
        for (size_t j = 0; j < matrixA[i].size(); ++j) {
            sum += std::abs(matrixA[i][j] - matrixB[i][j]);
        }
    }
    return sum;
}
