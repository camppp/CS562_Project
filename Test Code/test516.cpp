#include <ros/console.h>
#include <lcm/lcm-cpp.hpp>
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Debug);
  ROS_DEBUG_STREAM("start new lcm to ros node...");

  lcm::LCM lcm;
  if (!lcm.good()) {
    ROS_ERROR_STREAM("LCM init failed.");
    return -1;
  }

  // Initialize ROS node
  ros::init(argc, argv, "lcm_to_ros_node");
  ros::NodeHandle nh;

  // Add your ROS node initialization and further processing here

  return 0;
}
