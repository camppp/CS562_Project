void execute() {
    std::unique_lock<std::mutex> lk(mutex_);
    // At this point, if "alive_ == true" then tasks_pool_ cannot be empty (the lock was reacquired before evaluating the predicate).
    if (alive_) {
        task = tasks_pool_.front();
        tasks_pool_.pop();
        lk.unlock();

        ++running_tasks_count_;

        // Execute the task here using the obtained task
        // ...

        lk.lock();
        --running_tasks_count_;
        cv_.notify_one();
    }
}
