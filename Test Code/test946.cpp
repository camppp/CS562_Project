#include <iostream>

class UltrasonicData {
private:
    float distance;

public:
    void setDistance(float distance) {
        this->distance = distance;
    }

    float getDistance() {
        return distance;
    }

    void printGreeting() {
        std::cout << "Hello Hovergames from the Ultrasonic Sensor System (USS)!" << std::endl;
    }
};
