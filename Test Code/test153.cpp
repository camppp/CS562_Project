python
from typing import List, Tuple

def count_zero_rows_cols(grid: List[List[int]]) -> Tuple[int, int]:
    rows = [0] * len(grid)
    cols = [0] * len(grid[0])

    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 0:
                rows[i] = 1
                cols[j] = 1

    zero_rows = rows.count(0)
    zero_cols = cols.count(0)

    return zero_rows, zero_cols
