def maxProfit(self, prices: List[int]) -> int:
    if len(prices) == 0:
        return 0
    min_price = prices[0]
    max_profit = 0
    for i in range(1, len(prices)):
        if prices[i] > prices[i - 1]:
            max_profit = max(max_profit, prices[i] - min_price)
        else:
            min_price = prices[i]
    return max_profit