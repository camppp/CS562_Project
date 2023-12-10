void dfs(string node, vector<string>& path, unordered_map<string, int>& counter, unordered_map<string, vector<string>>& graph) {
    while (counter[node] < graph[node].size()) {
        string nextNode = graph[node][counter[node]++];
        dfs(nextNode, path, counter, graph);
    }
    path.insert(path.begin(), node);
}
