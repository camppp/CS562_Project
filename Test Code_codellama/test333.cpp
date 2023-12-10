glm::vec3 applyRotations(glm::vec3 initialPosition, float ry, float rz) {
    // Create the rotation matrices
    glm::mat4 roty = glm::rotate(unit, glm::radians(ry), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 rotz = glm::rotate(unit, glm::radians(rz), glm::vec3(0.0f, 0.0f, 1.0f));

    // Apply the rotations to the initial position
    glm::vec3 rotatedPosition = initialPosition * roty * rotz;

    return rotatedPosition;
}
