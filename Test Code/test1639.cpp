namespace flow {
    void updateFlowOnPath(const std::vector<mojo::gfx::composition::Node*>& path, int flowValue, mojo::gfx::composition::Node* container) {
        // Update the flow on the given path
        for (size_t i = 0; i < path.size() - 1; ++i) {
            // Update the flow on the edge from path[i] to path[i+1]
            // Assuming the graph has an edge class with capacity and flow properties
            // Update the flow on the edge from path[i] to path[i+1] by adding flowValue
            // Ensure to handle the direction of the edge based on the graph representation

            // Pseudocode:
            // edge = findEdgeBetween(path[i], path[i+1])
            // edge.flow += flowValue
        }

        // Update the flow conservation property in the graph
        // Pseudocode:
        // for each node in the path
        //     calculate totalInFlow and totalOutFlow
        //     if (node is not source or sink)
        //         adjust flow based on totalInFlow and totalOutFlow to maintain flow conservation
    }
}  // namespace flow
