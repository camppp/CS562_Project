void HandleGameplayCue(AActor* ActorInfo, FGameplayTag GameplayCueTag, EGameplayCueEvent::Type EventType, FGameplayCueParameters CueParameters)
{
    if (GameplayCueTag == FGameplayTag::RequestGameplayTag(FName("GameplayCue.Jump")))
    {
        if (EventType == EGameplayCueEvent::Type::Removed)
        {
            // Trigger the gameplay cue "GameplayCue.Jump" when the character stops jumping
            ActorInfo->AvatarActor.Get()->TriggerGameplayCue(FName("GameplayCue.Jump"));
        }
    }
}
