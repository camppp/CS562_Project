def simulate_arm_movement(duration, time_step, initial_joint_angles, joint_velocities):
    # Initialize joint angles
    q = initial_joint_angles

    # Simulate movement for the given duration
    for _ in range(int(duration / time_step)):
        # Update joint angles
        q = [q[i] + joint_velocities[i] * time_step for i in range(6)]

        # Set joint orientations
        for i in range(6):
            set_joint_orientation(i, q[i], 'absolute')