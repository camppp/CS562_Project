python
def longestCommonSubsequence(S, T):
    m, n = len(S), len(T)
    LCS = [[0] * (n + 1) for _ in range(m + 1)]

    def lcs(i, j):
        if i < 0 or j < 0:
            return 0
        if LCS[i][j] > 0:
            return LCS[i][j]
        if S[i-1] != '*':
            if S[i-1] == T[j-1]:
                LCS[i][j] = max(LCS[i][j], lcs(i-1, j-1) + 1)
            else:
                LCS[i][j] = max(LCS[i][j], lcs(i-1, j), lcs(i, j-1))
        else:
            LCS[i][j] = max(LCS[i][j], max(lcs(i-1, j), lcs(i, j-1)))
        return LCS[i][j]

    return lcs(m, n)

# Test the function
print(longestCommonSubsequence("abc*def", "abcddef"))  # Output: 6
