bool subsetSumExists(vector<int> wt, int Sum) {
    int n = wt.size();
    bool t[n + 1][Sum + 1];

    for (int i = 0; i <= Sum; i++) t[0][i] = false;
    for (int i = 0; i <= n; i++) t[i][0] = true; // empty set

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= Sum; j++) {
            if (wt[i - 1] <= j) {
                t[i][j] = t[i - 1][j - wt[i - 1]] || t[i - 1][j];
            } else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][Sum];
}
