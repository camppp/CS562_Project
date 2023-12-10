#include <vector>
#include <unordered_map>
#include "graph.cpp"

Graph reorder(const Graph& g, const vector<int>& to) {
    int n = g.size();
    Graph reorderedGraph(n);

    // Create a mapping from original vertex indices to their new positions
    unordered_map<int, int> vertexMap;
    for (int i = 0; i < n; i++) {
        vertexMap[to[i]] = i;
    }

    // Reorder the vertices and their adjacency lists
    for (int i = 0; i < n; i++) {
        int newVertex = to[i];
        for (int neighbor : g[i]) {
            reorderedGraph[vertexMap[newVertex]].push_back(vertexMap[to[neighbor]]);
        }
    }

    return reorderedGraph;
}
