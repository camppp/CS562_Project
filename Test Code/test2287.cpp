#include <queue>
#include <mutex>
#include <condition_variable>

class MessageQueue {
public:
  void EnqueueWorkItem(WorkItem item) {
    std::unique_lock<std::mutex> lock(mutex_);
    queue_.push(item);
    work_scheduled_ = true;
    condition_.notify_one();
  }

  WorkItem DequeueWorkItem() {
    std::unique_lock<std::mutex> lock(mutex_);
    condition_.wait(lock, [this] { return !queue_.empty() || !in_native_loop_; });

    if (!queue_.empty()) {
      WorkItem item = queue_.front();
      queue_.pop();
      return item;
    }

    return nullptr;
  }

  void ExecuteWorkItem(WorkItem item) {
    if (item) {
      item->Execute();
    }
  }

  void SetInNativeLoop(bool inLoop) {
    std::lock_guard<std::mutex> lock(mutex_);
    in_native_loop_ = inLoop;
  }

  void HandleWorkScheduling() {
    std::lock_guard<std::mutex> lock(mutex_);
    work_scheduled_ = false;
  }

private:
  std::queue<WorkItem> queue_;
  std::mutex mutex_;
  std::condition_variable condition_;
  bool in_native_loop_ = false;
  bool work_scheduled_ = false;
};
