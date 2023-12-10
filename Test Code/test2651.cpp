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

    // wait until all pending logs have been flushed entirely
    auto waitUntilAllFlushed = [this, pendingLogs] {
        return this->logs.size() == 0 && pendingLogs.size() == 0;
    };
    this->sync.await.wait(lock, waitUntilAllFlushed);
}
