python
def circleRelationship(x1, y1, r1, x2, y2, r2):
    dist = ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5
    if dist > r1 + r2:
        return "None"
    elif x1 == x2 and y1 == y2 and r1 == r2:
        return "More"
    elif dist < r1 and dist + r2 == r1:
        return "One"
    elif dist < r2 and dist + r1 == r2:
        return "One"
    else:
        return "None"
