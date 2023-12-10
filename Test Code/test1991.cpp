#include <vector>
#include <queue>

std::vector<int> topologicalSort(const std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    std::vector<int> inDegree(n, 0);
    for (const auto& neighbors : graph) {
        for (int neighbor : neighbors) {
            inDegree[neighbor]++;
        }
    }

    std::queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    std::vector<int> result;
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
        return std::vector<int>();  // Not a DAG
    }

    return result;
}
