std::vector<int> topologicalSort(const std::vector<std::vector<int>>& graph) {
    // Create a vector to store the sorted nodes
    std::vector<int> sorted;

    // Create a vector to store the nodes that have no incoming edges
    std::vector<int> sources;

    // Initialize the sources vector with the nodes that have no incoming edges
    for (int i = 0; i < graph.size(); i++) {
        if (graph[i].empty()) {
            sources.push_back(i);
        }
    }

    // While there are still nodes to visit
    while (!sources.empty()) {
        // Get the next node to visit
        int node = sources.back();
        sources.pop_back();

        // Add the node to the sorted vector
        sorted.push_back(node);

        // Remove the node from the graph
        graph[node].clear();

        // Add the nodes that the current node has directed edges to to the sources vector
        for (int neighbor : graph[node]) {
            if (--graph[neighbor].size() == 0) {
                sources.push_back(neighbor);
            }
        }
    }

    // Return the sorted vector
    return sorted;
}
