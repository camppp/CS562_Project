#include <map>
#include <vector>

class Graph
{
    // Define the Graph class as needed
};

class Prim
{
private:
    std::map<int, std::vector<std::map<int, int>>> priority_queue;

    void add_edge_priority_queue(int vertex1, int vertex2, int weight)
    {
        // Add the edge to the priority queue
        priority_queue[vertex1].push_back({vertex2, weight});
    }

    int mst_add_lowest_edge(Graph *g, Graph *mst)
    {
        // Find the lowest-weight edge in the priority queue
        int lowest_weight = INT_MAX;
        int lowest_edge = -1;
        for (auto& edge : priority_queue)
        {
            if (edge.second[0]["weight"] < lowest_weight)
            {
                lowest_weight = edge.second[0]["weight"];
                lowest_edge = edge.first;
            }
        }

        // Add the lowest-weight edge to the MST
        mst->add_edge(lowest_edge, priority_queue[lowest_edge][0]["vertex2"]);

        // Return the weight of the added edge
        return lowest_weight;
    }

public:
    // Other methods and members of the Prim class
};
