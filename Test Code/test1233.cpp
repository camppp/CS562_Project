FVector CalculateRelativeVelocity(BodyInstance* BodyInst0, BodyInstance* BodyInst1, const FContactInfo& ContactInfo) {
    FVector Velocity0 = BodyInst0->GetUnrealWorldVelocityAtPoint_AssumesLocked(ContactInfo.ContactPosition);
    FVector Velocity1 = BodyInst1->GetUnrealWorldVelocityAtPoint_AssumesLocked(ContactInfo.ContactPosition);
    FVector AngularVelocity0 = BodyInst0->GetUnrealWorldAngularVelocityInRadians_AssumesLocked();
    FVector AngularVelocity1 = BodyInst1->GetUnrealWorldAngularVelocityInRadians_AssumesLocked();

    FVector RelativeVelocity = Velocity0 - Velocity1;
    RelativeVelocity += AngularVelocity0.Cross(ContactInfo.ContactPosition - BodyInst0->GetUnrealWorldPosition());
    RelativeVelocity -= AngularVelocity1.Cross(ContactInfo.ContactPosition - BodyInst1->GetUnrealWorldPosition());

    return RelativeVelocity;
}
