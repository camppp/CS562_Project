#include <iostream>
#include <vector>

class Observer {
  // Define the Observer class
};

class DeviceNamePolicyHandler {
public:
  // Constructor and other necessary methods

  ~DeviceNamePolicyHandler() = default;

  void AddObserver(Observer* observer) {
    observers_.push_back(observer);
  }

  void RemoveObserver(Observer* observer) {
    observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
  }

  // Other necessary methods for handling device name policy

  void NotifyObservers() {
    for (Observer* observer : observers_) {
      // Notify each observer about the change in device name policy
    }
  }

private:
  std::vector<Observer*> observers_;
};
