#include <vector>

struct Edge {
    int u, v;
    Edge(int u, int v) : u(u), v(v) {}
};

bool isCyclicUtil(int v, std::vector<bool>& visited, std::vector<bool>& recStack, const std::vector<std::vector<int>>& adj) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        for (int u : adj[v]) {
            if (!visited[u] && isCyclicUtil(u, visited, recStack, adj)) {
                return true;
            } else if (recStack[u]) {
                return true;
            }
        }
    }
    recStack[v] = false;
    return false;
}

bool hasCycle(std::vector<Edge>& edges, int n) {
    std::vector<std::vector<int>> adj(n);
    for (const auto& edge : edges) {
        adj[edge.u].push_back(edge.v);
    }

    std::vector<bool> visited(n, false);
    std::vector<bool> recStack(n, false);

    for (int i = 0; i < n; ++i) {
        if (isCyclicUtil(i, visited, recStack, adj)) {
            return true;
        }
    }
    return false;
}
