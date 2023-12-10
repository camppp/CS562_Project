template<typename DATA_t = double, typename INDEX_t = int, typename CLUSTER_t = int, class V>
void compute_centroids(int ndim, INDEX_t nobs, const DATA_t* data, CLUSTER_t ncenters, DATA_t* centers, const CLUSTER_t* clusters, const V& sizes) {
    // Initialize arrays to store the sum of data points and the count of data points for each cluster
    std::vector<DATA_t> sum(ndim * ncenters, 0);
    std::vector<int> count(ncenters, 0);

    // Iterate through the data points and accumulate the sum for each cluster
    for (INDEX_t i = 0; i < nobs; ++i) {
        CLUSTER_t cluster = clusters[i];
        for (int j = 0; j < ndim; ++j) {
            sum[cluster * ndim + j] += data[i * ndim + j];
        }
        count[cluster]++;
    }

    // Calculate the centroids by dividing the sum by the count for each cluster
    for (CLUSTER_t k = 0; k < ncenters; ++k) {
        if (count[k] > 0) {
            for (int j = 0; j < ndim; ++j) {
                centers[k * ndim + j] = sum[k * ndim + j] / static_cast<DATA_t>(count[k]);
            }
        }
    }
}
