#include <iostream>

int main() {
    // Create a sample TriangleMesh with vertex colors
    TriangleMesh mesh;
    mesh.get_vertex_colors().push_back({255, 0, 0});  // Red
    mesh.get_vertex_colors().push_back({0, 255, 0});  // Green
    mesh.get_vertex_colors().push_back({0, 0, 255});  // Blue

    // Calculate the average color
    TriangleMesh::Color averageColor = ColorCalculator::calculate_average_color(mesh);

    // Output the average color
    std::cout << "Average Color: (" << averageColor[0] << ", " << averageColor[1] << ", " << averageColor[2] << ")" << std::endl;

    return 0;
}
