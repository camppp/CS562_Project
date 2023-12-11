#include "graph.cpp"

Graph reorder(const Graph& g, const vector<int>& to) {
    // Create a new graph with the same number of vertices as the original graph
    Graph new_graph(g.size());

    // Iterate over the vertices in the original graph
    for (int i = 0; i < g.size(); i++) {
        // Get the vertex at the current position in the permutation vector
        int new_vertex = to[i];

        // Add the vertex to the new graph at its new position
        new_graph.add_vertex(new_vertex);

        // Iterate over the neighbors of the vertex in the original graph
        for (int neighbor : g[i]) {
            // Get the position of the neighbor in the permutation vector
            int new_neighbor = to[neighbor];

            // Add the neighbor to the new graph at its new position
            new_graph.add_edge(new_vertex, new_neighbor);
        }
    }

    return new_graph;
}
