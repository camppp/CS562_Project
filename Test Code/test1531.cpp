float calculateAverageVerticalBearing(int vertBearings[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += vertBearings[i];
    }
    return static_cast<float>(sum) / size;
}
