#include <iostream>
#include <vector>

// Define the Camera class
class Camera {
public:
    int id;
    std::string name;
    // Constructor to initialize id and name
    Camera(int id, const std::string& name) : id(id), name(name) {}
};

// Define the CameraManager class
class CameraManager {
private:
    std::vector<Camera> cameras;  // Store the added cameras

public:
    // Add a new camera to the system
    void CameraAdded(const Camera& cam) {
        cameras.push_back(cam);
    }

    // Print error message with error code
    void PrintError(long errorCode) {
        std::cout << "Error: 0x" << std::hex << errorCode << std::dec << std::endl;
    }

    // Print the details of all added cameras
    void PrintCameras() {
        for (const auto& cam : cameras) {
            std::cout << "Camera " << cam.id << ": " << cam.name << std::endl;
        }
    }
};
