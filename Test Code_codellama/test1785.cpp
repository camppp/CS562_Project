#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

class WeightedDirectedGraph {
private:
    // Data structure to represent the items in the graph
    std::vector<int> items;

    // Data structure to represent the links between items, along with their weights
    std::unordered_map<int, std::vector<std::pair<int, int>>> links;

public:
    // Constructor
    WeightedDirectedGraph() {}

    // Function to add a new item to the graph
    void addItem(int item) {
        items.push_back(item);
    }

    // Function to add a directed link between two items with a specified weight
    void addLink(int from, int to, int weight) {
        links[from].push_back(std::make_pair(to, weight));
    }

    // Function to retrieve the shortest weight between two items
    int getShortestWeight(int from, int to) {
        // Use the provided comparison function to compare the shortest weights of two items
        int shortestWeight = std::numeric_limits<int>::max();
        for (const auto& link : links[from]) {
            if (link.first == to) {
                shortestWeight = std::min(shortestWeight, link.second);
            }
        }
        return shortestWeight;
    }
};
