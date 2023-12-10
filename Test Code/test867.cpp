python
def calculatePolygonArea(vertices):
    if len(vertices) < 3:
        return 0
    
    area = 0
    n = len(vertices)
    for i in range(n):
        j = (i + 1) % n
        area += vertices[i][0] * vertices[j][1] - vertices[j][0] * vertices[i][1]
    
    return abs(area) / 2
