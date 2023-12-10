++
int calculateSectorSplits(double latitude) {
    const int topSectorSplitsByLatitude = splitsParameters._x; // Assume this value is provided

    // Calculate the total number of sectors based on the given latitude and topSectorSplitsByLatitude
    double normalizedLatitude = abs(latitude); // Normalize latitude to positive value
    double sectorSplits = (normalizedLatitude / 90) * topSectorSplitsByLatitude;

    return static_cast<int>(sectorSplits);
}
