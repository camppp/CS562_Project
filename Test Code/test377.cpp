#include <iostream>
#include <thread>

// Define the thread function signature
typedef void (*ThreadFunction)(void*);

// Structure to hold thread arguments
struct ThreadArgs {
    std::thread* currentThread;
    ThreadFunction func;
    void* args;
};

// Class to manage threads
class ThreadManager {
public:
    // Create a new thread with the specified function
    void createThread(ThreadFunction func, void* args) {
        ThreadArgs threadArgs;
        threadArgs.func = func;
        threadArgs.args = args;
        threads.push_back(threadArgs);
    }

    // Start the execution of the created thread
    void startThread() {
        if (!threads.empty()) {
            ThreadArgs& threadArgs = threads.back();
            threadArgs.currentThread = new std::thread(&ThreadManager::executeThread, this, &threadArgs);
        }
    }

    // Wait for the thread to finish its execution
    void joinThread() {
        if (!threads.empty()) {
            ThreadArgs& threadArgs = threads.back();
            if (threadArgs.currentThread->joinable()) {
                threadArgs.currentThread->join();
            }
            delete threadArgs.currentThread;
            threads.pop_back();
        }
    }

private:
    std::vector<ThreadArgs> threads;

    // Function to execute the thread
    void executeThread(ThreadArgs* threadArgs) {
        threadArgs->func(threadArgs->args);
    }
};

// Example function to be executed by the thread
void exampleFunction(void* args) {
    int* value = static_cast<int*>(args);
    std::cout << "Thread executing with value: " << *value << std::endl;
}

int main() {
    ThreadManager threadManager;

    int value = 42;
    threadManager.createThread(exampleFunction, &value);
    threadManager.startThread();
    threadManager.joinThread();

    return 0;
}
