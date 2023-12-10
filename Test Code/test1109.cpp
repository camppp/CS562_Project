PRStatus ProcessLock::acquire(Sleeper& sleeper) {
    // Acquire the cross-process lock
    if (lock_.acquire() != PR_SUCCESS) {
        return PR_FAILURE;
    }

    // Acquire the intra-process lock
    if (lockFD_.acquire() != PR_SUCCESS) {
        // Release the cross-process lock if the intra-process lock cannot be acquired
        lock_.release();
        return PR_FAILURE;
    }

    // Wait for the locks if they are not immediately available
    if (sleeper.waitForLocks(lock_, lockFD_) != PR_SUCCESS) {
        // Release both locks if waiting for them fails
        lock_.release();
        lockFD_.release();
        return PR_FAILURE;
    }

    return PR_SUCCESS;
}
