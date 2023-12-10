int countOccurrences(string text, string pattern) {
    int cnt = 0;
    vector<int> pi(pattern.size(), 0);
    int pInd = 0;
    for (int i = 1; i < pattern.size(); i++) {
        while (pInd > 0 && pattern[i] != pattern[pInd]) {
            pInd = pi[pInd-1];
        }
        if (pattern[i] == pattern[pInd]) {
            pi[i] = ++pInd;
        }
    }

    int ind = 0;
    while (ind < text.size()) {
        if (text[ind] == pattern[pInd]) {
            pInd++;
            ind++;
        }
        else if (pInd == 0) { // can't find same string
            ind++;
        }

        if (pattern.size() == pInd) {
            cnt++;
            pInd = pi[pInd-1];
            if (ind == pattern.size()) cnt--;
        }
    }
    return cnt;
}
