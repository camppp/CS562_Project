import random
from typing import List

def add_building(pixeldata, x, width, height):
    # Implementation not provided
    pass

def generate_city_skyline(seed: int, num_buildings: int) -> List[List[int]]:
    random.seed(seed)
    skyline = [[0 for _ in range(10)] for _ in range(8)]
    x = 0
    for _ in range(num_buildings):
        gap = random.randint(5, 20)
        x += gap
        width = random.randint(10, 40)
        height = random.randint(20, 50)
        add_building(skyline, x, width, height)
        x += width
    return skyline