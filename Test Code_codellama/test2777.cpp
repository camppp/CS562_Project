#include <ros2/lifecycle_msgs.hpp>
#include <dds/dds.hpp>

class DDSMiddlewareManager {
public:
    DDSMiddlewareManager() {
        // Initialize DDS entities and set up configurations
        initialize();
    }

    ~DDSMiddlewareManager() {
        // Destroy DDS entities
        destroy();
    }

    void initialize() {
        // Create DDS DomainParticipant using ROS 2 Lifecycle Messages package
        domain_participant_ = ros2::create_domain_participant();

        // Configure DDS DomainParticipant using ROS 2 Lifecycle Messages package
        domain_participant_.set_qos(ros2::get_domain_participant_qos());

        // Create DDS DataReader using ROS 2 Lifecycle Messages package
        data_reader_ = domain_participant_.create_data_reader(ros2::get_data_reader_qos());

        // Create DDS DataWriter using ROS 2 Lifecycle Messages package
        data_writer_ = domain_participant_.create_data_writer(ros2::get_data_writer_qos());
    }

    void readData() {
        // Read data from DDS middleware using DDS DataReader
        data_reader_.read(data_);
    }

    void writeData(const YourDataType& data) {
        // Write data to DDS middleware using DDS DataWriter
        data_writer_.write(data);
    }

private:
    // DDS entities
    ros2::DomainParticipant domain_participant_;
    ros2::DataReader data_reader_;
    ros2::DataWriter data_writer_;

    // Data to be written
    YourDataType data_;
};
