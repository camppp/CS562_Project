c
double* calculateFeatureMeans(double *ptr, int numObservations, int numFeatures) {
    double *means = (double *)malloc(numFeatures * sizeof(double));
    for (int i = 0; i < numFeatures; i++) {
        means[i] = 0;
    }
    for (int i = 0; i < numObservations; i++) {
        for (int j = 0; j < numFeatures; j++) {
            means[j] += ptr[i * numFeatures + j];
        }
    }
    for (int i = 0; i < numFeatures; i++) {
        means[i] /= numObservations;
    }
    return means;
}
