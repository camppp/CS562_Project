int GetAssignedClass(int desiredClass, int playerIndex) {
    int assignedClass;
    const int TF_CLASS_RANDOM = -1; // Assuming TF_CLASS_RANDOM is defined as -1

    if (desiredClass != TF_CLASS_RANDOM) {
        assignedClass = desiredClass;
    } else {
        // Assuming tf_PR is a global or accessible object that provides player class information
        assignedClass = tf_PR->GetPlayerClass(playerIndex);
    }

    return assignedClass;
}
