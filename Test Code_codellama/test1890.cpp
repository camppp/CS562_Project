void Scene::render(const BasicMaterialShader& shader) {
    for (const auto& triangle : triangles) {
        // Calculate the shaded color for the triangle
        Vector2D point(0.0f, 0.0f);  // Example point for shading
        Color shadedColor = shader.applyShading(triangle, point);

        // Output the rendered image
        std::cout << "Rendered triangle with color: (" << shadedColor.r << ", " << shadedColor.g << ", " << shadedColor.b << ")" << std::endl;
    }
}
