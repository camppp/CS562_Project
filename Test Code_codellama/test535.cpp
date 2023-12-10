std::vector<int> shortestPath(const std::unordered_map<int, std::vector<int>>& graph, int start, int end) {
    std::queue<int> queue;
    std::unordered_set<int> visited;
    std::vector<int> path;

    queue.push(start);
    visited.insert(start);

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        if (current == end) {
            break;
        }

        for (int neighbor : graph.at(current)) {
            if (visited.find(neighbor) == visited.end()) {
                queue.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }

    if (visited.find(end) != visited.end()) {
        for (int vertex : visited) {
            if (vertex == end) {
                path.push_back(vertex);
                break;
            }
        }
    }

    return path;
}
