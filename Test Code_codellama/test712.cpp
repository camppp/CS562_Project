ThreadLockState* SystemGetThreadLockState(LockFlags lockFlags) {
  // Get the current thread ID
  std::thread::id threadId = std::this_thread::get_id();

  // Get the thread-local storage for the current thread
  std::thread_local ThreadLockState* threadLocalState = nullptr;

  // If the thread-local storage is not initialized, initialize it
  if (!threadLocalState) {
    threadLocalState = new ThreadLockState();
    std::thread_local_storage::set(threadId, threadLocalState);
  }

  // Get the lock state for the current thread
  ThreadLockState& lockState = threadLocalState->getLockState(lockFlags);

  // Return a pointer to the lock state
  return &lockState;
}
