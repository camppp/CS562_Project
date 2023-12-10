#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>

class ObjectPublisher {
 public:
  ObjectPublisher();
  ~ObjectPublisher();

  void publishBoundingBoxes(const std::vector<geometry_msgs::PoseStamped>& bboxes);
  void publishClassLabels(const std::vector<std_msgs::String>& class_labels);
  void publishConfidences(const std::vector<std_msgs::Float32>& confidences);

  void setMarkerLifetime(double marker_lifetime);
  void setRGBAColor(const std::vector<double>& rgba);

 private:
  ros::Publisher bbox_pub_;
  ros::Publisher class_pub_;
  ros::Publisher confidence_pub_;

  double marker_lifetime_;
  std::vector<double> rgba_;
};

ObjectPublisher::ObjectPublisher() {
  // Initialize ROS publishers
  bbox_pub_ = nh.advertise<geometry_msgs::PoseStamped>("bbox_pub", 10);
  class_pub_ = nh.advertise<std_msgs::String>("class_pub", 10);
  confidence_pub_ = nh.advertise<std_msgs::Float32>("confidence_pub", 10);

  // Set default values for marker lifetime and RGBA color
  marker_lifetime_ = 0.5;
  rgba_ = {0.0, 0.0, 0.0, 1.0};
}

ObjectPublisher::~ObjectPublisher() {
  // Clean up ROS publishers
  bbox_pub_.shutdown();
  class_pub_.shutdown();
  confidence_pub_.shutdown();
}

void ObjectPublisher::publishBoundingBoxes(const std::vector<geometry_msgs::PoseStamped>& bboxes) {
  for (const auto& bbox : bboxes) {
    geometry_msgs::PoseStamped msg;
    msg.header.stamp = ros::Time::now();
    msg.header.frame_id = "map";
    msg.pose.position.x = bbox.x;
    msg.pose.position.y = bbox.y;
    msg.pose.position.z = bbox.z;
    msg.pose.orientation.x = bbox.qx;
    msg.pose.orientation.y = bbox.qy;
    msg.pose.orientation.z = bbox.qz;
    msg.pose.orientation.w = bbox.qw;
    bbox_pub_.publish(msg);
  }
}

void ObjectPublisher::publishClassLabels(const std::vector<std_msgs::String>& class_labels) {
  for (const auto& label : class_labels) {
    std_msgs::String msg;
    msg.data = label;
    class_pub_.publish(msg);
  }
}

void ObjectPublisher::publishConfidences(const std::vector<std_msgs::Float32>& confidences) {
  for (const auto& confidence : confidences) {
    std_msgs::Float32 msg;
    msg.data = confidence;
    confidence_pub_.publish(msg);
  }
}

void ObjectPublisher::setMarkerLifetime(double marker_lifetime) {
  marker_lifetime_ = marker_lifetime;
}

void ObjectPublisher::setRGBAColor(const std::vector<double>& rgba) {
  rgba_ = rgba;
}
