int InternalPartition(int aVector[], int aLow, int aHigh) {
    int pivot = aVector[aHigh];  // Select the pivot element as the last element
    int i = aLow - 1;  // Initialize the index of the smaller element

    for (int j = aLow; j < aHigh; j++) {
        if (aVector[j] < pivot) {
            i++;  // Increment index of smaller element
            // Swap aVector[i] and aVector[j]
            int temp = aVector[i];
            aVector[i] = aVector[j];
            aVector[j] = temp;
        }
    }

    // Swap aVector[i+1] and aVector[aHigh] (pivot)
    int temp = aVector[i + 1];
    aVector[i + 1] = aVector[aHigh];
    aVector[aHigh] = temp;

    return i + 1;  // Return the index of the pivot element
}
