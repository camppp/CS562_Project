#include <stdlib.h>

typedef struct {
    int* data;
    int numFeatures;
    int numBins;
} DenseSift;

void simplified_dsift_delete(DenseSift* dsift) {
    if (dsift != NULL) {
        if (dsift->data != NULL) {
            free(dsift->data);  // Free the memory allocated for the data array
            dsift->data = NULL; // Set the data pointer to NULL to avoid dangling pointers
        }
        free(dsift);  // Free the memory allocated for the dense SIFT object
    }
}
