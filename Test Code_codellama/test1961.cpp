bool hasCycle(vector<Edge>& edges, int n) {
    vector<bool> visited(n, false);
    vector<bool> onStack(n, false);
    stack<int> stack;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            stack.push(i);
            onStack[i] = true;
            while (!stack.empty()) {
                int vertex = stack.top();
                stack.pop();
                onStack[vertex] = false;
                for (int j = 0; j < edges.size(); j++) {
                    if (edges[j].u == vertex && !visited[edges[j].v]) {
                        visited[edges[j].v] = true;
                        if (onStack[edges[j].v]) {
                            return true;
                        }
                        stack.push(edges[j].v);
                        onStack[edges[j].v] = true;
                    }
                }
            }
        }
    }
    return false;
}
