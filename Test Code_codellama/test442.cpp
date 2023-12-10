int maxCookies(vector<int> g, vector<int> s) {
    int max_cookies = 0;
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            if (g[i] <= s[j]) {
                max_cookies++;
                break;
            }
        }
    }
    return max_cookies;
}
