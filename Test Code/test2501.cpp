#include <iostream>
#include <vector>

void printGrid(const std::vector<std::vector<int>>& grid, int H, int W) {
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            std::cout << (grid[y][x] == 1 ? '#' : '.') << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> b = {{1, 0, 1, 0},
                                       {0, 1, 0, 1},
                                       {1, 1, 0, 0}};
    int H = 3, W = 4;
    printGrid(b, H, W);
    return 0;
}
