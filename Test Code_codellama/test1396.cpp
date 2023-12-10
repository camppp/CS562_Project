int countDistinctCycles(int enter[], int N) {
    int ans = 0;
    bool visit[N];
    for (int i = 0; i < N; i++) {
        if (!visit[i]) {
            ans++;
            while (!visit[i]) {
                visit[i] = true;
                i = enter[i];
            }
        }
    }
    return ans;
}
