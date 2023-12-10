#include <array>
#include <vector>

int findLargestSumIndex(const std::vector<std::array<int, 3>>& indices) {
    int largestSum = 0;
    int largestSumIndex = 0;

    for (int i = 0; i < indices.size(); i++) {
        int sum = indices[i][0] + indices[i][1] + indices[i][2];
        if (sum > largestSum) {
            largestSum = sum;
            largestSumIndex = i;
        }
    }

    return largestSumIndex;
}
