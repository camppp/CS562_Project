#include <iostream>
#include <cmath>

class Point {
private:
    int x, y;

public:
    Point(int x, int y) : x(x), y(y) {}

    double distanceTo(Point other) {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }

    double distanceToOrigin() {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    void move(int offsetX, int offsetY) {
        x += offsetX;
        y += offsetY;
    }
};

int main() {
    Point p(3, 4);
    std::cout << "Distance to origin: " << p.distanceToOrigin() << std::endl;

    Point q(6, 8);
    std::cout << "Distance between p and q: " << p.distanceTo(q) << std::endl;

    p.move(1, 1);
    std::cout << "New coordinates of p: (" << p.x << ", " << p.y << ")" << std::endl;

    return 0;
}
