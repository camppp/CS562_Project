python
def custom_division(x: int, y: int) -> float:
    if y == 0:
        raise ValueError("Division by zero is not allowed")
    
    result = 0.0
    abs_x, abs_y = abs(x), abs(y)
    sign = 1 if (x > 0 and y > 0) or (x < 0 and y < 0) else -1
    
    while abs_x >= abs_y:
        abs_x -= abs_y
        result += 1
    
    if abs_x > 0:
        remainder = abs_x / abs_y
        result += remainder
    
    return result if sign > 0 else -result
