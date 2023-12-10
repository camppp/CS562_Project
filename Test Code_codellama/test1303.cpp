c++
int calculateSectorSplits(double latitude) {
    // Calculate the number of sectors based on the given latitude
    int sectors = topSectorSplitsByLatitude;
    if (latitude < 0) {
        sectors = sectors / 2;
    }
    return sectors;
}
