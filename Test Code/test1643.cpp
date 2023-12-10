int trappedRainwater(vector<int>& heights) {
    int total = 0;
    for (int i = 1; i < heights.size(); i++) {
        int left = min(heights[i], heights[i-1]);
        int right = min(heights[i], heights[i+1]);
        total += left < right ? left - right : 0;
    }
    return total;
}
