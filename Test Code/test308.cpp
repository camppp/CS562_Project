#include <vector>
#include <queue>
#include <limits>

std::pair<std::vector<int>, int> dijkstraShortestPath(const std::vector<std::vector<std::pair<int, int>>>& graph, int source, int destination) {
    int n = graph.size();
    std::vector<int> distance(n, std::numeric_limits<int>::max());
    std::vector<int> parent(n, -1);
    std::vector<bool> visited(n, false);

    distance[source] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (!visited[v] && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                parent[v] = u;
                pq.push({distance[v], v});
            }
        }
    }

    if (distance[destination] == std::numeric_limits<int>::max()) {
        return {{}, std::numeric_limits<int>::max()};
    }

    std::vector<int> path;
    for (int v = destination; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());

    return {path, distance[destination]};
}
