python
from typing import List
from collections import deque

def shortest_path_length(graph: List[List[int]], source: int) -> List[int]:
    n = len(graph)
    distances = [float('inf')] * n
    distances[source] = 0
    queue = deque([source])

    while queue:
        node = queue.popleft()
        for neighbor in graph[node]:
            if distances[neighbor] == float('inf'):
                distances[neighbor] = distances[node] + 1
                queue.append(neighbor)

    return distances
