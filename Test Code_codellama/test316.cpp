#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>

class Test1 {
public:
  Test1() { std::cout << "Test1()\n"; }
  Test1(const Test1&) { std::cout << "Test1(const Test1&)\n"; }
  ~Test1() { std::cout << "~Test1()\n"; }
  void operator()(int a) {
    std::cout << "["
         << std::this_thread::get_id()
         << "] func1(" << a << ")\n";
  }
};

class ThreadSafeQueue {
public:
  void push(const Test1& item) {
    std::unique_lock<std::mutex> lock(mutex_);
    queue_.push(item);
    lock.unlock();
    condition_.notify_one();
  }

  void pop() {
    std::unique_lock<std::mutex> lock(mutex_);
    condition_.wait(lock, [this] { return !queue_.empty(); });
    queue_.pop();
  }

  bool empty() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return queue_.empty();
  }

private:
  std::queue<Test1> queue_;
  mutable std::mutex mutex_;
  std::condition_variable condition_;
};
