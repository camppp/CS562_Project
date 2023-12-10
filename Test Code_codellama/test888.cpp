bool sendMeasured() {
    // Determine whether to send a measured message or a commanded message
    // based on a certain condition
    if (condition) {
        return true;
    } else {
        return false;
    }
}

modrob_workstation::RobotConfigMeasured measuredMsg() {
    // Create a new RobotConfigMeasured message
    modrob_workstation::RobotConfigMeasured msg;

    // Set the message fields
    msg.header.stamp = ros::Time::now();
    msg.header.frame_id = "ns/robot_config_measured";
    msg.joint_angles.resize(num_joints);
    for (int i = 0; i < num_joints; i++) {
        msg.joint_angles[i] = joint_angles[i];
    }

    return msg;
}
