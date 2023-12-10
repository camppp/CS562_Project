python
def canTransform(x: str, y: str, k: int) -> str:
    if len(x) + len(y) <= k:
        return "Yes"  # It is possible to transform x into y by removing all characters and concatenating them

    common_prefix_len = 0
    for i in range(min(len(x), len(y))):
        if x[i] == y[i]:
            common_prefix_len += 1
        else:
            break

    operations_needed = (len(x) - common_prefix_len) + (len(y) - common_prefix_len)
    if operations_needed <= k and (k - operations_needed) % 2 == 0:
        return "Yes"
    else:
        return "No"
