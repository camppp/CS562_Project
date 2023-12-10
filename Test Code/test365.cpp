Mat4 Camera::lookAt() const {
    // Calculate the view matrix based on the camera's position and target
    Vec3 up = Vec3(0.0, 1.0, 0.0);
    return Mat4::lookAt(*getPosition(), *target, up);
}
