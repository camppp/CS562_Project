python
from typing import List
from collections import deque

def labelComponents(grid: List[List[int]]) -> List[List[int]]:
    def is_valid_move(x, y):
        return 0 <= x < len(grid) and 0 <= y < len(grid[0])

    def bfs(x, y, label):
        queue = deque([(x, y)])
        while queue:
            curr_x, curr_y = queue.popleft()
            grid[curr_x][curr_y] = label
            for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                new_x, new_y = curr_x + dx, curr_y + dy
                if is_valid_move(new_x, new_y) and grid[new_x][new_y] == 0:
                    queue.append((new_x, new_y))

    label = 1
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] != 0:
                bfs(i, j, label)
                label += 1
    return grid
