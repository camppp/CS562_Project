void dfs(string node, vector<string>& path, unordered_map<string, int>& counter, unordered_map<string, vector<string>>& graph) {
    // Mark the current node as visited
    counter[node] = 1;

    // Add the current node to the path
    path.push_back(node);

    // Visit all unvisited neighbors
    for (auto& neighbor : graph[node]) {
        if (counter[neighbor] == 0) {
            dfs(neighbor, path, counter, graph);
        }
    }
}
