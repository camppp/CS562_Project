#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Define the type of cost for the graph
using tCoste = int;

// Define the class for the weighted graph
class GrafoP {
public:
    // Constructor
    GrafoP(int numVertices) {
        numVertices_ = numVertices;
        vertices_.resize(numVertices);
        costs_.resize(numVertices);
    }

    // Add an edge to the graph
    void addEdge(int v1, int v2, tCoste cost) {
        vertices_[v1].push_back(v2);
        vertices_[v2].push_back(v1);
        costs_[v1].push_back(cost);
        costs_[v2].push_back(cost);
    }

    // Set the cost of a vertex
    void setCost(int v, tCoste cost) {
        costs_[v] = cost;
    }

    // Get the cost of a vertex
    tCoste getCost(int v) {
        return costs_[v];
    }

    // Get the number of vertices in the graph
    int getNumVertices() {
        return numVertices_;
    }

    // Get the number of edges in the graph
    int getNumEdges() {
        return vertices_.size();
    }

    // Get the vertices of the graph
    vector<int> getVertices() {
        return vertices_;
    }

    // Get the edges of the graph
    vector<int> getEdges() {
        return edges_;
    }

private:
    // Number of vertices in the graph
    int numVertices_;

    // Vector of vertices
    vector<int> vertices_;

    // Vector of edges
    vector<int> edges_;

    // Vector of costs
    vector<tCoste> costs_;
};

// Define the function to mark a vertex as mandatory for the Steiner tree
void setMandatory(GrafoP& graph, int v) {
    // Mark the vertex as mandatory
    graph.setCost(v, 0);
}

int main() {
    // Create a graph with 5 vertices
    GrafoP graph(5);

    // Add edges to the graph
    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 4);
    graph.addEdge(2, 3, 5);
    graph.addEdge(3, 4, 6);

    // Set the cost of vertex 0 as mandatory
    setMandatory(graph, 0);

    // Find the Steiner tree in the graph
    vector<int> steinerTree = findSteinerTree(graph);

    // Print the Steiner tree
    for (int v : steinerTree) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
