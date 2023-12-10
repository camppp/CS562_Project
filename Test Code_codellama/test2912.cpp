#include <ros/ros.h>
#include <sensor_msgs/Range.h>

class RosSonarPlugin {
public:
    // Constructor, member variables, and other methods are not shown for brevity.

    void onUpdated(){
        //copy data into ros message

        sonar_msg_.header.frame_id = "drone_link";
        sonar_msg_.header.stamp.sec = this->sonar_->LastUpdateTime().sec;
        sonar_msg_.header.stamp.nsec = this->sonar_->LastUpdateTime().nsec;

        sonar_msg_.range = this->sonar_->Range();
        sonar_msg_.max_range = this->sonar_->RangeMax();
        sonar_msg_.min_range = this->sonar_->RangeMin();

        // Publish sonar_msg_ to ROS network
        publishSonarData();
    }

private:
    // Other member variables and methods are not shown for brevity.

    void publishSonarData(){
        // Create a ROS publisher for sonar data
        ros::Publisher pub = nh_.advertise<sensor_msgs::Range>("sonar_data", 10);

        // Publish sonar_msg_ to the "sonar_data" topic
        pub.publish(sonar_msg_);
    }

    // Member variables
    ros::NodeHandle nh_;
    sensor_msgs::Range sonar_msg_;
};
