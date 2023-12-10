// UOrangeVesselTarget.h
#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UOrangeVesselTarget.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UOrangeVesselTarget : public UObject
{
    GENERATED_BODY()

public:
    UOrangeVesselTarget();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orange Vessel Target")
    FVector Location;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orange Vessel Target")
    FRotator Orientation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orange Vessel Target")
    bool bIsAffectedBySpell;
};

// UOrangeTargetData.h
#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UOrangeTargetData.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UOrangeTargetData : public UObject
{
    GENERATED_BODY()

public:
    UOrangeTargetData();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orange Target Data")
    bool bIsAffectedBySpell;
};

// SpellLogic.cpp
#include "SpellLogic.h"
#include "UOrangeVesselTarget.h"
#include "UOrangeTargetData.h"

bool IsTargetAffectedBySpell(AActor* HitActor)
{
    UOrangeVesselTarget* Target = Cast<UOrangeVesselTarget>(HitActor->GetComponentByClass(UOrangeVesselTarget::StaticClass()));
    if (!Target)
    {
        return false;
    }

    UOrangeTargetData* TargetData = Cast<UOrangeTargetData>(Target->GetComponentByClass(UOrangeTargetData::StaticClass()));
    if (!TargetData)
    {
        return false;
    }

    return TargetData->bIsAffectedBySpell;
}

void ApplySpellEffect(AActor* HitActor)
{
    UOrangeVesselTarget* Target = Cast<UOrangeVesselTarget>(HitActor->GetComponentByClass(UOrangeVesselTarget::StaticClass()));
    if (!Target)
    {
        return;
    }

    UOrangeTargetData* TargetData = Cast<UOrangeTargetData>(Target->GetComponentByClass(UOrangeTargetData::StaticClass()));
    if (!TargetData)
    {
        return;
    }

    TargetData->bIsAffectedBySpell = true;

    // Calculate the location and orientation of the affected target
    FVector Location = Target->Location;
    FRotator Orientation = Target->Orientation;

    // Apply the spell effect to the target
    // ...
}
