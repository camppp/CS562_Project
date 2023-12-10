#include <iostream>
#include <string>

class Robot {
public:
    Robot() : x(0), y(0) {}

    void move(const std::string& direction, int distance) {
        if (direction == "up") {
            y += distance;
        } else if (direction == "down") {
            y -= distance;
        } else if (direction == "left") {
            x -= distance;
        } else if (direction == "right") {
            x += distance;
        }
    }

    void process_request(const std::string& request_type) {
        std::cout << "Processing request: " << request_type << std::endl;
    }

private:
    int x;
    int y;
};

int main() {
    Robot robot;

    robot.move("up", 3);
    robot.move("left", 2);
    robot.move("right", 3);
    robot.move("down", 4);

    robot.process_request("pickup");
    robot.process_request("dropoff");
    robot.process_request("scan");

    return 0;
}
