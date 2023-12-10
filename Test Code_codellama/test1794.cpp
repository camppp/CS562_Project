TriangleMesh::Color ColorCalculator::calculate_average_color(const TriangleMesh& mesh) {
    const TriangleMesh::ColorList& colors = mesh.get_vertex_colors();
    int totalRed = 0, totalGreen = 0, totalBlue = 0;

    for (const auto& color : colors) {
        totalRed += color[0];
        totalGreen += color[1];
        totalBlue += color[2];
    }

    int numColors = colors.size();
    return {totalRed / numColors, totalGreen / numColors, totalBlue / numColors};
}
