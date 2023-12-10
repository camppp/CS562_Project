Mat4 Camera::lookAt() const {
    Vec3 up = Vec3(0.0, 1.0, 0.0); // Define the up vector
    Mat4 rot = Mat4::lookAt(*getPosition(), *target, up); // Calculate the view matrix using the provided method
    return rot; // Return the calculated view matrix
}
