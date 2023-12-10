#include <iostream>
#include <functional>
#include <unordered_map>
#include <vector>

class MyReceiver {
private:
  int calls;
  std::unordered_map<std::string, std::vector<std::function<void(std::string)>>> eventHandlers;

public:
  MyReceiver() : calls(0) {}

  virtual ~MyReceiver() {}

  // Subscribe event handler to a specific event
  void subscribe(const std::string& event, std::function<void(std::string)> handler) {
    eventHandlers[event].push_back(handler);
  }

  // Unsubscribe event handler from a specific event
  void unsubscribe(const std::string& event, std::function<void(std::string)> handler) {
    auto it = eventHandlers.find(event);
    if (it != eventHandlers.end()) {
      it->second.erase(std::remove(it->second.begin(), it->second.end(), handler), it->second.end());
    }
  }

  // Dispatch event to the appropriate event handlers
  void dispatch(const std::string& event, const std::string& arg) {
    auto it = eventHandlers.find(event);
    if (it != eventHandlers.end()) {
      for (const auto& handler : it->second) {
        handler(arg);
      }
    }
  }

  // Event handler method
  virtual void mySlot(std::string arg) {
    // ASSERT(this == check);
    ++calls;
  }

  void selfDelete(std::string arg) {
    // Implement selfDelete method
  }
};

int main() {
  MyReceiver receiver;

  // Subscribe event handlers
  receiver.subscribe("event1", [](std::string arg) {
    std::cout << "Event 1 handled with arg: " << arg << std::endl;
  });

  receiver.subscribe("event2", [](std::string arg) {
    std::cout << "Event 2 handled with arg: " << arg << std::endl;
  });

  // Dispatch events
  receiver.dispatch("event1", "Event1Arg1");
  receiver.dispatch("event2", "Event2Arg1");
  receiver.dispatch("event1", "Event1Arg2");

  return 0;
}
