python
from typing import List, Tuple

def unique_colors_in_graph(edges: List[Tuple[int, int, int, str]]) -> List[str]:
    unique_colors = set()
    for edge in edges:
        unique_colors.add(edge[3])
    return list(unique_colors)
