int calculateSectorNumber(int globalPhi) {
    int globalSectorPhi = globalPhi - 24;
    int sectorNumber = globalSectorPhi / 15;
    return sectorNumber;
}
