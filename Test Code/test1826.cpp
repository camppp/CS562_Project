double calculateAverageFPS(int* frameTimes, int numFrames) {
    double totalFPS = 0.0;
    for (int i = 0; i < numFrames; i++) {
        totalFPS += 1000.0 / frameTimes[i];  // Convert time interval to FPS
    }
    return totalFPS / numFrames;  // Calculate average FPS
}
