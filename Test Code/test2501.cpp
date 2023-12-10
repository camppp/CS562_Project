#include <iostream>

void printGrid(int grid[][W], int H, int W) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 1) {
                std::cout << "# ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int grid[3][4] = {
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 1, 0, 0}
    };
    printGrid(grid, 3, 4);
    return 0;
}
