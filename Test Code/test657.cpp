// Define the HandleGameplayCue function to manage gameplay cues
void HandleGameplayCue(AActor* AvatarActor, FGameplayTag GameplayCueTag, EGameplayCueEvent::Type Event, FGameplayCueParameters Parameters)
{
    // Implement the logic to handle the gameplay cue based on the provided parameters
    // For the "GameplayCue.Jump" cue, trigger visual or audio effects when the character stops jumping
    if (Event == EGameplayCueEvent::Type::Removed && GameplayCueTag.MatchesTag(FGameplayTag::RequestGameplayTag(FName("GameplayCue.Jump"))))
    {
        // Trigger visual or audio effects related to the jump action being removed
        // Example: Play a sound effect or show a particle effect indicating the end of the jump action
        // Implement the specific visual or audio effects based on the game's requirements
    }
}

// Update the original code snippet to call the HandleGameplayCue function
if (character != nullptr)
{
    UAbilitySystemGlobals::Get().GetGameplayCueManager()->HandleGameplayCue(
            ActorInfo->AvatarActor.Get(),
            FGameplayTag::RequestGameplayTag(FName("GameplayCue.Jump")),
            EGameplayCueEvent::Type::Removed,
            FGameplayCueParameters());
    character->StopJumping_();
}
