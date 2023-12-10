bool canPartition(vector<int>& a) {
    int n = a.size();
    int s = accumulate(a.begin(), a.end(), 0);
    if (s % 2 != 0) {
        return false;  // If the total sum is odd, it cannot be divided into two equal subsets
    }
    s /= 2;  // We need to find if there exists a subset with sum equal to s

    bool t[n + 1][s + 1];
    for (int i = 0; i <= n; i++) {
        t[i][0] = true;  // Base case: an empty subset can always have a sum of 0
    }
    for (int i = 1; i <= s; i++) {
        t[0][i] = false;  // Base case: an empty array cannot have a non-zero sum
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {
            if (a[i - 1] <= j) {
                t[i][j] = t[i - 1][j - a[i - 1]] || t[i - 1][j];
            } else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][s];
}
