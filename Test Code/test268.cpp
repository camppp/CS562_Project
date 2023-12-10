#include <stdio.h>
#include <pthread.h>

pthread_mutex_t resource_mutex = PTHREAD_MUTEX_INITIALIZER;
int next_device_id = 1;

typedef struct {
    int device_id;
    // other device-specific data
} DeviceData;

void *device_thread(void *device_data_ptr) {
    DeviceData *device_data = (DeviceData *)device_data_ptr;

    // Request access to the resource
    pthread_mutex_lock(&resource_mutex);
    printf("Device %d requests access.\n", device_data->device_id);

    // Simulate accessing the resource
    printf("Device %d accesses the resource.\n", device_data->device_id);

    // Release the resource
    printf("Device %d releases the resource.\n", device_data->device_id);
    pthread_mutex_unlock(&resource_mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];  // Create 3 device threads for demonstration
    DeviceData devices[3];

    for (int i = 0; i < 3; i++) {
        devices[i].device_id = next_device_id++;
        pthread_create(&threads[i], NULL, device_thread, (void *)&devices[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
