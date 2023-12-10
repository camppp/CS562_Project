#include <unordered_map>
#include <vector>
#include <queue>

std::vector<int> shortestPath(const std::unordered_map<int, std::vector<int>>& graph, int start, int end) {
    std::unordered_map<int, int> parent;
    std::queue<int> q;
    q.push(start);
    parent[start] = -1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == end) {
            std::vector<int> path;
            while (current != -1) {
                path.push_back(current);
                current = parent[current];
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (int neighbor : graph.at(current)) {
            if (parent.find(neighbor) == parent.end()) {
                q.push(neighbor);
                parent[neighbor] = current;
            }
        }
    }

    // If no path is found, return an empty path
    return {};
}
