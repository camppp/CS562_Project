vector<int> topologicalSort(const vector<vector<int>>& graph) {
    vector<int> order;
    vector<bool> visited(graph.size(), false);
    vector<bool> onStack(graph.size(), false);
    stack<int> stack;

    for (int i = 0; i < graph.size(); i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, onStack, stack);
        }
    }

    while (!stack.empty()) {
        order.push_back(stack.top());
        stack.pop();
    }

    return order;
}

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& onStack, stack<int>& stack) {
    visited[node] = true;
    onStack[node] = true;
    stack.push(node);

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, onStack, stack);
        } else if (onStack[neighbor]) {
            // If we encounter a node that is already on the stack, it means we have a cycle
            return;
        }
    }

    onStack[node] = false;
}
