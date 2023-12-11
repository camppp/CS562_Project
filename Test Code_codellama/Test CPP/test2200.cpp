int minHeightDifference(int heights[], int n) {
    int minDiff = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        int diff = abs(heights[i] - heights[i + 1]);
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    return minDiff;
}
