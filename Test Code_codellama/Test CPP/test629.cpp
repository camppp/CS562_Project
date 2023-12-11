for (int i = 0; i < ndets; i++) {
    int j = order[i];
    if (suppressed[j] == 0) {
        // Check if the current detection is suppressed by any previous detection
        for (int k = 0; k < i; k++) {
            if (suppressed[k] == 1) {
                // If the current detection is suppressed by a previous detection, mark it as suppressed
                suppressed[j] = 1;
                break;
            }
        }
    }
}
