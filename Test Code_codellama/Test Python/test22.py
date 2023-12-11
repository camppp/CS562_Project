def simulate_arm_movement(duration, time_step, initial_joint_angles, joint_velocities):
   # Initialize the joint angles and velocities
   joint_angles = initial_joint_angles
   joint_velocities = joint_velocities
   
   # Simulate the arm movement for the given duration
   for i in range(int(duration / time_step)):
       # Update the joint angles based on the previous joint angles, time step, and joint velocities
       joint_angles = [joint_angles[i] + joint_velocities[i] * time_step for i in range(len(joint_angles))]
       
       # Set the joint orientations using the `set_joint_orientation` function
       for i in range(len(joint_angles)):
           set_joint_orientation(i, joint_angles[i], "absolute")
       
       # Sleep for the time step
       time.sleep(time_step)