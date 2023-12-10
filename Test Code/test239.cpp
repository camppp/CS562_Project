#include <iostream>
#include <vector>

// Define a simple 2D vector class
class Vector2D {
public:
    float x, y;
    Vector2D(float x, float y) : x(x), y(y) {}
};

// Define a simple color class
class Color {
public:
    int r, g, b;
    Color(int r, int g, int b) : r(r), g(g), b(b) {}
};

// Define an abstract base class for animators
class Animator {
public:
    virtual void update() = 0;
};

// Define a position animator class
class PositionAnimator : public Animator {
private:
    Vector2D currentPosition;
public:
    PositionAnimator(float initialX, float initialY) : currentPosition(initialX, initialY) {}

    void update() {
        // Update position logic goes here
        // For example, you can simulate movement by incrementing x and y
        currentPosition.x += 1.0f;
        currentPosition.y += 0.5f;
    }

    Vector2D getCurrentPosition() {
        return currentPosition;
    }
};

// Define a color animator class
class ColorAnimator : public Animator {
private:
    Color currentColor;
public:
    ColorAnimator(int initialR, int initialG, int initialB) : currentColor(initialR, initialG, initialB) {}

    void update() {
        // Update color logic goes here
        // For example, you can simulate color change by cycling through RGB values
        currentColor.r = (currentColor.r + 1) % 256;
        currentColor.g = (currentColor.g + 2) % 256;
        currentColor.b = (currentColor.b + 3) % 256;
    }

    Color getColorCurrent() {
        return currentColor;
    }
};

int main() {
    // Create position animator with initial values
    PositionAnimator posAnim(100.0f, 100.0f);

    // Create color animator with initial values
    ColorAnimator colorAnim(255, 0, 0);

    // Update animators over time
    for (int i = 0; i < 10; i++) {
        posAnim.update();
        colorAnim.update();

        // Retrieve current position and color values
        Vector2D currentPosition = posAnim.getCurrentPosition();
        Color currentColor = colorAnim.getColorCurrent();

        // Draw a filled circle at the current position with the current color
        std::cout << "Drawing circle at (" << currentPosition.x << ", " << currentPosition.y << ") with color (" << currentColor.r << ", " << currentColor.g << ", " << currentColor.b << ")" << std::endl;
    }

    return 0;
}
