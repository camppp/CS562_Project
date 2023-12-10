bool** mirrorTable(bool** table, size_t xSize, size_t ySize) {
    bool** toReturn = (bool**)malloc(xSize * sizeof(bool*)); // Allocate memory for the new array

    for (size_t i = 0; i < xSize; ++i) {
        toReturn[i] = (bool*)malloc(ySize * sizeof(bool)); // Allocate memory for each row of the new array
        for (size_t j = 0; j < ySize; ++j) {
            toReturn[i][j] = (table[i][j] || table[xSize - i - 1][j]); // Compute the logical OR
        }
    }

    return toReturn;
}
