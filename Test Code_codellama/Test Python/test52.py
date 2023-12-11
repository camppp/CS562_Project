class Graph:
    def __init__(self, nodes: List[int], edges: List[Tuple[int, int]]):
        self.nodes = nodes
        self.edges = edges

    def flip_pairs(self, pairs: List[Tuple[int, int]]) -> List[Tuple[int, int]]:
        flipped_pairs = []
        for pair in pairs:
            node1, node2 = pair
            if (node1, node2) in self.edges:
                flipped_pairs.append((node2, node1))
            else:
                flipped_pairs.append(pair)
        return flipped_pairs