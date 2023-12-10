bool BeginFiringSequence(uint8 FireModeNum, bool bClientFired)
{
    // Check if the fire mode is valid
    if (FireModeNum >= FireModes.Num())
    {
        return false;
    }

    // Get the fire mode data
    const FireModeData& FireMode = FireModes[FireModeNum];

    // Check if the fire mode is currently active
    if (!FireMode.bActive)
    {
        return false;
    }

    // Check if the firing sequence is already in progress
    if (FireMode.bFiringSequenceInProgress)
    {
        return false;
    }

    // Set the firing sequence in progress flag
    FireMode.bFiringSequenceInProgress = true;

    // Initiate the firing sequence
    FireMode.FiringSequence.Begin(bClientFired);

    return true;
}
