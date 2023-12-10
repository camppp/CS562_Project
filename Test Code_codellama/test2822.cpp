std::vector<Edge> findMST(const Graph& graph) {
    // Create a priority queue using the custom comparison function
    auto cmp = [](const Edge& e1, const Edge& e2) {
        return e1.weight < e2.weight;
    };
    auto pq = get_heap(cmp);

    // Initialize the priority queue with all edges in the graph
    for (int i = 0; i < graph.E; i++) {
        pq.push(graph.edges[i]);
    }

    // Initialize the minimum spanning tree with the first edge
    std::vector<Edge> mst;
    mst.push_back(pq.top());
    pq.pop();

    // Loop until the priority queue is empty
    while (!pq.empty()) {
        // Get the next edge with the minimum weight
        Edge edge = pq.top();
        pq.pop();

        // Check if the edge is already in the minimum spanning tree
        if (std::find(mst.begin(), mst.end(), edge) != mst.end()) {
            continue;
        }

        // Add the edge to the minimum spanning tree
        mst.push_back(edge);

        // Update the priority queue with the new edge
        pq.push(edge);
    }

    return mst;
}
