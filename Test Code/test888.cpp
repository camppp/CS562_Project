bool sendMeasured() {
    // Implement the logic to determine whether to send a measured message or a commanded message
    // For example, you can use a simple condition like sending measured message every alternate iteration
    static bool sendMeasured = false;
    sendMeasured = !sendMeasured; // Alternate between sending measured and commanded messages
    return sendMeasured;
}

modrob_workstation::RobotConfigMeasured measuredMsg() {
    modrob_workstation::RobotConfigMeasured msg;
    // Populate the measured message with appropriate data
    // For example, set the measured joint angles or positions
    msg.joint1 = 1.0;
    msg.joint2 = 2.0;
    // ...
    return msg;
}
