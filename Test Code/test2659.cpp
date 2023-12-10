int strStr(string haystack, string needle) {
    if (needle.empty()) return 0; // Empty needle matches at index 0

    int n = haystack.size(), m = needle.size();
    vector<vector<int>> dfa(256, vector<int>(m + 1, 0));

    // DFA construction
    dfa[needle[0]][0] = 1;
    int lps = 0;
    for (int state = 1; state < m; state++) {
        for (int c = 0; c < 256; c++)
            dfa[c][state] = dfa[c][lps];
        dfa[needle[state]][state] = state + 1;
        lps = dfa[needle[state]][lps];
    }

    // Pattern matching using DFA
    int state = 0;
    for (int i = 0; i < n; i++) {
        state = dfa[haystack[i]][state];
        if (state == m) return i - m + 1; // Pattern found at index i - m + 1
    }

    return -1; // Pattern not found in the text
}
