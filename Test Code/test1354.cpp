#include <vector>

int calculateTerrainArea(std::vector<std::vector<int>>& terrain) {
    int totalArea = 0;
    for (size_t i = 0; i < terrain.size(); ++i) {
        for (size_t j = 0; j < terrain[i].size(); ++j) {
            totalArea += terrain[i][j] * 1; // Assuming the area of a single cell is 1
        }
    }
    return totalArea;
}
