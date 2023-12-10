#include <iostream>

// Structure for robot's pose
struct Pose {
    double x;
    double y;
    double theta;
};

// Function to retrieve and print laser scan data or robot's pose
void retrieveAndPrintData(char action, Robot& robot) {
    int error;
    LaserData laser_data;
    Pose pose;

    switch (action) {
        case 'l':
            error = neato_laser_scan_get(robot, &laser_data);
            if (!error) {
                dump_laser(laser_data);
            } else {
                std::cout << "Error retrieving data" << std::endl;
            }
            break;
        case 'p':
            error = neato_pose_get(robot, &pose);
            if (!error) {
                std::cout << "X : " << pose.x << " Y : " << pose.y << " Theta : " << pose.theta << std::endl;
            } else {
                std::cout << "Error retrieving data" << std::endl;
            }
            break;
        default:
            std::cout << "Invalid action" << std::endl;
    }
}
