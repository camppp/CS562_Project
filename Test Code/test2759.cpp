void SetupCharacterMovementAndCamera(USpringArmComponent* CameraBoom, USceneComponent* RootComponent, UCharacterMovementComponent* CharacterMovement)
{
    // Initialize character movement properties
    CharacterMovement->RotationRate = FRotator(0.0f, 100.0f, 0.0f);
    CharacterMovement->MaxWalkSpeed = 100.0f;
    CharacterMovement->MaxSlopeAngle = 45.0f;
    CharacterMovement->bConstrainToPlane = true;
    CharacterMovement->bSnapToPlane = true;

    // Setup camera boom
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->bDoCollisionTest = false;
    CameraBoom->bUsePawnControlRotation = true;
    CameraBoom->bInheritPitch = true;
    CameraBoom->bInheritYaw = true;
    CameraBoom->bInheritRoll = true;

    // Setup camera
    CameraBoom->CameraComponent->SetFieldOfView(60.0f);
    CameraBoom->CameraComponent->SetAspectRatio(1.33333f);
    CameraBoom->CameraComponent->SetNearClipPlane(1.0f);
    CameraBoom->CameraComponent->SetFarClipPlane(10000.0f);
}
