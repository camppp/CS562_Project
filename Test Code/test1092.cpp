vector<int> topologicalSort(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> inDegree(n, 0);
    for (const auto& neighbors : graph) {
        for (int neighbor : neighbors) {
            inDegree[neighbor]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        for (int neighbor : graph[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (result.size() != n) {
        return {};  // Graph contains a cycle
    }

    return result;
}
