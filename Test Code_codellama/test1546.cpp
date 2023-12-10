#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

// Define the bad_graph exception class
class bad_graph : public std::invalid_argument {
public:
    bad_graph(const std::string& message) : std::invalid_argument(message) {}
};

// Sample graph algorithm that may throw the bad_graph exception
void graph_traversal(const std::vector<std::vector<int>>& graph) {
    // Check for invalid graph structure
    if (graph.empty()) {
        throw bad_graph("Invalid graph structure");
    }

    // Traverse the graph
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            if (graph[i][j] < 0) {
                throw bad_graph("Negative edge weight");
            }
        }
    }
}

int main() {
    // Create a sample graph
    std::vector<std::vector<int>> graph = {
        {0, 1, 2},
        {1, 2, 3},
        {2, 3, 4}
    };

    // Throw the bad_graph exception
    try {
        graph_traversal(graph);
    } catch (const bad_graph& e) {
        std::cout << "Caught bad_graph exception: " << e.what() << std::endl;
    }

    return 0;
}
