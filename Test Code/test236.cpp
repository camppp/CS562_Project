#include <iostream>
#include <vector>
#include <algorithm>

struct Vec3 {
    float x, y, z;
};

struct Vertex {
    Vec3 first;  // 3D position
    Vec3 second; // Projected 2D position
};

std::vector<Vertex> mVertices(8);  // Array of vertices

// Function to project all vertices onto a 2D plane
void projectAllVertices(int numVertices) {
    // Implementation not provided
}

// Function to calculate the absolute difference between the maximum and minimum z-coordinates
float calculateZDifference(float ulz0, float urz0, float llz0) {
    float maxZ = std::max({ulz0, urz0, llz0});
    float minZ = std::min({ulz0, urz0, llz0});
    return std::abs(maxZ - minZ);
}

int main() {
    // Given code snippet
    mVertices[2].first = (center + Vec3{-one, one, -one});
    mVertices[3].first = (center + Vec3{one, one, -one});
    mVertices[4].first = (center + Vec3{-one, -one, one});
    mVertices[5].first = (center + Vec3{one, -one, one});
    mVertices[6].first = (center + Vec3{-one, one, one});
    mVertices[7].first = (center + Vec3{one, one, one});

    projectAllVertices(8);

    const auto ulz0 = mVertices[0].second;
    const auto urz0 = mVertices[1].second;
    const auto llz0 = mVertices[2].second;

    // Calculate the absolute difference between the maximum and minimum z-coordinates
    float zDifference = calculateZDifference(ulz0.z, urz0.z, llz0.z);
    std::cout << "Absolute difference between max and min z-coordinates: " << zDifference << std::endl;

    return 0;
}
