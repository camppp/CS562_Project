#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

// Function to find the shortest path between two nodes in a weighted graph using Dijkstra's algorithm
pair<vector<int>, int> dijkstraShortestPath(const vector<vector<pair<int, int>>>& graph, int source, int destination) {
    // Create a priority queue to store the nodes to be processed
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialize the distances and previous nodes for all nodes
    vector<int> distances(graph.size(), INT_MAX);
    vector<int> previous(graph.size(), -1);

    // Initialize the distances and previous nodes for the source node
    distances[source] = 0;
    previous[source] = -1;

    // Add the source node to the priority queue
    pq.push(make_pair(0, source));

    // Loop until the priority queue is empty
    while (!pq.empty()) {
        // Get the node with the minimum distance from the priority queue
        int node = pq.top().second;
        pq.pop();

        // If the node is the destination node, return the shortest path
        if (node == destination) {
            vector<int> path;
            int distance = 0;

            // Construct the shortest path by following the previous nodes
            for (int i = destination; i != -1; i = previous[i]) {
                path.push_back(i);
                distance += distances[i];
            }

            // Return the shortest path and its distance
            return make_pair(path, distance);
        }

        // Process the neighbors of the current node
        for (auto neighbor : graph[node]) {
            int neighborNode = neighbor.first;
            int weight = neighbor.second;

            // If the neighbor node is not processed yet and the current distance plus the weight is less than the previous distance, update the distances and previous nodes
            if (distances[neighborNode] > distances[node] + weight) {
                distances[neighborNode] = distances[node] + weight;
                previous[neighborNode] = node;
            }
        }
    }

    // If there is no path from the source to the destination, return an empty path and a distance of infinity
    return make_pair(vector<int>(), INT_MAX);
}

int main() {
    // Test the function with a graph and a source and destination node
    vector<vector<pair<int, int>>> graph = {
        {{1, 4}, {2, 2}},
        {{3, 5}},
        {{1, 1}, {3, 8}},
        {}
    };
    pair<vector<int>, int> result = dijkstraShortestPath(graph, 0, 3);
    cout << "Shortest path: ";
    for (int i = 0; i < result.first.size(); i++) {
        cout << result.first[i] << " ";
    }
    cout << endl;
    cout << "Distance: " << result.second << endl;

    return 0;
}
