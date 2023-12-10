#include <iostream>
#include <unordered_map>
#include <unordered_set>

class DirectedGraph {
private:
    std::unordered_map<int, std::unordered_set<int>> adjacencyList;
    std::unordered_map<std::pair<int, int>, double> edgeWeights;

public:
    bool addEdge(int tail, int head) {
        if (adjacencyList[tail].count(head) > 0) {
            return false;  // Edge already exists
        }
        adjacencyList[tail].insert(head);
        return true;
    }

    bool addEdge(int tail, int head, double weight) {
        if (edgeWeights.count({tail, head}) > 0) {
            return false;  // Edge already exists
        }
        adjacencyList[tail].insert(head);
        edgeWeights[{tail, head}] = weight;
        return true;
    }

    ~DirectedGraph() {
        // Destructor to release any allocated resources
    }
};

int main() {
    DirectedGraph graph;
    graph.addEdge(1, 2);
    graph.addEdge(2, 3, 5.0);
    return 0;
}
