python
def pairExists(n, s, d, pairs):
    for pair in pairs:
        if pair[0] + pair[1] > s and abs(pair[0] - pair[1]) > d:
            return "YES"
    return "NO"
