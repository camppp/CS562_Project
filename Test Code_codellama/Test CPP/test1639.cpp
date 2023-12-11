void updateFlowOnPath(const std::vector<mojo::gfx::composition::Node*>& path, int flowValue, mojo::gfx::composition::Node* container) {
    // Update the flow on the path
    for (auto node : path) {
        // Update the flow on the node
        node->flow += flowValue;

        // Update the flow on the edges
        for (auto edge : node->edges) {
            // Update the flow on the edge
            edge->flow += flowValue;
        }
    }

    // Update the flow on the container node
    container->flow += flowValue;
}
