void WorkerThread::start() {
    // Set the worker thread's status to S_running
    _status = S_running;

    // Notify the scheduler that the thread has started
    _parent_obj->signal_thread();

    // Call the thread_main() method to begin processing tasks
    thread_main();
}
