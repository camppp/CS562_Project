#include "collider.h"
#include <cmath>

class Collider {
public:
    static bool isColliding(const Shape& shape1, const Shape& shape2) {
        if (shape1.type == "circle" && shape2.type == "circle") {
            return isCircleColliding(static_cast<const Circle&>(shape1), static_cast<const Circle&>(shape2));
        } else if (shape1.type == "rectangle" && shape2.type == "rectangle") {
            return isRectangleColliding(static_cast<const Rectangle&>(shape1), static_cast<const Rectangle&>(shape2));
        } else {
            // Handle collision between different shape types
            return false;
        }
    }

    static bool isCircleColliding(const Circle& circle1, const Circle& circle2) {
        // Calculate the distance between the centers of the circles
        float distance = std::sqrt(std::pow(circle2.x - circle1.x, 2) + std::pow(circle2.y - circle1.y, 2));
        // Check if the distance is less than the sum of the radii
        return distance < (circle1.radius + circle2.radius);
    }

    static bool isRectangleColliding(const Rectangle& rect1, const Rectangle& rect2) {
        // Check for overlap in the x-axis
        bool overlapX = (rect1.x + rect1.width >= rect2.x) && (rect2.x + rect2.width >= rect1.x);
        // Check for overlap in the y-axis
        bool overlapY = (rect1.y + rect1.height >= rect2.y) && (rect2.y + rect2.height >= rect1.y);
        // If there is overlap in both axes, the rectangles are colliding
        return overlapX && overlapY;
    }
};
