#include "lifecycle_msgs/msg/rosidl_typesupport_opensplice_cpp__visibility_control.h"
#include "rclcpp/rclcpp.hpp"
#include "dds/domain/DomainParticipant.hpp"
#include "dds/pub/DataWriter.hpp"
#include "dds/sub/DataReader.hpp"

class DDSMiddlewareManager {
public:
    DDSMiddlewareManager() : participant_(nullptr), dataReader_(nullptr), dataWriter_(nullptr) {
        // Initialize DDS entities
    }

    ~DDSMiddlewareManager() {
        // Clean up DDS entities
    }

    void initialize() {
        // Create a DDS DomainParticipant and configure it using ROS 2 Lifecycle Messages package
        participant_ = std::make_shared<DDS::DomainParticipant>();
        // Configure participant using ROS 2 Lifecycle Messages package
    }

    void readData() {
        // Create a DDS DataReader and read data from the DDS middleware
        dataReader_ = std::make_shared<DDS::DataReader>();
        // Read data from the DDS middleware
    }

    void writeData(const YourDataType& data) {
        // Create a DDS DataWriter and write the provided data to the DDS middleware
        dataWriter_ = std::make_shared<DDS::DataWriter>();
        // Write data to the DDS middleware
    }

private:
    std::shared_ptr<DDS::DomainParticipant> participant_;
    std::shared_ptr<DDS::DataReader> dataReader_;
    std::shared_ptr<DDS::DataWriter> dataWriter_;
};
