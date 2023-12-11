class GraphConverter:
    def __init__(self, data):
        self.data = data

    def get_graph(self):
        """ Retrieves the graph data from the class. """
        return self.data

    def fill_graph(self):
        """ Fills the graph data with the required format for ECharts. """
        graph_data = []
        for node, connections in self.data.items():
            for connection in connections:
                graph_data.append({"source": node, "target": connection})
        return graph_data

    def run(self):
        """ Executes the process of getting and filling the graph data and returns the transformed data. """
        graph_data = self.get_graph()
        transformed_data = self.fill_graph()
        return transformed_data