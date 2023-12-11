float calculateAverageVerticalBearing(int vertBearings[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += vertBearings[i];
    }
    return sum / size;
}
