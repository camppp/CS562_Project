#include <iostream>
#include <vector>

using namespace std;

int maxRectangleArea(vector<int> &heights) {
    int n = heights.size();
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        int minHeight = heights[i];
        int maxHeight = heights[i];
        int area = 0;

        for (int j = i; j < n; j++) {
            minHeight = min(minHeight, heights[j]);
            maxHeight = max(maxHeight, heights[j]);
            area += minHeight * (j - i + 1);
        }

        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Maximum rectangle area: " << maxRectangleArea(heights) << endl;
    return 0;
}
