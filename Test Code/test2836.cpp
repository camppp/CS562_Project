#include <iostream>

class Line {
public:
    struct Point {
        int x;
        int y;
    };

    Point vStart;
    Point vEnd;

    Line(int startX, int startY, int endX, int endY) : vStart{startX, startY}, vEnd{endX, endY} {}

    Line& operator=(const Line& other) {
        vStart = other.vStart;
        vEnd = other.vEnd;
        return *this;
    }
};

int main() {
    Line line1(1, 2, 3, 4);
    Line line2 = line1;  // This should invoke the copy operator

    // Output the start and end points of line2 to verify the copy
    std::cout << "Start: (" << line2.vStart.x << ", " << line2.vStart.y << ")" << std::endl;
    std::cout << "End: (" << line2.vEnd.x << ", " << line2.vEnd.y << ")" << std::endl;

    return 0;
}
