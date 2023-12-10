Array* deepCopyArray(const Array *src) {
    // Allocate memory for the new array
    Array *dst = malloc(sizeof(Array));
    if (dst == NULL) {
        return NULL;
    }

    // Copy the dimension sizes
    dst->dims = src->dims;
    dst->size = malloc(src->dims * sizeof(size_t));
    if (dst->size == NULL) {
        free(dst);
        return NULL;
    }
    memcpy(dst->size, src->size, src->dims * sizeof(size_t));

    // Copy the array data
    dst->data = malloc(src->dims * src->size[0] * sizeof(void*));
    if (dst->data == NULL) {
        free(dst->size);
        free(dst);
        return NULL;
    }
    memcpy(dst->data, src->data, src->dims * src->size[0] * sizeof(void*));

    return dst;
}
