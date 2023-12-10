python
def get_fibonacci_partial_sum_fast(from_num, to_num):
    pisano_period = 60  # Pisano period for modulo 10 is 60
    from_num %= pisano_period
    to_num %= pisano_period

    if to_num < from_num:
        to_num += pisano_period

    fib_sum_to = [0, 1]
    for i in range(2, to_num + 1):
        fib_sum_to.append((fib_sum_to[i - 1] + fib_sum_to[i - 2] + 1) % 10)

    if from_num > 0:
        from_sum = fib_sum_to[from_num - 1]
    else:
        from_sum = 0

    to_sum = fib_sum_to[to_num]

    return (to_sum - from_sum) % 10
