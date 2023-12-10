int minUniqueSubstringLength(string S, int len) {
    int n = S.length();
    vector<bool> seen(n - len + 1, false);
    int min_len = n;

    for (int i = 0; i < n - len + 1; i++) {
        string substr = S.substr(i, len);
        if (!seen[i]) {
            seen[i] = true;
            int j = i + len;
            while (j < n && !seen[j]) {
                seen[j] = true;
                j += len;
            }
            min_len = min(min_len, j - i);
        }
    }

    return min_len;
}
