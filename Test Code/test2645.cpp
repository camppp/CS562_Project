#include <iostream>
#include <vector>
#include <stdexcept>
#include <random>

enum TerrainType { GRASS, WATER, MOUNTAIN, DESERT }; // Example terrain types

void map_gen(int width, int height, float density, int seed, int num_terrain_types) {
    if (width == 0 || height == 0) {
        throw std::invalid_argument("Map dimensions cannot be zero.");
    }
    if (density <= 0 || density > 1.0) {
        throw std::invalid_argument("Density must be in the range (0.0, 1.0].");
    }

    std::mt19937 gen(seed); // Mersenne Twister random number generator
    std::uniform_real_distribution<float> dis(0.0, 1.0);

    std::vector<std::vector<TerrainType>> map(height, std::vector<TerrainType>(width, GRASS));

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            float rand_val = dis(gen);
            if (rand_val < density) {
                int terrain_type = rand() % num_terrain_types;
                map[y][x] = static_cast<TerrainType>(terrain_type);
            }
        }
    }

    // Further map generation logic based on terrain types and density
    // ...

    // Output the generated map
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::cout << map[y][x] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char **argv) {
    try {
        map_gen(30, 20, 1.0, 0, 4); // Example usage with error conditions
    } catch (const std::invalid_argument &e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    return 0;
}
