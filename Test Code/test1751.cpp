#include <mutex>
#include <unordered_map>

class BBNamingContextServer {
 public:
  void bind(const std::string& name, const ObjectReference& objectRef) {
    std::lock_guard<std::mutex> lock(mutex_);
    namingMap_[name] = objectRef;
  }

  void unbind(const std::string& name) {
    std::lock_guard<std::mutex> lock(mutex_);
    namingMap_.erase(name);
  }

  ObjectReference resolve(const std::string& name) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = namingMap_.find(name);
    if (it != namingMap_.end()) {
      return it->second;
    } else {
      // Handle not found case, e.g., throw an exception or return a default reference
      return ObjectReference();  // Placeholder for default reference
    }
  }

 private:
  std::mutex mutex_;
  std::unordered_map<std::string, ObjectReference> namingMap_;
};
