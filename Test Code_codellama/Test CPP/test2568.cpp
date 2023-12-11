bool compareJointConfigurations(const std::vector<JointPtr>& result, const std::vector<JointPtr>& expected) {
    // Check that the result and expected vectors have the same size
    if (result.size() != expected.size()) {
        return false;
    }

    // Iterate over the joints in the result and expected vectors
    for (size_t i = 0; i < result.size(); i++) {
        // Get the current joint from the result vector
        JointPtr currentJoint = result[i];

        // Get the corresponding joint from the expected vector
        JointPtr expectedJoint = expected[i];

        // Check that the current joint's angle is within a tolerance of the expected joint's angle
        if (std::abs(currentJoint->getAngle() - expectedJoint->getAngle()) > 0.01) {
            return false;
        }
    }

    // If we reach this point, the joint configurations match
    return true;
}
