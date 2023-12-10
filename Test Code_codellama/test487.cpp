#include <iostream>
#include <vector>
#include <unordered_map>

class DirectedGraph {
public:
    DirectedGraph() {}

    ~DirectedGraph() {
        for (auto& edge : edges) {
            delete edge;
        }
    }

    bool addEdge(int tail, int head) {
        if (tail < 0 || head < 0) {
            return false;
        }

        if (edges.find(tail) == edges.end()) {
            edges[tail] = std::vector<int>();
        }

        if (edges[tail].find(head) != edges[tail].end()) {
            return false;
        }

        edges[tail].push_back(head);
        return true;
    }

    bool addEdge(int tail, int head, double weight) {
        if (tail < 0 || head < 0) {
            return false;
        }

        if (edges.find(tail) == edges.end()) {
            edges[tail] = std::vector<int>();
        }

        if (edges[tail].find(head) != edges[tail].end()) {
            return false;
        }

        edges[tail].push_back(head);
        weights[tail][head] = weight;
        return true;
    }

private:
    std::unordered_map<int, std::vector<int>> edges;
    std::unordered_map<int, std::unordered_map<int, double>> weights;
};
