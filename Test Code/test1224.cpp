bool UKGWeaponStateActive::BeginFiringSequence(uint8 FireModeNum, bool bClientFired)
{
    // Check if the provided fire mode number is valid
    if (FireModeNum < TotalFireModes)
    {
        // Check if the firing action is initiated by the client
        if (bClientFired)
        {
            // Perform client-specific firing sequence initiation logic
            // ...
            return true;  // Return true indicating successful initiation
        }
        else
        {
            // Perform server-specific firing sequence initiation logic
            // ...
            return true;  // Return true indicating successful initiation
        }
    }
    else
    {
        // Invalid fire mode number, unable to initiate firing sequence
        return false;  // Return false indicating failure
    }
}
