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

    // Print details of all added cameras
    void PrintAllCameras() {
        for (const auto& cam : cameras) {
            std::cout << "Camera ID: " << cam.id << ", Name: " << cam.name << std::endl;
        }
    }
};

int main() {
    // Create a CameraManager object
    CameraManager manager;

    // Add some cameras
    manager.CameraAdded(Camera(1, "Front Camera"));
    manager.CameraAdded(Camera(2, "Rear Camera"));

    // Print all added cameras
    manager.PrintAllCameras();

    // Print an error message
    manager.PrintError(0x12345678);

    return 0;
}
