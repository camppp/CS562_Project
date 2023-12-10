double CalculateVolume(int*** imageData, double spacing[3], int sizeX, int sizeY, int sizeZ) {
    double volume = 0.0;
    for (int z = 0; z < sizeZ; z++) {
        for (int y = 0; y < sizeY; y++) {
            for (int x = 0; x < sizeX; x++) {
                volume += spacing[0] * spacing[1] * spacing[2]; // Multiply the voxel volume by the spacing
            }
        }
    }
    return volume;
}
