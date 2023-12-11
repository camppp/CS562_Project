// Method to set the camera's position in 3D space
void setPosition(const glm::vec3& position) {
    position_ = position;
}

// Method to retrieve the camera's position in 3D space
glm::vec3 getPosition() const {
    return position_;
}

// Method to adjust the camera's orientation (e.g., pitch, yaw, roll)
void adjustOrientation(const glm::vec3& orientation) {
    orientation_ = orientation;
}

// Method to retrieve the camera's orientation (e.g., pitch, yaw, roll)
glm::vec3 getOrientation() const {
    return orientation_;
}
