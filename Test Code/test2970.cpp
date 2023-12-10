class ALivingUnit
{
public:
    // Other methods and members are not shown for brevity.

    void OnEnemyLeaveSight(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
    {
        AUnit* OtherUnit = Cast<AUnit>(OtherActor);
        if (OtherUnit)
        {
            // TODO: Handle the case when an enemy unit leaves the sight of the living unit.
            // Your implementation goes here.
            // Example: Remove the OtherUnit from the data structure tracking enemy units within the living unit's sight.
        }
    }

    // Efficient data structure to track enemy units within the living unit's sight.
    std::unordered_set<AUnit*> enemyUnitsInSight;

    // Method to add an enemy unit to the data structure when it enters the living unit's sight.
    void AddEnemyToSight(AUnit* enemyUnit)
    {
        enemyUnitsInSight.insert(enemyUnit);
    }

    // Method to remove an enemy unit from the data structure when it leaves the living unit's sight.
    void RemoveEnemyFromSight(AUnit* enemyUnit)
    {
        enemyUnitsInSight.erase(enemyUnit);
    }
};
