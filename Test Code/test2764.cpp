#include <ros/ros.h>
#include <vector>

class ObjectPublisher {
public:
    ObjectPublisher() {
        bbox_pub_ = nh_.advertise<BoundingBox>("bbox_pub", 10);
        class_pub_ = nh_.advertise<ClassLabel>("class_pub", 10);
        confidence_pub_ = nh_.advertise<Confidence>("confidence_pub", 10);
        marker_lifetime_ = 5.0;  // Default marker lifetime
        rgba_ = {1.0, 0.0, 0.0, 1.0};  // Default RGBA color (red)
    }

    void publishBoundingBoxes(const std::vector<BoundingBox>& boxes) {
        bbox_pub_.publish(boxes);
    }

    void publishClassLabels(const std::vector<ClassLabel>& labels) {
        class_pub_.publish(labels);
    }

    void publishConfidences(const std::vector<Confidence>& confidences) {
        confidence_pub_.publish(confidences);
    }

    void setMarkerLifetime(double lifetime) {
        marker_lifetime_ = lifetime;
    }

    void setRGBAColor(const std::vector<double>& rgba) {
        if (rgba.size() == 4) {
            rgba_ = rgba;
        } else {
            ROS_WARN("Invalid RGBA color format. RGBA color should have 4 components.");
        }
    }

private:
    ros::NodeHandle nh_;
    ros::Publisher bbox_pub_;
    ros::Publisher class_pub_;
    ros::Publisher confidence_pub_;
    double marker_lifetime_;
    std::vector<double> rgba_;
};

// Example usage
int main(int argc, char** argv) {
    ros::init(argc, argv, "object_publisher_node");
    ObjectPublisher obj_pub;

    // Publish example data
    std::vector<BoundingBox> boxes = { /* Populate with bounding boxes */ };
    std::vector<ClassLabel> labels = { /* Populate with class labels */ };
    std::vector<Confidence> confidences = { /* Populate with confidence values */ };

    obj_pub.publishBoundingBoxes(boxes);
    obj_pub.publishClassLabels(labels);
    obj_pub.publishConfidences(confidences);

    obj_pub.setMarkerLifetime(7.0);
    obj_pub.setRGBAColor({0.0, 1.0, 0.0, 1.0});  // Set color to green

    ros::spin();
    return 0;
}
