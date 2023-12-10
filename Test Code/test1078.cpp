#include "collider.h"

// Define the Shape structure
struct Shape {
    int type;
    // ...
};

// Define the Circle structure
struct Circle {
    int x;
    int y;
    int radius;
};

// Define the Rectangle structure
struct Rectangle {
    int x;
    int y;
    int width;
    int height;
};

// Define the Collider class
class Collider {
public:
    // Static method to detect collisions between two shapes
    static bool isColliding(const Shape& shape1, const Shape& shape2) {
        // Check the type of the shapes
        if (shape1.type == Circle && shape2.type == Circle) {
            return isCircleColliding(shape1, shape2);
        } else if (shape1.type == Rectangle && shape2.type == Rectangle) {
            return isRectangleColliding(shape1, shape2);
        } else {
            return false;
        }
    }

    // Static method to detect collisions between two circles
    static bool isCircleColliding(const Circle& circle1, const Circle& circle2) {
        // Calculate the distance between the centers of the circles
        int dx = circle1.x - circle2.x;
        int dy = circle1.y - circle2.y;
        int distance = sqrt(dx * dx + dy * dy);

        // Check if the distance is less than the sum of the radii
        return distance < circle1.radius + circle2.radius;
    }

    // Static method to detect collisions between two rectangles
    static bool isRectangleColliding(const Rectangle& rect1, const Rectangle& rect2) {
        // Check if the rectangles are overlapping in the x-axis
        if (rect1.x < rect2.x + rect2.width && rect2.x < rect1.x + rect1.width) {
            // Check if the rectangles are overlapping in the y-axis
            if (rect1.y < rect2.y + rect2.height && rect2.y < rect1.y + rect1.height) {
                return true;
            }
        }
        return false;
    }
};
