std::vector<std::string> bfsTraversal(const std::string& startNode) {
    std::vector<std::string> visited;
    std::queue<std::string> queue;
    queue.push(startNode);
    visited.push_back(startNode);

    while (!queue.empty()) {
        std::string currentNode = queue.front();
        queue.pop();

        for (const auto& neighbor : getNeighbors(currentNode)) {
            if (visited.find(neighbor) == visited.end()) {
                queue.push(neighbor);
                visited.push_back(neighbor);
            }
        }
    }

    return visited;
}
