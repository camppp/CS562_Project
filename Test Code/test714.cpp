// LevelSwitchTrigger.cpp
#include "LevelSwitchTrigger.h"

// Sets default values
ALevelSwitchTrigger::ALevelSwitchTrigger()
{
	PrimaryActorTick.bCanEverTick = false;

	TriggerPoint = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerPoint"));
	RootComponent = TriggerPoint;

	Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	Billboard->SetupAttachment(GetRootComponent());

	bCanSwitchLevel = false;

	TriggerPoint->OnComponentBeginOverlap.AddDynamic(this, &ALevelSwitchTrigger::OnPlayerEnterTrigger);
}

// Called when the game starts or when spawned
void ALevelSwitchTrigger::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALevelSwitchTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Enable or disable the level switch
void ALevelSwitchTrigger::SetLevelSwitchEnabled(bool bEnabled)
{
	bCanSwitchLevel = bEnabled;
}

// Function to handle level switch activation
void ALevelSwitchTrigger::OnPlayerEnterTrigger(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (bCanSwitchLevel && OtherActor != nullptr && OtherActor->IsA(APawn::StaticClass()))
	{
		// Implement level switch logic here, e.g., load a new level or teleport the player to a different location
	}
}
