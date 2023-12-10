python
from typing import List

def max_profit(prices: List[int]) -> int:
    if not prices:
        return 0
    
    max_profit = 0
    min_price = prices[0]
    
    for price in prices:
        if price < min_price:
            min_price = price
        else:
            max_profit = max(max_profit, price - min_price)
    
    return max_profit
