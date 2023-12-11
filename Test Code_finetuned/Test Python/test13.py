import math

def calculate_distances(dataset, query_point):
    distances = []
    for i, record in enumerate(dataset):
        class_label, feature1, feature2, feature3 = record
        distance = math.sqrt((feature1 - query_point[0])**2 + (feature2 - query_point[1])**2 + (feature3 - query_point[2])**2)
        distances.append((i, distance))
    distances.sort(key=lambda x: x[1])
    return distances