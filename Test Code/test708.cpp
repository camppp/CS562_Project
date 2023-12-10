void Camera::update()
{
    apply_jitter();

    glm::quat qPitch = glm::angleAxis(m_pitch, glm::vec3(1.0f, 0.0f, 0.0f));
    glm::quat qYaw   = glm::angleAxis(m_yaw, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::quat qRoll  = glm::angleAxis(m_roll, glm::vec3(0.0f, 0.0f, 1.0f));

    // Combine the orientation quaternions in the correct order to update the camera's orientation
    m_orientation = qPitch * m_orientation;
    m_orientation = m_orientation * qYaw;
    m_orientation = m_orientation * qRoll;
}
