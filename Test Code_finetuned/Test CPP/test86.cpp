#include <vector>
#include <array>
#include <algorithm>

int findLargestSumIndex(const std::vector<std::array<int, 3>>& indices) {
    int maxSum = -1;
    int maxIndex = -1;

    for (int i = 0; i < indices.size(); i++) {
        int sum = std::accumulate(indices[i].begin(), indices[i].end(), 0);
        if (sum > maxSum) {
            maxSum = sum;
            maxIndex = i;
        }
    }

    return maxIndex;
}