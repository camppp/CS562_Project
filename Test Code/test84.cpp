#include <stdbool.h>
#include <stdlib.h>

// Structure for the payload
typedef struct {
    int validation_code;
    int process_id;
    int owner_process_id;
} Payload;

// Function to send IOCTL command to the driver
extern bool request_ioctl(int command, Payload* payload, size_t size);

int enumerateProcessThreads(int process_id) {
    Payload* payload = (Payload*)malloc(sizeof(Payload));
    if (payload == NULL) {
        return -1; // Memory allocation failure
    }

    payload->validation_code = MHYPROT_ENUM_PROCESS_THREADS_CODE;
    payload->process_id = process_id;
    payload->owner_process_id = process_id;

    if (!request_ioctl(MHYPROT_IOCTL_ENUM_PROCESS_THREADS, payload, sizeof(Payload))) {
        free(payload);
        return -1; // IOCTL request failure
    }

    int* threadCount = (int*)payload;
    int numThreads = *threadCount;

    free(payload);
    return numThreads;
}
