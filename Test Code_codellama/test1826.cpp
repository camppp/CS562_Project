double calculateAverageFPS(int* frameTimes, int numFrames) {
    double sum = 0;
    for (int i = 0; i < numFrames; i++) {
        sum += 1000 / frameTimes[i];
    }
    return sum / numFrames;
}
