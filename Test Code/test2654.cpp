double calculateRearLeftWheelAngularSpeed(double angularSpeed, const double* wheelRearRightVelocity, double noSlipLinearSpeed, const double* worldVelTrisphere0, EntityComponentManager* ecm, Entity wheelRearLeftSpin1Entity) {
    // Calculate the angular speed of the rear left wheel
    // Access the velocity data of the rear left wheel using the provided entity and ecm
    components::JointVelocity* wheelRearLeftVelocity = ecm->Component<components::JointVelocity>(wheelRearLeftSpin1Entity);

    // Calculate the angular speed based on the difference between the angular speed of the vehicle and the velocity of the rear right wheel
    double rearLeftAngularSpeed = angularSpeed - wheelRearRightVelocity[0];

    // Return the calculated angular speed of the rear left wheel
    return rearLeftAngularSpeed;
}
