#include <stdio.h>
#include <stdlib.h>

double* calculateFeatureMeans(double *ptr, int numObservations, int numFeatures) {
    double *featureMeans = (double *)malloc(numFeatures * sizeof(double)); // Allocate memory for the feature means

    // Initialize featureMeans array to store the sum of each feature
    for (int i = 0; i < numFeatures; i++) {
        featureMeans[i] = 0.0;
    }

    // Calculate the sum of each feature across all observations
    for (int obs = 0; obs < numObservations; obs++) {
        for (int feat = 0; feat < numFeatures; feat++) {
            featureMeans[feat] += ptr[obs * numFeatures + feat];
        }
    }

    // Calculate the mean value for each feature
    for (int i = 0; i < numFeatures; i++) {
        featureMeans[i] /= numObservations;
    }

    return featureMeans;
}

int main() {
    // Example usage
    double data[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0}; // Example dataset
    int numObservations = 2; // Number of observations
    int numFeatures = 3; // Number of features

    double *means = calculateFeatureMeans(data, numObservations, numFeatures);

    // Output the calculated feature means
    for (int i = 0; i < numFeatures; i++) {
        printf("Mean of Feature %d: %.2f\n", i+1, means[i]);
    }

    free(means); // Free the allocated memory

    return 0;
}
