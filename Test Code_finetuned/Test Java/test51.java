def maxSumOfKSubarrays(a, k, l, m):
    n = len(a)
    dp = [[-1] * (k + 1) for _ in range(n)]
    dp[0][0] = 0
    for i in range(1, n):
        dp[i][0] = 0
        for j in range(1, min(i // l + 1, k + 1)):
            dp[i][j] = max(dp[i - 1][j], dp[i - l][j - 1] + sum(a[i - l + 1:i + 1]))
    for i in range(m, n):
        if dp[i][k]!= -1:
            return dp[i][k]
    return -1