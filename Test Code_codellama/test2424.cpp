void bfs(map<string, vector<string> > &g, string c, set<string> &comp) {
	queue<string> q;
	q.push(c);
	comp.insert(c);
	while (!q.empty()) {
		string node = q.front();
		q.pop();
		for (string neighbor : g[node]) {
			if (comp.find(neighbor) == comp.end()) {
				q.push(neighbor);
				comp.insert(neighbor);
			}
		}
	}
}
