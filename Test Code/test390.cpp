#include <vector>
#include <algorithm>
#include <cmath>

class GenUtils {
public:
    static bool less_vectors(const std::vector<int>& v1, const std::vector<int>& v2) {
        return v1.size() < v2.size();
    }
};

double euclideanDistance(const std::vector<double>& point1, const std::vector<double>& point2) {
    double sum = 0.0;
    for (size_t i = 0; i < point1.size(); i++) {
        sum += std::pow(point1[i] - point2[i], 2);
    }
    return std::sqrt(sum);
}

std::vector<std::vector<int>> sortClusters(double** input_data, int ncluster, int num_points) {
    // Perform k-means clustering
    // ... (implementation of k-means clustering algorithm)

    // Assume clusters and cluster_ids are populated with the clustering results
    std::vector<int> clusters;  // Example clusters
    std::vector<std::vector<int>> cluster_ids(ncluster);

    for (int i = 0; i < clusters.size(); i++) {
        cluster_ids[clusters[i] - 1].push_back(i);
    }

    // Sort the clusters based on their IDs
    std::sort(cluster_ids.begin(), cluster_ids.end(), GenUtils::less_vectors);

    return cluster_ids;
}
