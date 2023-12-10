#include <iostream>
#include <sstream>
#include <queue>
#include <stdexcept>

class Printer {
private:
    std::queue<std::string> jobQueue;
    std::string lastErrorDetails;

public:
    void addJob(const std::string& job) {
        jobQueue.push(job);
    }

    int pendingJobs() {
        return jobQueue.size();
    }

    std::string reportStatus() {
        std::stringstream status;
        status << "Pending Jobs: " << pendingJobs() << "\n";
        status << "Last Error: " << lastErrorDetails;
        return status.str();
    }

    std::string print() {
        if (jobQueue.empty()) {
            lastErrorDetails = "No jobs to print";
            throw std::logic_error("No jobs to print");
        }

        std::string job = jobQueue.front();
        jobQueue.pop();
        return job;
    }

    std::string lastError() {
        return lastErrorDetails;
    }
};
