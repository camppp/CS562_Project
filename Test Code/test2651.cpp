void flushLogs() {
    std::unique_lock<std::recursive_mutex> lock(this->sync.mutex);
    if (this->logs.size() == 0) {
        return;
    }

    auto pendingLogs = this->logs;
    this->logs.clear();

    // wait until previous logs have been flushed entirely
    auto waitUntilFlushed = [this] { return !this->sync.pending.load(); };
    this->sync.await.wait(lock, waitUntilFlushed);

    // Flush the pending logs
    this->sync.pending.store(true); // Mark logs as pending
    lock.unlock(); // Release the lock before flushing logs

    // Simulate flushing of logs (replace with actual flushing mechanism)
    for (const auto& log : pendingLogs) {
        // Simulate flushing by printing the log
        std::cout << "Flushing log: " << log << std::endl;
    }

    lock.lock(); // Reacquire the lock
    this->sync.pending.store(false); // Mark logs as flushed
    this->sync.await.notify_all(); // Notify waiting threads that logs have been flushed
}
