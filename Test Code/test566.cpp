python
def findPythagoreanTripletProduct():
    for a in range(1, 333):
        for b in range(a + 1, 500):
            c = 1000 - b - a
            if a * a + b * b == c * c:
                return a * b * c
    return 0
