java
public int countDistinctCycles(int[] enter) {
    int N = enter.length;
    boolean[] visit = new boolean[N];
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (!visit[i]) {
            ans++;
        }
        int j = i;
        while (!visit[j]) {
            visit[j] = true;
            j = enter[j];
        }
    }
    return ans;
}
