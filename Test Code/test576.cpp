python
def calculateTotalArea(terrainMap):
    totalArea = 0
    for row in terrainMap:
        for elevation in row:
            totalArea += elevation  # area of each cell is the elevation itself
    return totalArea
