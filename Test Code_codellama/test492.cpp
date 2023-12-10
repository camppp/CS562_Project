#include <iostream>

class Robot {
private:
    long distX;
    long distY;

public:
    Robot() : distX(0), distY(0) {}

    void moveX(int x) {
        distX += x;
    }

    void moveY(int y) {
        distY += y;
    }

    long getX() {
        return distX;
    }

    long getY() {
        return distY;
    }
};

int main() {
    Robot robot;
    robot.moveX(5);
    robot.moveY(-3);
    std::cout << "Final X position: " << robot.getX() << std::endl;
    std::cout << "Final Y position: " << robot.getY() << std::endl;
    return 0;
}
