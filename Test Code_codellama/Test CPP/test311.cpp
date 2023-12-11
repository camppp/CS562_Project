vector<int> calculateAnswer(int x) {
    vector<int> ans(210, 0);
    int at = 0;
    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        if (a[i] > a[x]) {
            val[x][a[i]] = 1;
            at++;
        } else if (a[i] < a[x]) {
            val[x][a[i]] = -1;
            at--;
        } else {
            parent[x].push_back(i);
        }
    }
    ans[at] = parent[x].size();
    return ans;
}
