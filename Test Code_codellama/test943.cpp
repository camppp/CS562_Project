def calculatePolygonArea(vertices):
    area = 0
    for i in range(len(vertices) - 1):
        area += (vertices[i][0] - vertices[i + 1][0]) * (vertices[i][1] + vertices[i + 1][1])
    return area / 2
