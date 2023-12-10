int maxAbsDifference(int arrC[], int x, int y) {
    int maxDiff = 0;
    int xCount = 0;
    int yCount = 0;

    for (int i = 0; i < arrC.size(); i++) {
        if (arrC[i] == x) {
            xCount++;
        } else if (arrC[i] == y) {
            yCount++;
        }
    }

    maxDiff = max(abs(xCount - yCount), maxDiff);

    return maxDiff;
}
