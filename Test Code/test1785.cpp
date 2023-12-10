#include <iostream>
#include <vector>
#include <algorithm>

class WeightedDirectedGraph {
private:
    struct Item {
        std::vector<std::pair<Item*, int>> children;
    };
    std::vector<Item*> items;

public:
    void add_item() {
        items.push_back(new Item());
    }

    void add_link(Item* from, Item* to, int weight) {
        auto& children = from->children;
        children.emplace_back(to, weight);
    }

    int shortest_weight(Item* from, Item* to) {
        // Dijkstra's algorithm to find the shortest weight between two items
        std::vector<int> dist(items.size(), INT_MAX);
        dist[from - &items[0]] = 0;

        std::vector<bool> visited(items.size(), false);

        for (size_t i = 0; i < items.size() - 1; ++i) {
            int u = -1;
            for (size_t j = 0; j < items.size(); ++j) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }

            visited[u] = true;

            for (const auto& child : items[u]->children) {
                int v = child.first - &items[0];
                int weight = child.second;
                if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        return dist[to - &items[0]];
    }
};

int main() {
    WeightedDirectedGraph graph;
    graph.add_item(); // Add item 1
    graph.add_item(); // Add item 2

    // Add a directed link from item 1 to item 2 with weight 5
    graph.add_link(graph.items[0], graph.items[1], 5);

    // Retrieve the shortest weight from item 1 to item 2
    std::cout << "Shortest weight from item 1 to item 2: " << graph.shortest_weight(graph.items[0], graph.items[1]) << std::endl;

    return 0;
}
