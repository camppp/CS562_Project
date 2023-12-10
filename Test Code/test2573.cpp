java
public static float calculateAverage(float[] reference) {
    float sum = 0.0f;
    int count = 0;

    for (float val : reference) {
        if (val > 0.0f) {
            sum += val;
            count++;
        }
    }

    if (count == 0) {
        return -1;
    } else {
        return sum / count;
    }
}
