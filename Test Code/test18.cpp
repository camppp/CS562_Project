python
from typing import List, Tuple

def max_distance_points(points: List[Tuple[float, float]]) -> Tuple[Tuple[float, float], Tuple[float, float]]:
    max_distance = 0
    max_points = ()
    
    for i in range(len(points)):
        for j in range(i+1, len(points)):
            distance = ((points[j][0] - points[i][0])**2 + (points[j][1] - points[i][1])**2)**0.5
            if distance > max_distance:
                max_distance = distance
                max_points = (points[i], points[j])
    
    return max_points
