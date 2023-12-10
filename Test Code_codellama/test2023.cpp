#include <hip/hip_runtime.h>

// Define the mutex structure
typedef struct {
    hipEvent_t event;
    hipStream_t stream;
} mutex_t;

// Initialize the mutex
void mutex_init(mutex_t *mutex) {
    hipEventCreate(&mutex->event, hipEventDisableTiming);
    hipStreamCreate(&mutex->stream);
}

// Lock the mutex
void mutex_lock(mutex_t *mutex) {
    hipEventSynchronize(mutex->event);
    hipStreamWaitEvent(mutex->stream, mutex->event, 0);
}

// Unlock the mutex
void mutex_unlock(mutex_t *mutex) {
    hipEventRecord(mutex->event, mutex->stream);
}

// Destroy the mutex
void mutex_destroy(mutex_t *mutex) {
    hipEventDestroy(mutex->event);
    hipStreamDestroy(mutex->stream);
}
