// Adds an edge to the graph
void addEdge(int from, int to, int capacity) {
    // Create a new edge object
    Edge* edge = new Edge(from, to, capacity);

    // Add the edge to the graph
    graph[from].push_back(edge);
    graph[to].push_back(edge);
}

// Computes the maximum flow from the source to the sink in the graph
int fordFulkerson(int source, int sink) {
    // Initialize the flow to 0
    int flow = 0;

    // Loop until there are no more augmenting paths
    while (true) {
        // Find an augmenting path from the source to the sink
        vector<int> path = findAugmentingPath(source, sink);

        // If there is no augmenting path, return the current flow
        if (path.empty()) {
            return flow;
        }

        // Compute the bottleneck capacity of the augmenting path
        int bottleneck = computeBottleneck(path);

        // Update the flow along the augmenting path
        updateFlow(path, bottleneck);

        // Increment the flow by the bottleneck capacity
        flow += bottleneck;
    }
}

// Finds an augmenting path from the source to the sink in the graph
vector<int> findAugmentingPath(int source, int sink) {
    // Create a queue to store the vertices to visit
    queue<int> queue;

    // Initialize the queue with the source vertex
    queue.push(source);

    // Loop until the sink vertex is reached
    while (queue.front() != sink) {
        // Get the current vertex from the queue
        int vertex = queue.front();

        // Remove the vertex from the queue
        queue.pop();

        // Loop through the edges incident on the vertex
        for (Edge* edge : graph[vertex]) {
            // If the edge is not saturated, add the neighboring vertex to the queue
            if (edge->capacity > edge->flow) {
                queue.push(edge->to);
            }
        }
    }

    // Return the path from the source to the sink
    return queue;
}

// Computes the bottleneck capacity of an augmenting path
int computeBottleneck(vector<int> path) {
    // Initialize the bottleneck capacity to the maximum integer value
    int bottleneck = INT_MAX;

    // Loop through the edges in the path
    for (int i = 0; i < path.size() - 1; i++) {
        // Get the current edge and its neighboring vertices
        Edge* edge = graph[path[i]][path[i + 1]];
        int from = edge->from;
        int to = edge->to;

        // Compute the bottleneck capacity of the edge
        int capacity = edge->capacity - edge->flow;

        // Update the bottleneck capacity if necessary
        if (capacity < bottleneck) {
            bottleneck = capacity;
        }
    }

    // Return the bottleneck capacity
    return bottleneck;
}

// Updates the flow along an augmenting path
void updateFlow(vector<int> path, int bottleneck) {
    // Loop through the edges in the path
    for (int i = 0; i < path.size() - 1; i++) {
        // Get the current edge and its neighboring vertices
        Edge* edge = graph[path[i]][path[i + 1]];
        int from = edge->from;
        int to = edge->to;

        // Update the flow on the edge
        edge->flow += bottleneck;

        // Update the flow on the reverse edge
        graph[to][from]->flow -= bottleneck;
    }
}
