#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "LevelSwitchTrigger.generated.h"

UCLASS()
class YOURGAME_API ALevelSwitchTrigger : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALevelSwitchTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Trigger")
	UBoxComponent* TriggerPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Trigger")
	UBillboardComponent* Billboard;

	bool bCanSwitchLevel;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Enable or disable the level switch
	void SetLevelSwitchEnabled(bool bEnabled);

	// Function to handle level switch activation
	UFUNCTION()
	void OnPlayerEnterTrigger(class AActor* OverlappedActor, class AActor* OtherActor);
};

ALevelSwitchTrigger::ALevelSwitchTrigger()
{
	// Set default values for this actor's properties
	PrimaryActorTick.bCanEverTick = true;

	// Create the trigger point and billboard components
	TriggerPoint = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerPoint"));
	TriggerPoint->SetCollisionProfileName(TEXT("Trigger"));
	TriggerPoint->SetBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	TriggerPoint->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));

	Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	Billboard->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
	Billboard->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
	Billboard->SetMaterial(0, LoadObject<UMaterial>(nullptr, TEXT("/Game/Materials/TriggerMaterial.TriggerMaterial")));

	// Set the default values for the level switch
	bCanSwitchLevel = false;
}

void ALevelSwitchTrigger::BeginPlay()
{
	Super::BeginPlay();

	// Set the trigger point and billboard components to be visible
	TriggerPoint->SetVisibility(true);
	Billboard->SetVisibility(true);
}

void ALevelSwitchTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Check if the player has entered the trigger area
	if (TriggerPoint->IsOverlappingActor(GetWorld()->GetFirstPlayerController()->GetPawn()))
	{
		// If the level switch is enabled, activate it
		if (bCanSwitchLevel)
		{
			// TODO: Implement level switch activation logic here
		}
	}
}

void ALevelSwitchTrigger::SetLevelSwitchEnabled(bool bEnabled)
{
	bCanSwitchLevel = bEnabled;
}

void ALevelSwitchTrigger::OnPlayerEnterTrigger(class AActor* OverlappedActor, class AActor* OtherActor)
{
	// Check if the player has entered the trigger area
	if (OverlappedActor == GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		// If the level switch is enabled, activate it
		if (bCanSwitchLevel)
		{
			// TODO: Implement level switch activation logic here
		}
	}
}
