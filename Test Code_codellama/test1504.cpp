c
int isCyclic(int numVertices, int numEdges, int (*edges)[2]) {
    // Create a boolean array to keep track of visited vertices
    bool visited[numVertices];
    // Initialize all vertices as unvisited
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }
    // Iterate over all edges
    for (int i = 0; i < numEdges; i++) {
        // Get the two vertices connected by the current edge
        int u = edges[i][0];
        int v = edges[i][1];
        // If either vertex is already visited, the graph contains a cycle
        if (visited[u] || visited[v]) {
            return 1;
        }
        // Mark the current vertex as visited
        visited[u] = true;
        // Recursively check the other vertex
        if (isCyclic(numVertices, numEdges, edges, v, visited)) {
            return 1;
        }
    }
    // If no cycle was found, the graph is acyclic
    return 0;
}
