std::vector<std::string> bfsTraversal(const std::string& startNode) {
    std::vector<std::string> result;
    std::queue<std::string> queue;
    std::set<std::string> visited;

    queue.push(startNode);
    visited.insert(startNode);

    while (!queue.empty()) {
        std::string current = queue.front();
        queue.pop();
        result.push_back(current);

        // Get the adjacent nodes of the current node
        for (auto it = visited_.begin(); it != visited_.end(); ++it) {
            if (visited.find(*it) == visited.end()) {
                queue.push(*it);
                visited.insert(*it);
            }
        }
    }

    return result;
}
