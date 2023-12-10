#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

// Define the JobTrans struct
struct JobTrans {
    int id;
    std::string name;
    std::string desc;
};

// Define the Manager class
class Manager {
public:
    // Constructor
    Manager() {
        m_trans_queue = new std::queue<JobTrans>;
    }

    // Destructor
    ~Manager() {
        delete m_trans_queue;
    }

    // Add a job transaction to the queue
    void add_trans(JobTrans trans) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_trans_queue->push(trans);
    }

    // Retrieve a job transaction from the queue
    JobTrans pop_trans() {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_trans_queue->pop();
    }

private:
    // The transaction queue
    std::queue<JobTrans>* m_trans_queue;

    // The mutex for protecting the transaction queue
    std::mutex m_mutex;
};

// Define the worker task
class WorkerTask {
public:
    // Constructor
    WorkerTask(Manager* manager) {
        m_manager = manager;
    }

    // Destructor
    ~WorkerTask() {
    }

    // Process a job transaction
    void process_trans(JobTrans trans) {
        // Start profiling the task execution time
        PROFILE_START(trans.id);

        // Process the job transaction
        std::cout << "Processing job transaction " << trans.id << "..." << std::endl;

        // Record the time taken for processing
        PROFILE_END(trans.id);
    }

private:
    // The manager object
    Manager* m_manager;
};

int main() {
    // Create a manager object
    Manager manager;

    // Create a worker task
    WorkerTask worker(&manager);

    // Add a job transaction to the queue
    JobTrans trans1 = {1, "Job 1", "Description of job 1"};
    manager.add_trans(trans1);

    // Add another job transaction to the queue
    JobTrans trans2 = {2, "Job 2", "Description of job 2"};
    manager.add_trans(trans2);

    // Retrieve a job transaction from the queue
    JobTrans trans3 = manager.pop_trans();

    // Process the job transaction
    worker.process_trans(trans3);

    // Retrieve another job transaction from the queue
    JobTrans trans4 = manager.pop_trans();

    // Process the job transaction
    worker.process_trans(trans4);

    return 0;
}
