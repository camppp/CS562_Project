int calculateTotalArea(const vector<vector<int>>& terrainMap) {
    int totalArea = 0;
    for (int i = 0; i < terrainMap.size(); i++) {
        for (int j = 0; j < terrainMap[i].size(); j++) {
            totalArea += terrainMap[i][j] * 1;
        }
    }
    return totalArea;
}
