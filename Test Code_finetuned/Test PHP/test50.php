from typing import List, Dict, Tuple

def calculate_total_price(items: List[str], quantities: List[int], base_prices: Dict[str, float], discount_rules: Dict[str, Tuple[int, float]]) -> float:
    total_price = 0.0
    for item, quantity in zip(items, quantities):
        base_price = base_prices[item]
        discount_rule = discount_rules.get(item, (0, 0.0))
        discount_quantity, discount_percentage = discount_rule
        if quantity >= discount_quantity:
            total_price += base_price * quantity * (1 - discount_percentage)
        else:
            total_price += base_price * quantity
    return total_price