public int[] bfs(int[][] e, int s) {
    int n = e.length;
    int[] dist = new int[n];
    Arrays.fill(dist, -1);
    dist[s] = 0;
    Queue<Integer> Q = new LinkedList<>();
    Q.add(s);
    while (!Q.isEmpty()) {
        int u = Q.poll();
        for (int i = 0; i < e[u].length; i++) {
            int v = e[u][i];
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                Q.add(v);
            }
        }
    }
    return dist;
}
