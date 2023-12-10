#include <vector>
#include <queue>
#include <algorithm>

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    std::vector<Edge> edges;
};

auto get_heap() noexcept {
    const auto compare = [](const Edge& lhs, const Edge& rhs) noexcept {
        return lhs.weight > rhs.weight;
    };

    return std::priority_queue<Edge, std::vector<Edge>, decltype(compare)>{compare};
}

int findParent(std::vector<int>& parent, int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

void unionSets(std::vector<int>& parent, int x, int y) {
    int xset = findParent(parent, x);
    int yset = findParent(parent, y);
    parent[xset] = yset;
}

std::vector<Edge> findMST(const Graph& graph) {
    std::vector<Edge> result;
    std::vector<int> parent(graph.V, -1);
    auto pq = get_heap();

    for (const auto& edge : graph.edges) {
        pq.push(edge);
    }

    while (!pq.empty() && result.size() < graph.V - 1) {
        Edge nextEdge = pq.top();
        pq.pop();

        int x = findParent(parent, nextEdge.src);
        int y = findParent(parent, nextEdge.dest);

        if (x != y) {
            result.push_back(nextEdge);
            unionSets(parent, x, y);
        }
    }

    return result;
}
