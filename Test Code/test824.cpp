#include <queue>

class Job {
    // Define the Job class as per your requirements
};

class JobScheduler {
private:
    std::queue<Job*> jobsQueue;
    Job* currentJob;

public:
    void addJob(Job* job) {
        jobsQueue.push(job);
    }

    Job* processNextJob() {
        if (!jobsQueue.empty()) {
            currentJob = jobsQueue.front();
            jobsQueue.pop();
            return currentJob;
        }
        else {
            currentJob = nullptr;
            return nullptr;
        }
    }
};
