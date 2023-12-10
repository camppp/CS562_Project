int calculateTerrainArea(std::vector<std::vector<int>>& terrain) {
    int totalArea = 0;
    for (int i = 0; i < terrain.size(); i++) {
        for (int j = 0; j < terrain[i].size(); j++) {
            totalArea += terrain[i][j] * terrain[i][j];
        }
    }
    return totalArea;
}
