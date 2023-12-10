python
def cluster_data(data_points, min_cluster_size=1, max_cluster_size=None, knmax=None):
    # Sort data points based on some criteria, e.g., distance from centroid
    sorted_data = sorted(data_points, key=lambda x: some_criteria(x))

    clusters = []
    current_cluster = []

    for point in sorted_data:
        if len(current_cluster) < min_cluster_size:
            current_cluster.append(point)
        elif max_cluster_size and len(current_cluster) >= max_cluster_size:
            clusters.append(current_cluster)
            current_cluster = [point]
        else:
            current_cluster.append(point)

    if current_cluster:  # Add the remaining points as a cluster
        clusters.append(current_cluster)

    return clusters
