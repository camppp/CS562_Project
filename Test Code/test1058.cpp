#include <iostream>
#include <string>
#include <cmath>

class Camera {
public:
    // Constructor to initialize the camera with a given name
    Camera(const std::string& name) : name_(name), distance_(0.0f), fov_(90.0f), position_{0.0f, 0.0f, 0.0f}, orientation_{0.0f, 0.0f, 0.0f} {}

    // Method to set the distance to the focal point
    void setDistance(float distance) {
        distance_ = distance;
    }

    // Method to set the field of view angle
    void setFOV(float fov) {
        fov_ = fov;
    }

    // Method to set the camera's position in 3D space
    void setPosition(float x, float y, float z) {
        position_[0] = x;
        position_[1] = y;
        position_[2] = z;
    }

    // Method to set the camera's orientation (pitch, yaw, roll)
    void setOrientation(float pitch, float yaw, float roll) {
        orientation_[0] = pitch;
        orientation_[1] = yaw;
        orientation_[2] = roll;
    }

    // Method to retrieve the camera's name
    std::string getName() const {
        return name_;
    }

    // Method to retrieve the distance to the focal point
    float getDistance() const {
        return distance_;
    }

    // Method to retrieve the field of view angle
    float getFOV() const {
        return fov_;
    }

    // Method to retrieve the camera's position in 3D space
    const float* getPosition() const {
        return position_;
    }

    // Method to retrieve the camera's orientation
    const float* getOrientation() const {
        return orientation_;
    }

private:
    float distance_;  // Distance to the focal point
    float fov_;       // Field of view angle
    std::string name_;  // Name of the camera
    float position_[3];  // Camera's position in 3D space (x, y, z)
    float orientation_[3];  // Camera's orientation (pitch, yaw, roll)
};

int main() {
    Camera myCamera("MainCamera");
    myCamera.setDistance(10.0f);
    myCamera.setFOV(120.0f);
    myCamera.setPosition(1.0f, 2.0f, 3.0f);
    myCamera.setOrientation(45.0f, 30.0f, 0.0f);

    std::cout << "Camera Name: " << myCamera.getName() << std::endl;
    std::cout << "Distance to Focal Point: " << myCamera.getDistance() << std::endl;
    std::cout << "Field of View: " << myCamera.getFOV() << std::endl;

    const float* position = myCamera.getPosition();
    std::cout << "Camera Position: (" << position[0] << ", " << position[1] << ", " << position[2] << ")" << std::endl;

    const float* orientation = myCamera.getOrientation();
    std::cout << "Camera Orientation (Pitch, Yaw, Roll): (" << orientation[0] << ", " << orientation[1] << ", " << orientation[2] << ")" << std::endl;

    return 0;
}
