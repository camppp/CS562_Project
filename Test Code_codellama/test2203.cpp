vector<vector<int>> sortDiagonals(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> sortedMat(m, vector<int>(n));

    // Iterate over each diagonal
    for (int i = 0; i < m; i++) {
        // Iterate over each element in the diagonal
        for (int j = 0; j < n; j++) {
            // Find the index of the element in the diagonal
            int index = i + j;
            // Sort the element in the diagonal
            sort(mat[i][j], mat[i][j] + n, greater<int>());
            // Copy the sorted element to the sorted matrix
            sortedMat[i][j] = mat[i][j];
        }
    }

    return sortedMat;
}
