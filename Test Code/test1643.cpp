#include <vector>
#include <algorithm>

int trappedRainwater(std::vector<int>& heights) {
    int n = heights.size();
    if (n <= 2) {
        return 0; // Cannot trap water with less than 3 buildings
    }

    std::vector<int> leftMax(n), rightMax(n);
    leftMax[0] = heights[0];
    rightMax[n - 1] = heights[n - 1];

    for (int i = 1; i < n; ++i) {
        leftMax[i] = std::max(leftMax[i - 1], heights[i]);
    }

    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = std::max(rightMax[i + 1], heights[i]);
    }

    int trappedWater = 0;
    for (int i = 0; i < n; ++i) {
        trappedWater += std::max(0, std::min(leftMax[i], rightMax[i]) - heights[i]);
    }

    return trappedWater;
}
