Matrix4 Matrix4::ViewMatrix(const Vector3& position, const Vector3& rotation) {
    Matrix4 viewMatrix;

    // Calculate the camera's forward, right, and up vectors based on the rotation
    Vector3 forward = Vector3(
        cos(rotation.y) * cos(rotation.x),
        sin(rotation.x),
        sin(rotation.y) * cos(rotation.x)
    ).normalize();

    Vector3 right = Vector3(
        sin(rotation.y - Maths::Radians(90.0f)),
        0,
        cos(rotation.y - Maths::Radians(90.0f))
    ).normalize();

    Vector3 up = right.cross(forward);

    // Set the view matrix based on the camera's position and orientation
    viewMatrix[0][0] = right.x;
    viewMatrix[1][0] = right.y;
    viewMatrix[2][0] = right.z;
    viewMatrix[3][0] = -right.dot(position);

    viewMatrix[0][1] = up.x;
    viewMatrix[1][1] = up.y;
    viewMatrix[2][1] = up.z;
    viewMatrix[3][1] = -up.dot(position);

    viewMatrix[0][2] = -forward.x;
    viewMatrix[1][2] = -forward.y;
    viewMatrix[2][2] = -forward.z;
    viewMatrix[3][2] = forward.dot(position);

    viewMatrix[0][3] = 0.0f;
    viewMatrix[1][3] = 0.0f;
    viewMatrix[2][3] = 0.0f;
    viewMatrix[3][3] = 1.0f;

    return viewMatrix;
}
