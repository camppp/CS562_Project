FVector CalculateRelativeVelocity(BodyInstance* BodyInst0, BodyInstance* BodyInst1, const FContactInfo& ContactInfo) {
    // Find relative velocity.
    FVector Velocity0 = BodyInst0->GetUnrealWorldVelocityAtPoint_AssumesLocked(ContactInfo.ContactPosition);
    FVector AngularVel0 = BodyInst0->GetUnrealWorldAngularVelocityInRadians_AssumesLocked();

    FVector Velocity1 = BodyInst1->GetUnrealWorldVelocityAtPoint_AssumesLocked(ContactInfo.ContactPosition);
    FVector AngularVel1 = BodyInst1->GetUnrealWorldAngularVelocityInRadians_AssumesLocked();

    // Calculate relative velocity as the difference between the velocities of the two bodies.
    const FVector RelVel = Velocity1 - Velocity0;

    return RelVel;
}
