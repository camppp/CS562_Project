python
def calculatePolygonArea(vertices):
    area = 0
    n = len(vertices)

    for i in range(n):
        x1, y1 = vertices[i]
        x2, y2 = vertices[(i + 1) % n]  # Wrap around to the first vertex for the last edge

        area += (x1 * y2 - x2 * y1)

    return abs(area) / 2
