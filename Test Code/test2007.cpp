python
def find_missing_point(x, y):
    # Calculate the missing point to complete the rectangle
    if x[0] == x[1]:
        xa = x[2] + x[0] - x[1]
        ya = y[2] + y[0] - y[1]
    elif x[0] == x[2]:
        xa = x[1] + x[0] - x[2]
        ya = y[1] + y[0] - y[2]
    else:
        xa = x[0] + x[1] - x[2]
        ya = y[0] + y[1] - y[2]
    
    return (xa, ya)
