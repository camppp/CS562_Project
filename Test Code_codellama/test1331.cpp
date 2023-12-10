void addEdge(std::vector<std::vector<int>>& ad, int u, int v) {
    u--; v--; // subtract 1 from u and v to get the correct index
    ad[u].push_back(v); // add v to the list of nodes connected to u
    ad[v].push_back(u); // add u to the list of nodes connected to v
}
