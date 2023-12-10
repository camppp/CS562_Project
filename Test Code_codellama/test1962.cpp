void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack) {
    // Mark the current node as visited
    visited[v] = true;

    // Recursively sort all of its neighbors
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            topologicalSortUtil(*i, visited, Stack);
        }
    }

    // Push the current node onto the stack
    Stack.push(v);
}
