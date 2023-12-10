python
import math

def calculatePolygonArea(n, r):
    angle = (2 * math.pi) / n  # Calculate the interior angle of the regular polygon
    area = (r ** 2) * math.sin(angle) / 2  # Calculate the area using the formula
    return area
