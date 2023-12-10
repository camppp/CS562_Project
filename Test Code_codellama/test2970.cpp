void ALivingUnit::OnEnemyLeaveSight(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    AUnit* OtherUnit = Cast<AUnit>(OtherActor);
    if (OtherUnit)
    {
        // Remove the enemy unit from the data structure that tracks enemy units within the living unit's sight.
        EnemyUnits.Remove(OtherUnit);
    }
}
