#include <functional>
#include <vector>

class CallbackManager {
public:
  // Registers a callback function.
  void RegisterCallback(std::function<void()> callback) {
    callbacks_.push_back(callback);
  }

  // Invokes all registered callback functions.
  void InvokeCallbacks() {
    for (const auto& callback : callbacks_) {
      callback();
    }
  }
  
private:
  std::vector<std::function<void()>> callbacks_;
};
