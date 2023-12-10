#include <iostream>
#include <thread>
#include <mutex>

void MultiThreadsEvaluation(bool useOptimized) {
  // Define a mutex to synchronize access to the shared data
  std::mutex mtx;

  // Define a vector to store the results of each thread
  std::vector<double> results;

  // Define a function to perform the evaluation
  auto evaluate = [&](int thread_id) {
    // Acquire the lock on the mutex
    std::lock_guard<std::mutex> lock(mtx);

    // Perform the evaluation
    double result = 0;
    if (useOptimized) {
      // Use the optimized evaluation algorithm
      result = optimizedEvaluation(thread_id);
    } else {
      // Use the standard evaluation algorithm
      result = standardEvaluation(thread_id);
    }

    // Add the result to the vector
    results.push_back(result);
  };

  // Create a vector of threads
  std::vector<std::thread> threads;

  // Create a thread for each CPU core
  for (int i = 0; i < std::thread::hardware_concurrency(); i++) {
    // Create a thread with the evaluate function
    threads.push_back(std::thread(evaluate, i));
  }

  // Join the threads
  for (auto& thread : threads) {
    thread.join();
  }

  // Print the results
  for (auto result : results) {
    std::cout << result << std::endl;
  }
}
