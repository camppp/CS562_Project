#include <iostream>
#include <string>
#include <cstdint>

class RosBagReader {
private:
    uint64_t frame_num;  // frame number in streaming session (stream is looped, video sequence will be repeated again and again)
    std::string bag_file_name;  // name of the ROS bag file being read

public:
    RosBagReader() : frame_num(0), bag_file_name("") {}

    ~RosBagReader() {
        // Perform any necessary cleanup here
    }

    // Method to open a ROS bag file and read data from it
    void open(const std::string& file_name) {
        // Open the ROS bag file and read data
        bag_file_name = file_name;
        // Simulate reading data and updating frame number
        // In a real implementation, this would involve parsing the bag file and extracting relevant data
        frame_num = 1;  // Simulated frame number
        std::cout << "Opened ROS bag file: " << bag_file_name << std::endl;
    }

    // Method to retrieve the frame number from the streaming session
    uint64_t getFrameNumber() const {
        return frame_num;
    }
};

int main() {
    RosBagReader reader;
    reader.open("example.bag");
    std::cout << "Current frame number: " << reader.getFrameNumber() << std::endl;
    return 0;
}
