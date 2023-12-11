def calculate_distances(dataset, query_point):
    distances = []
    for i, record in enumerate(dataset):
        dist = ((record[1] - query_point[0])**2 + (record[2] - query_point[1])**2 + (record[3] - query_point[2])**2)**0.5
        distances.append((i, dist))
    distances.sort(key=lambda x: x[1])
    return distances