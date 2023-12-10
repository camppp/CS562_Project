#include <lcm/lcm.h>
#include <ros/ros.h>

int main(int argc, char** argv) {
    // Initialize the LCM system
    lcm_t* lcm = lcm_create(NULL);
    if (!lcm) {
        ROS_ERROR("Failed to initialize LCM");
        return -1;
    }

    // Initialize the ROS system
    ros::init(argc, argv, "lcm_to_ros_node");
    ros::NodeHandle nh;

    // Set the logger level for ROS to Debug
    ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Debug);

    // Print a debug message indicating the start of the LCM to ROS node
    ROS_DEBUG("Starting LCM to ROS node");

    // Handle potential errors during initialization
    if (!ros::ok()) {
        ROS_ERROR("Failed to initialize ROS");
        return -1;
    }

    // Initialize the LCM to ROS bridge
    lcm_to_ros::LCMToROS lcm_to_ros(lcm, nh);

    // Run the LCM to ROS bridge
    lcm_to_ros.run();

    return 0;
}
