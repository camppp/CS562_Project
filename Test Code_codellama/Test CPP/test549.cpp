def custom_division(x: int, y: int) -> float:
    if y == 0:
        return float('inf')
    else:
        return x * (1 / y)
