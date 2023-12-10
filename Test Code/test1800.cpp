void WorkerThread::start() {
    std::unique_lock<std::mutex> lock(_mutex);
    if (_status != S_idle) {
        // Thread is already running or waiting, do nothing
        return;
    }
    _status = S_running;
    _cv.notify_one(); // Notify the scheduler that the thread has started
    lock.unlock(); // Release the lock before calling thread_main
    thread_main(); // Begin processing tasks
}
