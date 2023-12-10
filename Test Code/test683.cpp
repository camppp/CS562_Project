python
def base_repr(number: int, base: int = 2, padding: int = 0) -> str:
    if number < 0:
        raise ValueError("Number must be a non-negative integer")

    if base < 2 or base > 36:
        raise ValueError("Base must be an integer between 2 and 36")

    if padding < 0:
        raise ValueError("Padding must be a non-negative integer")

    digits = "0123456789abcdefghijklmnopqrstuvwxyz"
    result = ""
    while number > 0:
        result = digits[number % base] + result
        number //= base

    if padding > 0 and len(result) < padding:
        result = "0" * (padding - len(result)) + result

    return result
