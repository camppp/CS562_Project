void findMinMax(float arr[], int length, float& maxVal, float& minVal) {
    if (length <= 0) {
        // Handle empty array case
        maxVal = -FLT_MAX;
        minVal = FLT_MAX;
        return;
    }

    maxVal = arr[0];
    minVal = arr[0];

    for (int i = 1; i < length; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
}
