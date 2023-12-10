int longestCommonSubsequence(string S, string T) {
    int n = S.length(), m = T.length();
    vector<vector<int>> LCS(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S[i-1] == T[j-1]) {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            } else if (S[i-1] == '*') {
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            } else {
                LCS[i][j] = 0;
            }
        }
    }

    return LCS[n][m];
}
