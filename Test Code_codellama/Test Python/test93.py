def single_precision_sum(numbers: List[float]) -> float:
    sum = 0.0
    for number in numbers:
        sum += float32(number)
    return sum