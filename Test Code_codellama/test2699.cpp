int GetAssignedClass(int desiredClass, int playerIndex)
{
    if (desiredClass != TF_CLASS_RANDOM)
    {
        // If the desired class is not random, assign it to the player
        return desiredClass;
    }
    else
    {
        // For non-local players, show the current class
        return tf_PR->GetPlayerClass(playerIndex);
    }
}
