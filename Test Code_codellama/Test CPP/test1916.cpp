#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

// Voxel class
class Voxel {
public:
    int x, y, z;
    bool isActive;

    Voxel(int x, int y, int z) : x(x), y(y), z(z), isActive(true) {}
};

// VoxelSet class
class VoxelSet {
public:
    set<Voxel> voxels;

    VoxelSet(const vector<Voxel>& voxels) : voxels(voxels) {}

    void thin() {
        // Implement 3D thinning algorithm here
    }
};

// Main function
int main() {
    // Initialize voxel set
    vector<Voxel> voxels = {
        {0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {3, 0, 0},
        {0, 1, 0}, {1, 1, 0}, {2, 1, 0}, {3, 1, 0},
        {0, 2, 0}, {1, 2, 0}, {2, 2, 0}, {3, 2, 0},
        {0, 3, 0}, {1, 3, 0}, {2, 3, 0}, {3, 3, 0},
        {0, 0, 1}, {1, 0, 1}, {2, 0, 1}, {3, 0, 1},
        {0, 1, 1}, {1, 1, 1}, {2, 1, 1}, {3, 1, 1},
        {0, 2, 1}, {1, 2, 1}, {2, 2, 1}, {3, 2, 1},
        {0, 3, 1}, {1, 3, 1}, {2, 3, 1}, {3, 3, 1},
        {0, 0, 2}, {1, 0, 2}, {2, 0, 2}, {3, 0, 2},
        {0, 1, 2}, {1, 1, 2}, {2, 1, 2}, {3, 1, 2},
        {0, 2, 2}, {1, 2, 2}, {2, 2, 2}, {3, 2, 2},
        {0, 3, 2}, {1, 3, 2}, {2, 3, 2}, {3, 3, 2},
        {0, 0, 3}, {1, 0, 3}, {2, 0, 3}, {3, 0, 3},
        {0, 1, 3}, {1, 1, 3}, {2, 1, 3}, {3, 1, 3},
        {0, 2, 3}, {1, 2, 3}, {2, 2, 3}, {3, 2, 3},
        {0, 3, 3}, {1, 3, 3}, {2, 3, 3}, {3, 3, 3}
    };
    VoxelSet voxelSet(voxels);

    // Thin voxel set
    voxelSet.thin();

    // Print resulting skeleton
    for (const Voxel& voxel : voxelSet.voxels) {
        if (voxel.isActive) {
            cout << "(" << voxel.x << ", " << voxel.y << ", " << voxel.z << ")" << endl;
        }
    }

    return 0;
}
