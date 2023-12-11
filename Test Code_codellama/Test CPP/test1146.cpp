int countReachableNodes(vector<vector<int>> adjList, int u) {
    int count = 0;
    vector<bool> visited(adjList.size(), false);
    stack<int> s;
    s.push(u);
    visited[u] = true;
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        count++;
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                s.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    return count;
}
