public static float calculateAverage(float[] reference) {
    float sum = 0.0f;
    int count = 0;

    for (int i = 0; i < reference.length; i++) {
        if (reference[i] > 0.0f) {
            sum += reference[i];
            count++;
        }
    }

    if (count == 0) {
        return -1.0f;
    }

    return sum / count;
}
