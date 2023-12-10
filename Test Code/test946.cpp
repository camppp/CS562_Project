#include <iostream>

class UltrasonicData {
private:
    float distance;

public:
    void setDistance(float newDistance) {
        distance = newDistance;
    }

    float getDistance() {
        return distance;
    }

    void printGreeting() {
        std::cout << "Hello Hovergames from the Ultrasonic Sensor System (USS)!" << std::endl;
    }
};

/* main */
int dd_ultrasonic_main(int argc, char *argv[]) {
    PX4_INFO("Hello Hovergames from the Ultrasonic Sensor System (USS)!");

    UltrasonicData ultrasonicData;
    ultrasonicData.printGreeting();

    return 0;
}
