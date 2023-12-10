#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void map_gen(int width, int height, float density, int seed, int num_terrain_types) {
    // Check for invalid input
    if (width <= 0 || height <= 0) {
        throw invalid_argument("Invalid map dimensions");
    }
    if (density <= 0.0 || density > 1.0) {
        throw invalid_argument("Invalid density value");
    }

    // Initialize random number generator
    srand(seed);

    // Generate map grid
    int** grid = new int*[width];
    for (int i = 0; i < width; i++) {
        grid[i] = new int[height];
        for (int j = 0; j < height; j++) {
            grid[i][j] = 0;
        }
    }

    // Generate terrain
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // Randomly generate terrain type
            int terrain_type = rand() % num_terrain_types;
            grid[i][j] = terrain_type;
        }
    }

    // Print map grid
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < width; i++) {
        delete[] grid[i];
    }
    delete[] grid;
}

int main() {
    int width = 10;
    int height = 10;
    float density = 0.5;
    int seed = 1234;
    int num_terrain_types = 3;

    try {
        map_gen(width, height, density, seed, num_terrain_types);
    } catch (invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
