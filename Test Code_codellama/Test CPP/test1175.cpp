template<typename DATA_t = double, typename INDEX_t = int, typename CLUSTER_t = int, class V>
void compute_centroids(int ndim, INDEX_t nobs, const DATA_t* data, CLUSTER_t ncenters, DATA_t* centers, const CLUSTER_t* clusters, const V& sizes) {
    // Initialize the centroids to zero
    for (int i = 0; i < ncenters; i++) {
        for (int j = 0; j < ndim; j++) {
            centers[i * ndim + j] = 0;
        }
    }

    // Compute the centroids for each cluster
    for (int i = 0; i < nobs; i++) {
        int cluster = clusters[i];
        for (int j = 0; j < ndim; j++) {
            centers[cluster * ndim + j] += data[i * ndim + j] / sizes[cluster];
        }
    }
}
