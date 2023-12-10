// Define the UOrangeVesselTarget class representing the target component
class UOrangeVesselTarget : public UActorComponent
{
    GENERATED_BODY()

public:
    // Define necessary functions and members for the target component
};

// Define the UOrangeTargetData class holding additional information about a target
class UOrangeTargetData : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsAffectedByThisEffect;
    // Define other necessary members and functions for the target data
};

// Implement the logic to handle the spell's effects
void HandleSpellEffect(const FHitResult& HitResult, UPillarManager* PillarManager)
{
    AActor* HitActor = Cast<AActor>(HitResult.Actor);
    if (HitActor)
    {
        UOrangeVesselTarget* Target = Cast<UOrangeVesselTarget>(HitActor->GetComponentByClass(UOrangeVesselTarget::StaticClass()));
        if (Target && Target->Owner)
        {
            UOrangeTargetData* Data = Cast<UOrangeTargetData>(Target->GetDataOfComponent(Cast<UPrimitiveComponent>(HitResult.Component)));
            if (PillarManager && Data && Data->bIsAffectedByThisEffect)
            {
                // Calculate the location and orientation of the affected target
                FVector Location = FVector(HitResult.Location.X, HitResult.Location.Y, HitResult.Location.Z);
                FRotator OtherUp = HitResult.Normal.Rotation();
                // Apply the spell's effect to the target using the calculated location and orientation
                ApplySpellEffectToTarget(Target, Location, OtherUp);
            }
        }
    }
}
