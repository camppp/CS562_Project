position_value_t findMaxValueInRange(cell_t grid[MAX_ROWS][MAX_COLS], 
                                      int startRow, 
                                      int startCol, 
                                      int endRow, 
                                      int endCol, 
                                      cell_t rhsCell, 
                                      position_value_t maximumValue) {
    for (int row = startRow; row <= endRow; row++) {
        for (int col = startCol; col <= endCol; col++) {
            cell_t currentCell = grid[row][col];
            if (currentCell > rhsCell) {
                maximumValue = currentCell;
            }
        }
    }
    return maximumValue;
}
