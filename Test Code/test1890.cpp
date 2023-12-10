#include <vector>
#include <iostream>

class Vector2D {
public:
    float x, y;
    Vector2D(float x, float y) : x(x), y(y) {}
};

class Color {
public:
    float r, g, b;
    Color(float r, float g, float b) : r(r), g(g), b(b) {}
};

class Triangle {
public:
    Vector2D v1, v2, v3;
    Color color;
    Triangle(Vector2D v1, Vector2D v2, Vector2D v3, Color color) : v1(v1), v2(v2), v3(v3), color(color) {}
};

class BasicMaterialShader {
public:
    Color applyShading(const Triangle& triangle, const Vector2D& point) {
        // Apply basic material shading logic here
        // For simplicity, let's assume flat shading with a single color for the entire triangle
        return triangle.color;
    }
};

class Scene {
private:
    std::vector<Triangle> triangles;
public:
    void addTriangle(const Triangle& triangle) {
        triangles.push_back(triangle);
    }

    void render(const BasicMaterialShader& shader) {
        // Implement the rendering logic here using the provided BasicMaterialShader
        for (const auto& triangle : triangles) {
            // Render each triangle using the shader and output the rendered image
            Vector2D point(0.0f, 0.0f);  // Example point for shading
            Color shadedColor = shader.applyShading(triangle, point);
            std::cout << "Rendered triangle with color: (" << shadedColor.r << ", " << shadedColor.g << ", " << shadedColor.b << ")" << std::endl;
        }
    }
};

int main() {
    Scene scene;
    BasicMaterialShader shader;

    // Create and add triangles to the scene
    Triangle triangle1(Vector2D(0.0f, 0.0f), Vector2D(1.0f, 0.0f), Vector2D(0.5f, 1.0f), Color(1.0f, 0.0f, 0.0f));
    Triangle triangle2(Vector2D(1.0f, 0.0f), Vector2D(2.0f, 0.0f), Vector2D(1.5f, 1.0f), Color(0.0f, 1.0f, 0.0f));
    scene.addTriangle(triangle1);
    scene.addTriangle(triangle2);

    // Render the scene
    scene.render(shader);

    return 0;
}
