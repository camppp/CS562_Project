c
#include <stdlib.h>
#include <string.h>
#include <android/gralloc_handle.h>

#define LOG_TAG "lamecomposer"

typedef struct {
    gralloc_handle_t handle;
    size_t size;
} gralloc_handle_info_t;

size_t processGrallocHandles(gralloc_handle_t *handles, size_t numHandles) {
    size_t total_size = 0;
    gralloc_handle_info_t *largest_handle = NULL;
    gralloc_handle_info_t *sorted_handles = NULL;

    // Calculate the total size of memory allocated by all the gralloc handles
    for (size_t i = 0; i < numHandles; i++) {
        total_size += handles[i].size;
    }

    // Find the gralloc handle with the largest memory allocation
    for (size_t i = 0; i < numHandles; i++) {
        if (largest_handle == NULL || handles[i].size > largest_handle->size) {
            largest_handle = &handles[i];
        }
    }

    // Sort the gralloc handles based on their memory allocation size in ascending order
    sorted_handles = (gralloc_handle_info_t *)malloc(numHandles * sizeof(gralloc_handle_info_t));
    for (size_t i = 0; i < numHandles; i++) {
        sorted_handles[i].handle = handles[i];
        sorted_handles[i].size = handles[i].size;
    }
    qsort(sorted_handles, numHandles, sizeof(gralloc_handle_info_t), compare_gralloc_handles);

    return total_size;
}

int compare_gralloc_handles(const void *a, const void *b) {
    const gralloc_handle_info_t *ha = (const gralloc_handle_info_t *)a;
    const gralloc_handle_info_t *hb = (const gralloc_handle_info_t *)b;
    return ha->size - hb->size;
}
