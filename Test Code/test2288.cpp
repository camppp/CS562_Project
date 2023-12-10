python
from typing import List

def tallest_building_index(buildings: List[int]) -> int:
    if not buildings:
        return -1

    tallest_height = buildings[0]
    tallest_index = 0

    for i in range(1, len(buildings)):
        if buildings[i] > tallest_height:
            tallest_height = buildings[i]
            tallest_index = i

    return tallest_index
