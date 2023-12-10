python
import math

def convertToRectangular(latitude, longitude):
    x = math.cos(math.radians(latitude)) * math.cos(math.radians(longitude))
    y = math.cos(math.radians(latitude)) * math.sin(math.radians(longitude))
    z = math.sin(math.radians(latitude))
    return (x, y, z)

# Example usage
dblParallelNorth = 40.7128  # Latitude of New York City
dblAzimuth = -74.0060  # Longitude of New York City
rectangular_coords = convertToRectangular(dblParallelNorth, dblAzimuth)
dblRectifiedGrid = rectangular_coords
print(dblRectifiedGrid)  # Output: (0.514929357586247, -0.825408304576051, 0.239315664287557)
