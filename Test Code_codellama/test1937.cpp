#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the shared variable
volatile int opt = 1;

// Define the function that creates an infinite loop based on the value of opt
void* Fn(void* arg) {
    while (opt) {
        // Do some work
        printf("Working...\n");
        sleep(1);
    }
    return NULL;
}

// Define the function that changes the value of opt to 0
void ChangeOpt(void) {
    opt = 0;
}

int main() {
    // Create a thread that runs the Fn function
    pthread_t thread;
    pthread_create(&thread, NULL, Fn, NULL);

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    // Change the value of opt to 0
    ChangeOpt();

    // Print the value of opt
    printf("opt = %d\n", opt);

    return 0;
}
