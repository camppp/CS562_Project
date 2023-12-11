#include <iostream>
#include <vector>

class Observer {
public:
    virtual void Update(const std::string& message) = 0;
};

class ObserverList {
public:
    void AddObserver(Observer* observer) {
        observers_.push_back(observer);
    }

    void RemoveObserver(Observer* observer) {
        for (auto it = observers_.begin(); it != observers_.end(); ++it) {
            if (*it == observer) {
                observers_.erase(it);
                break;
            }
        }
    }

    int GetObserverCount() {
        return observers_.size();
    }

    Observer* GetObserverAt(int index) {
        return observers_[index];
    }

private:
    std::vector<Observer*> observers_;
};

class ExtensionWarningService {
private:
    ObserverList observer_list_;

public:
    void AddObserver(Observer* observer) {
        observer_list_.AddObserver(observer);
    }

    void RemoveObserver(Observer* observer) {
        observer_list_.RemoveObserver(observer);
    }

    void NotifyObservers(const std::string& message) {
        for (auto observer : observer_list_.GetObserverAt(0)) {
            observer->Update(message);
        }
    }
};

int main() {
    // Test the implementation
    ExtensionWarningService service;

    // Add an observer
    class MyObserver : public Observer {
    public:
        void Update(const std::string& message) override {
            std::cout << "Received message: " << message << std::endl;
        }
    };
    MyObserver observer;
    service.AddObserver(&observer);

    // Remove the observer
    service.RemoveObserver(&observer);

    // Notify the observers
    service.NotifyObservers("Hello, world!");

    return 0;
}
