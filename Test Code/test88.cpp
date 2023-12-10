#include <vector>
#include <array>

int findLargestSumIndex(const std::vector<std::array<int, 3>>& indices) {
    int maxSum = 0;
    int maxIndex = 0;

    for (int i = 0; i < indices.size(); ++i) {
        int currentSum = indices[i][0] + indices[i][1] + indices[i][2];
        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxIndex = i;
        }
    }

    return maxIndex;
}
