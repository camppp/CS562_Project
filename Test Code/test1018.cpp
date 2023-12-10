java
public static int longestIncreasingSubsequence(int[] dp, int N) {
    int[] lis = new int[N];
    int max = 0;

    for (int i = 0; i < N; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if (dp[i] > dp[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
        if (lis[i] > max) {
            max = lis[i];
        }
    }
    return max;
}
