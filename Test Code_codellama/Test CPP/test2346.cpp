#include <semaphore.h>

// Define the semaphore for the lock
sem_t lock;

// Initialize the semaphore
sem_init(&lock, 0, 1);

// Define the locking functions
void tryLockRead() {
    // Acquire the read lock
    sem_wait(&lock);
}

void tryLockWrite() {
    // Acquire the write lock
    sem_wait(&lock);
}

// Define the unlocking functions
void unlockRead() {
    // Release the read lock
    sem_post(&lock);
}

void unlockWrite() {
    // Release the write lock
    sem_post(&lock);
}

// Define the lock status function
int lockStatus() {
    // Return the current lock status
    return sem_getvalue(&lock);
}
