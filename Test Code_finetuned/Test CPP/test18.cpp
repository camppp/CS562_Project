import math
from typing import List, Tuple
from itertools import combinations

def max_distance_points(points: List[Tuple[float, float]]) -> Tuple[Tuple[float, float], Tuple[float, float]]:
    max_distance = 0
    max_points = None
    for point1, point2 in combinations(points, 2):
        distance = math.sqrt((point2[0] - point1[0])**2 + (point2[1] - point1[1])**2)
        if distance > max_distance:
            max_distance = distance
            max_points = (point1, point2)
    return max_points