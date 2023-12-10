void bfs(map<string, vector<string> > &g, string c, set<string> &comp) {
    queue<string> q;
    q.push(c);
    comp.insert(c);  // Add the starting node to the set

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        // Traverse the adjacent nodes of the current node
        for (const string &neighbor : g[current]) {
            // If the neighbor has not been visited, add it to the set and the queue
            if (comp.find(neighbor) == comp.end()) {
                comp.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}
