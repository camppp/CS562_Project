class DeviceNamePolicyHandler {
public:
  DeviceNamePolicyHandler() = default;

  ~DeviceNamePolicyHandler() = default;

  void AddObserver(Observer* observer) {
    observers_.push_back(observer);
  }

  void RemoveObserver(Observer* observer) {
    auto it = std::find(observers_.begin(), observers_.end(), observer);
    if (it != observers_.end()) {
      observers_.erase(it);
    }
  }

  void NotifyObservers() {
    for (auto& observer : observers_) {
      observer->OnDeviceNamePolicyChanged();
    }
  }

private:
  std::vector<Observer*> observers_;
};
