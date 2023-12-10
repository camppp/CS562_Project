python
def simulateParticle(side, iterations, v0, v1, v2, v3):
    x, y = 0, 0
    for _ in range(iterations):
        if x == 0 and y < side:  # moving along edge v0
            y = min(y + v0, side)
        elif y == side and x < side:  # moving along edge v1
            x = min(x + v1, side)
        elif x == side and y > 0:  # moving along edge v2
            y = max(y + v2, 0)
        elif y == 0 and x > 0:  # moving along edge v3
            x = max(x + v3, 0)
    return round(x, 2), round(y, 2)
