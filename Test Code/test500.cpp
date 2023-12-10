double CalculateVolume(int*** imageData, double spacing[3], int sizeX, int sizeY, int sizeZ) {
    double volume = 0;
    for (int x = 0; x < sizeX; x++) {
        for (int y = 0; y < sizeY; y++) {
            for (int z = 0; z < sizeZ; z++) {
                volume += imageData[x][y][z] * spacing[0] * spacing[1] * spacing[2];
            }
        }
    }
    return volume;
}
