class JobScheduler {
public:
    JobScheduler(JobQueue* jobs, Semaphore* pending) : _jobs(jobs), _pending(pending) {}

    void schedule(Job routine) {
        // Insert the job into the job queue
        if (_jobs->insert(routine) == _jobs->empty()) {
            // If the job queue was empty before the insertion, signal the semaphore
            _pending->give();
        }
    }

private:
    JobQueue* _jobs;
    Semaphore* _pending;
};
