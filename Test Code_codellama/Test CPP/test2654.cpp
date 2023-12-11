double calculateRearLeftWheelAngularSpeed(double angularSpeed, const double* wheelRearRightVelocity, double noSlipLinearSpeed, const double* worldVelTrisphere0, EntityComponentManager* ecm, Entity wheelRearLeftSpin1Entity) {
    // Calculate the angular speed of the rear left wheel based on the given context and code snippet
    double wheelRearLeftVelocity = ecm->Component<WheelVelocity>(wheelRearLeftSpin1Entity);
    double angularSpeedRearLeft = (wheelRearLeftVelocity - noSlipLinearSpeed) / (wheelRearRightVelocity - noSlipLinearSpeed);
    return angularSpeedRearLeft;
}
