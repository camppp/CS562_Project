java
import java.util.*;

public class DijkstraAlgorithm {
    public static void dijkstra(int source, List<List<int[]>> adj, int[] dist) {
        int n = adj.size();
        boolean[] visited = new boolean[n];
        int[][] q = new int[n][3]; // {node, parent, distance}
        int r = 1;
        q[0][0] = source;
        q[0][1] = -1;
        q[0][2] = 0;

        while (r > 0) {
            int l = 0;
            int u = q[l][0];
            int parent = q[l][1];
            int distance = q[l][2];
            visited[u] = true;
            r--;

            for (int[] edge : adj.get(u)) {
                int v = edge[0];
                int w = edge[1];
                if (!visited[v] && (dist[v] == -1 || dist[v] > distance + w)) {
                    dist[v] = distance + w;
                    q[r][0] = v;
                    q[r][1] = u;
                    q[r][2] = dist[v];
                    r++;
                }
            }
        }
    }

    public static void main(String[] args) {
        int n = 5; // Number of nodes
        List<List<int[]>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        // Adding edges to the graph
        adj.get(0).add(new int[]{1, 4});
        adj.get(0).add(new int[]{2, 1});
        adj.get(1).add(new int[]{2, 2});
        adj.get(1).add(new int[]{3, 5});
        adj.get(2).add(new int[]{3, 2});
        adj.get(2).add(new int[]{4, 1});
        adj.get(3).add(new int[]{4, 3});

        int source = 0; // Source node
        int[] dist = new int[n];
        Arrays.fill(dist, -1);
        dist[source] = 0;

        dijkstra(source, adj, dist);

        // Printing the shortest distances from the source node to all other nodes
        for (int i = 0; i < n; i++) {
            System.out.println("Shortest distance from node " + source + " to node " + i + " is " + dist[i]);
        }
    }
}
