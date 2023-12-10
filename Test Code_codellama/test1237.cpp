bool** mirrorTable(bool** table, size_t xSize, size_t ySize) {
    bool** toReturn = new bool*[xSize];
    for (size_t i = 0; i < xSize; i++) {
        toReturn[i] = new bool[ySize];
        for (size_t j = 0; j < ySize; j++) {
            toReturn[i][j] = table[i][j] || table[xSize - i - 1][j];
        }
    }
    return toReturn;
}
