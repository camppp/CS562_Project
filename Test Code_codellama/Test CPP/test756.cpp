int calculateColumnIndex(int relX, int keyXSize) {
    int col = relX - keyXSize / 2;
    if (col < 0) {
        col = 0;
    } else if (col > 8) {
        col = 8;
    }
    return col;
}
