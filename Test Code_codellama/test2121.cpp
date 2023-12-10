#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Define a struct to represent a job
struct Job {
    int id;
    string data;
};

// Define a struct to represent a worker node
struct Worker {
    int id;
    string ip;
};

// Define a vector to store the jobs
vector<Job> evalPool;

// Define a vector to store the worker nodes
vector<Worker> workers;

// Define a function to distribute jobs to worker nodes
void distributeJobs() {
    // Iterate through the remaining jobs in the evalPool
    for (int i = 0; i < evalPool.size(); i++) {
        // Get the current job
        Job job = evalPool[i];

        // Find the worker node with the least number of jobs
        int minWorkerId = -1;
        int minNumJobs = INT_MAX;
        for (int j = 0; j < workers.size(); j++) {
            if (workers[j].numJobs < minNumJobs) {
                minWorkerId = workers[j].id;
                minNumJobs = workers[j].numJobs;
            }
        }

        // Assign the job to the worker node with the least number of jobs
        workers[minWorkerId].numJobs++;
        workers[minWorkerId].jobs.push_back(job);
    }
}

int main() {
    // Initialize the evalPool and workers
    evalPool = {
        {1, "job1"},
        {2, "job2"},
        {3, "job3"},
        {4, "job4"},
        {5, "job5"}
    };
    workers = {
        {1, "192.168.1.1"},
        {2, "192.168.1.2"},
        {3, "192.168.1.3"},
        {4, "192.168.1.4"},
        {5, "192.168.1.5"}
    };

    // Distribute the jobs to the worker nodes
    distributeJobs();

    // Print the jobs assigned to each worker node
    for (int i = 0; i < workers.size(); i++) {
        cout << "Worker " << workers[i].id << " has " << workers[i].numJobs << " jobs: ";
        for (int j = 0; j < workers[i].jobs.size(); j++) {
            cout << workers[i].jobs[j].id << " ";
        }
        cout << endl;
    }

    return 0;
}
