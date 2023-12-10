std::vector<std::vector<int>> sortClusters(const std::vector<std::vector<double>>& input_data, int ncluster) {
    // Perform k-means clustering on the input data
    std::vector<std::vector<double>> clusters = kMeansClustering(input_data, ncluster);

    // Sort the clusters based on their IDs
    std::vector<std::vector<int>> cluster_ids(ncluster);
    for (int i = 0; i < clusters.size(); i++) {
        cluster_ids[clusters[i] - 1].push_back(i);
    }
    std::sort(cluster_ids.begin(), cluster_ids.end(), GenUtils::less_vectors);

    return cluster_ids;
}
