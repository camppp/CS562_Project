int countPeaks(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] >= grid[i][j-1] && grid[i][j] >= grid[i][j+1] &&
                grid[i][j] >= grid[i-1][j] && grid[i][j] >= grid[i+1][j]) {
                count++;
            }
        }
    }

    return count;
}
