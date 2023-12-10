#include <iostream>
#include <vector>

// Define the orcamap function to map 2D coordinates to 3D indices
std::vector<int> orcamap(int eta, int phi) {
    std::vector<int> indices(3);
    indices[0] = phi / 8;  // Calculate the first index
    indices[1] = eta / 8;  // Calculate the second index
    indices[2] = phi % 8 * 8 + eta % 8;  // Calculate the third index
    return indices;
}

int main() {
    // Assuming combEM and combHD are defined and initialized elsewhere
    std::vector<int> combEM(72 * 56);  // Assuming the size of combEM is 72 * 56
    std::vector<int> combHD(72 * 56);  // Assuming the size of combHD is 72 * 56

    // Assuming barrelData is a 3D vector initialized elsewhere
    std::vector<std::vector<std::vector<int>>> barrelData(9, std::vector<std::vector<int>>(7, std::vector<int>(64)));

    for (int phi = 0; phi < 72; phi++) {
        for (int eta = 0; eta < 56; eta++) {
            std::vector<int> indices = orcamap(eta, phi);
            barrelData[indices[0]][indices[1]][indices[2]] = combEM[phi * 56 + eta];
            barrelData[indices[0]][indices[1]][indices[2] + 32] = combHD[phi * 56 + eta];
        }
    }

    // Output or further processing of populated barrelData
    return 0;
}
