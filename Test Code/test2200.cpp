java
public static int minHeightDifference(int[] heights) {
    int n = heights.length;
    int ans = Integer.MAX_VALUE;
    for (int i = 1; i < n; ++i) {
        ans = Math.min(ans, heights[i] - heights[i - 1]);
    }
    return ans;
}
