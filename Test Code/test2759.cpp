void SetupCharacterMovementAndCamera(USpringArmComponent* CameraBoom, USceneComponent* RootComponent, UCharacterMovementComponent* CharacterMovement) {
    // Set character movement properties
    CharacterMovement->bOrientRotationToMovement = true; // Rotate character to moving direction
    CharacterMovement->RotationRate = FRotator(0.f, 640.f, 0.f);
    CharacterMovement->bConstrainToPlane = true;
    CharacterMovement->bSnapToPlaneAtStart = true;

    // Create a camera boom and attach it to the character's root component
    CameraBoom = NewObject<USpringArmComponent>(RootComponent, TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
}
