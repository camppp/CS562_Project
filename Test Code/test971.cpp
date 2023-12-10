java
public int calculateSectorNumber(int globalPhi) {
    int globalSectorPhi = (globalPhi - 24); // Calculate the sector-specific angle
    int sectorWidth = 15; // Sector's angular width
    int sectorNumber = globalSectorPhi / sectorWidth; // Calculate the sector number
    return sectorNumber;
}
