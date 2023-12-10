#include <stdlib.h>
#include <string.h>

typedef struct {
    size_t dims; // number of dimensions
    size_t *size; // array of dimension sizes
    void *data; // pointer to the array data
} Array;

Array* deepCopyArray(const Array *src) {
    Array *dst = (Array*)malloc(sizeof(Array));
    if (dst == NULL) {
        return NULL; // Memory allocation failed
    }

    dst->dims = src->dims;
    dst->size = (size_t*)malloc(src->dims * sizeof(size_t));
    if (dst->size == NULL) {
        free(dst);
        return NULL; // Memory allocation failed
    }

    memcpy(dst->size, src->size, src->dims * sizeof(size_t));

    dst->data = malloc(src->size[0] * src->size[1] * sizeof(int)); // Assuming array data type is int
    if (dst->data == NULL) {
        free(dst->size);
        free(dst);
        return NULL; // Memory allocation failed
    }

    memcpy(dst->data, src->data, src->size[0] * src->size[1] * sizeof(int)); // Assuming array data type is int

    return dst;
}
