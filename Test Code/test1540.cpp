python
def canDivideDeck(deck):
    from collections import Counter
    counts = Counter(deck)
    min_count = min(counts.values())
    if min_count < 2:
        return False
    for i in range(2, min_count + 1):
        if all(count % i == 0 for count in counts.values()):
            return True
    return False
