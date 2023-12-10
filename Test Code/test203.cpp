position_value_t findMaxValueInRange(cell_t grid[MAX_ROWS][MAX_COLS], 
                                      int startRow, 
                                      int startCol, 
                                      int endRow, 
                                      int endCol, 
                                      cell_t rhsCell, 
                                      position_value_t maximumValue) {
    for (int i = startRow; i <= endRow; i++) {
        for (int j = startCol; j <= endCol; j++) {
            if (grid[i][j].value > rhsCell.value && grid[i][j].value > maximumValue) {
                maximumValue = grid[i][j].value;
            }
        }
    }
    return maximumValue;
}
