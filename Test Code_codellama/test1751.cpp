#include <iostream>
#include <map>
#include <mutex>
#include <string>

class BBNamingContextServer {
 public:
  void bind(const std::string& name, const ObjectReference& objectRef) {
    std::lock_guard<std::mutex> lock(mutex_);
    nameToObjectRef_[name] = objectRef;
  }

  void unbind(const std::string& name) {
    std::lock_guard<std::mutex> lock(mutex_);
    nameToObjectRef_.erase(name);
  }

  ObjectReference resolve(const std::string& name) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = nameToObjectRef_.find(name);
    if (it != nameToObjectRef_.end()) {
      return it->second;
    } else {
      return ObjectReference();
    }
  }

 private:
  std::map<std::string, ObjectReference> nameToObjectRef_;
  std::mutex mutex_;
};
