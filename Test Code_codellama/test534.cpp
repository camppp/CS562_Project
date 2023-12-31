#include <cmath>

namespace Sirikata {
namespace Graphics {

class Point2D {
public:
    // Constructor to initialize the point with given x and y coordinates
    Point2D(double x, double y) : x_(x), y_(y) {}

    // Set the x coordinate of the point
    void setX(double x) { x_ = x; }

    // Set the y coordinate of the point
    void setY(double y) { y_ = y; }

    // Get the x coordinate of the point
    double getX() const { return x_; }

    // Get the y coordinate of the point
    double getY() const { return y_; }

    // Calculate the distance between this point and another point
    double distanceTo(const Point2D& other) const {
        return std::sqrt(std::pow(x_ - other.x_, 2) + std::pow(y_ - other.y_, 2));
    }

private:
    double x_; // x coordinate of the point
    double y_; // y coordinate of the point
};

} // namespace Graphics
} // namespace Sirikata
