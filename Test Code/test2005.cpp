java
public int[] bfs(int[][] e, int s) {
    int n = e.length;
    int[] dist = new int[n];
    boolean[] visited = new boolean[n];
    int[] Q = new int[n];
    int frontI = 0, backI = 0;

    Q[backI++] = s;
    visited[s] = true;

    while (frontI < backI) {
        int v = Q[frontI++];
        for (int i = 1; i <= e[v][0]; i++) {
            int neighbor = e[v][i];
            if (!visited[neighbor]) {
                dist[neighbor] = dist[v] + 1;
                Q[backI++] = neighbor;
                visited[neighbor] = true;
            }
        }
    }

    return dist;
}
