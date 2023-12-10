python
def knapsackMaxValue(W, w, p):
    n = len(w)
    ans = [[-1 for _ in range(n)] for _ in range(W+1)]

    def max_profit(W, n):
        if n < 0 or W <= 0:
            return 0
        if ans[W][n] != -1:
            return ans[W][n]
        if W >= w[n]:
            aux1 = max_profit(W - w[n], n - 1) + p[n]
        else:
            aux1 = 0
        aux2 = max_profit(W, n - 1)
        if aux1 > aux2:
            ans[W][n] = aux1
            return aux1
        ans[W][n] = aux2
        return aux2

    return max_profit(W, n - 1)
