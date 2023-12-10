#include <iostream>
#include <vector>

void addEdge(std::vector<std::vector<int>>& ad, int u, int v) {
    --u; // Adjust for 0-indexing
    --v; // Adjust for 0-indexing
    ad[u].push_back(v); // Add v to the adjacency list of u
    ad[v].push_back(u); // Add u to the adjacency list of v
}
