#include <iostream>
#include <fstream>
#include <vector>

void abi_gen_imf_deeptiledoutputpart(std::ostream& os) {
    // Generate a deep tiled output part with 3 levels of tiles
    std::vector<std::vector<std::vector<int>>> tiles(3);

    // Initialize the tiles with some sample data
    for (int i = 0; i < 3; i++) {
        tiles[i].resize(3);
        for (int j = 0; j < 3; j++) {
            tiles[i][j].resize(3);
            for (int k = 0; k < 3; k++) {
                tiles[i][j][k] = i * 100 + j * 10 + k;
            }
        }
    }

    // Write the tiles to the output stream
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                os << tiles[i][j][k] << " ";
            }
            os << "\n";
        }
        os << "\n";
    }
}
