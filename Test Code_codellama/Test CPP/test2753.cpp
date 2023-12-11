#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the distance between two data points
double distance(const vector<double>& a, const vector<double>& b) {
    double sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt(sum);
}

// Function to select clusters based on the given criteria
vector<vector<double>> cluster_data(const vector<vector<double>>& data_points, int min_cluster_size, int max_cluster_size, pair<int, int> knmax) {
    // Initialize the clusters
    vector<vector<double>> clusters;

    // Loop through the data points and assign them to clusters
    for (int i = 0; i < data_points.size(); i++) {
        // Check if the current data point is within the minimum and maximum cluster size
        if (data_points[i].size() >= min_cluster_size && data_points[i].size() <= max_cluster_size) {
            // Check if the current data point is within the knmax distance from the existing clusters
            bool is_within_knmax = true;
            for (int j = 0; j < clusters.size(); j++) {
                if (distance(data_points[i], clusters[j]) > knmax.first) {
                    is_within_knmax = false;
                    break;
                }
            }
            if (is_within_knmax) {
                // Add the data point to the current cluster
                clusters[clusters.size() - 1].push_back(data_points[i]);
            } else {
                // Create a new cluster
                vector<double> new_cluster;
                new_cluster.push_back(data_points[i]);
                clusters.push_back(new_cluster);
            }
        }
    }

    return clusters;
}

int main() {
    // Example data points
    vector<vector<double>> data_points = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18},
        {19, 20, 21},
        {22, 23, 24},
        {25, 26, 27},
        {28, 29, 30}
    };

    // Call the cluster_data function with the given parameters
    vector<vector<double>> clusters = cluster_data(data_points, 5, 10, make_pair(5, 10));

    // Print the clusters
    for (int i = 0; i < clusters.size(); i++) {
        cout << "Cluster " << i + 1 << ": ";
        for (int j = 0; j < clusters[i].size(); j++) {
            cout << clusters[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
