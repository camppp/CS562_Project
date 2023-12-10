// Definition of GrafoP class representing a weighted graph
template <typename tCoste>
class GrafoP {
public:
    // Define necessary data structures and methods to represent a weighted graph
    // For example, you can use an adjacency matrix or adjacency list to store the graph structure
    // Include methods for adding edges, setting costs, and accessing vertices and edges
};

// Function to mark a vertex as mandatory for the Steiner tree
template <typename tCoste>
void setMandatory(GrafoP<tCoste>& g, vertice v) {
    // Implement the logic to mark the vertex v as mandatory for the Steiner tree
    // This may involve updating the graph structure to indicate that the vertex is mandatory
}

// Function to find the Steiner tree in the given graph
template <typename tCoste>
vector<vertice> steiner_r(GrafoP<tCoste> g, vertice v) {
    setMandatory(g, v); // Mark vertex v as mandatory
    // Implement the logic to find the Steiner tree using the modified graph
    // This may involve using algorithms such as Prim's algorithm or Dijkstra's algorithm to find the minimum spanning tree
    // Return the vertices of the Steiner tree as a vector
}
