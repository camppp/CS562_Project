import math

def is_parallelogram(vertices):
    # Calculate the distance between two points
    def distance(p1, p2):
        return math.sqrt((p2[0] - p1[0])**2 + (p2[1] - p1[1])**2)

    # Calculate the distance between the first two and the last two points
    d1 = distance(vertices[0], vertices[1])
    d2 = distance(vertices[2], vertices[3])

    # If the distances are not equal, the quadrilateral is not a parallelogram
    if d1!= d2:
        return False

    # Calculate the distance between the second and third points
    d3 = distance(vertices[1], vertices[2])
    d4 = distance(vertices[0], vertices[3])

    # If the distances are not equal, the quadrilateral is not a parallelogram
    if d3!= d4:
        return False

    # If we've made it this far, the quadrilateral is a parallelogram
    return True