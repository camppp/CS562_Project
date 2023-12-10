void Prim::add_edge_priority_queue(int vertex1, int vertex2, int weight)
{
    priority_queue[vertex1].push_back({{vertex2, weight}});
    priority_queue[vertex2].push_back({{vertex1, weight}});
}

int Prim::mst_add_lowest_edge(Graph *g, Graph *mst)
{
    int min_weight = INT_MAX;
    int min_vertex1, min_vertex2;

    for (const auto &entry : priority_queue)
    {
        int vertex1 = entry.first;
        for (const auto &edge : entry.second)
        {
            int vertex2 = edge.begin()->first;
            int weight = edge.begin()->second;

            if (mst->contains_vertex(vertex1) && !mst->contains_vertex(vertex2))
            {
                if (weight < min_weight)
                {
                    min_weight = weight;
                    min_vertex1 = vertex1;
                    min_vertex2 = vertex2;
                }
            }
        }
    }

    mst->add_edge(min_vertex1, min_vertex2, min_weight);
    return min_weight;
}
