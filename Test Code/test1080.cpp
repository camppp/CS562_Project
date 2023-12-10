python
def maxSumWithConstraints(arr):
    n = len(arr)
    maxSum = [0] * n
    sols = [[] for _ in range(n)]

    for i in range(n - 1, -1, -1):
        if i == n - 1:
            maxSum[i] = arr[i]
            sols[i] = [arr[i]]
        elif i == n - 2:
            maxSum[i] = max(arr[i], arr[i + 1])
            sols[i] = [arr[i]] if arr[i] > arr[i + 1] else [arr[i + 1]]
        else:
            if i + 3 < n:
                maxi = 2 if maxSum[i + 2] > maxSum[i + 3] else 3
                if maxSum[i + 2] == maxSum[i + 3]:
                    l = min(len(sols[i + 2]), len(sols[i + 3]))
                    for j in range(l):
                        if sols[i + 2][j] != sols[i + 3][j]:
                            maxi = sols[i + 2][j] > sols[i + 3][j] ? 2 : 3
                            break
            else:
                maxi = sols[i + 1][j] > sols[i + 2][j] ? 1 : 2

            maxSum[i] = maxSum[i + maxi]
            sols[i] = sols[i + maxi]

    return maxSum[0]
