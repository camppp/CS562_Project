#include <thread>
#include <mutex>
#include <unordered_map>

// Define a thread-local storage for ThreadLockState objects
thread_local std::unordered_map<LockFlags, ThreadLockState> thread_lock_states;

// Define a mutex for thread-local state access
std::mutex thread_lock_states_mutex;

ThreadLockState* SystemGetThreadLockState(LockFlags lock_flags) {
  // Lock the access to thread-local state
  std::lock_guard<std::mutex> lock(thread_lock_states_mutex);

  // Check if the ThreadLockState for the given lock_flags exists
  auto it = thread_lock_states.find(lock_flags);
  if (it == thread_lock_states.end()) {
    // If not found, create a new ThreadLockState for the lock_flags
    thread_lock_states[lock_flags] = ThreadLockState{};
  }

  // Return a pointer to the thread-local ThreadLockState for the lock_flags
  return &thread_lock_states[lock_flags];
}
