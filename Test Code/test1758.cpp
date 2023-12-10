python
def find_missing_numbers_positions(grid):
    missing_positions = []
    rows = grid.strip().split('\n')
    for i, row in enumerate(rows):
        numbers = row.split(',')
        for j, num in enumerate(numbers):
            if num.strip() == '-1':
                missing_positions.append((i, j))
    return missing_positions

# Example usage
grid = """
      13, 15, 12, 29, 49, -1, 51, 33, 50,
      14, 30, -1, 50, 52, 49, 15, 34, 53,
      14, 16, -1, 31, 51, 17, 53, 35, 52,
      15, 32, 16, 52, 54, 51, 17, 36, 55,
      16, 18, 15, 33, 53, -1, 55, 37, 54,
      17, 34, -1, 54, 56, 53, 18, 38, 57,
"""
print(find_missing_numbers_positions(grid))
# Output: [(0, 5), (1, 2), (4, 5), (5, 2)]
