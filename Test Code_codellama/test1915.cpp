Matrix4 Matrix4::ViewMatrix(const Vector3& position, const Vector3& rotation)
{
    // Calculate the sine and cosine of the rotation angles
    float sinX = std::sin(rotation.x);
    float cosX = std::cos(rotation.x);
    float sinY = std::sin(rotation.y);
    float cosY = std::cos(rotation.y);
    float sinZ = std::sin(rotation.z);
    float cosZ = std::cos(rotation.z);

    // Calculate the first column of the view matrix
    Vector3 column1 = Vector3(cosY * cosZ, cosY * sinZ, -sinY);

    // Calculate the second column of the view matrix
    Vector3 column2 = Vector3(sinX * sinY * cosZ - cosX * sinZ, sinX * sinY * sinZ + cosX * cosZ, cosX * sinY);

    // Calculate the third column of the view matrix
    Vector3 column3 = Vector3(sinX * cosY, -sinX * sinY, cosX);

    // Calculate the fourth column of the view matrix
    Vector3 column4 = Vector3(0, 0, 0);

    // Calculate the translation vector
    Vector3 translation = position;

    // Calculate the view matrix
    Matrix4 viewMatrix = Matrix4(column1, column2, column3, column4, translation);

    return viewMatrix;
}
