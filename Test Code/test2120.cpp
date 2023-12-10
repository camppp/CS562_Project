#include <cstdint>
#include <cmath>

struct Particle {
    bool mature;
    // Other particle attributes
};

size_t xy2pos(uint16_t x, uint16_t y) {
    // Implementation of xy2pos function
    // This function returns the position of the particle in the grid based on its coordinates
    // Implementation not provided as it's outside the scope of this problem
}

void updateParticlePositionAndMaturity(Particle* p, int px, int py, int width, int height) {
    uint16_t x = std::min(int(px), width - 1);
    uint16_t y = std::min(int(py), height - 1);
    size_t pos = xy2pos(x, y);

    if (!p->mature) {
        p->mature = true;
    }

    // Other calculations or operations based on x, y, pos, px, py, and p
    // Implementation not provided as it's outside the scope of this problem
}
