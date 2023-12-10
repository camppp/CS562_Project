#include <stdio.h>
#include <pthread.h>

volatile int opt = 1;

void *threadFn(void *arg) {
    while (opt == 1) {
        // Perform some operations
    }
    printf("Thread exiting\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, threadFn, NULL);

    // Simulate an external operation changing the value of opt
    // For demonstration purposes, sleep for a short duration before changing the value
    sleep(2);
    opt = 0;

    pthread_join(thread, NULL);
    printf("Main thread exiting\n");

    return 0;
}
