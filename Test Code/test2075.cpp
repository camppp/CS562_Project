#include <iostream>
#include <vector>

class Observer {
public:
    virtual void Update(const std::string& message) = 0;
};

class ObserverList {
private:
    std::vector<Observer*> observers_;

public:
    void AddObserver(Observer* observer) {
        observers_.push_back(observer);
    }

    void RemoveObserver(Observer* observer) {
        observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
    }

    int GetObserverCount() {
        return observers_.size();
    }

    Observer* GetObserverAt(int index) {
        if (index >= 0 && index < observers_.size()) {
            return observers_[index];
        }
        return nullptr;
    }
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
        for (int i = 0; i < observer_list_.GetObserverCount(); ++i) {
            Observer* observer = observer_list_.GetObserverAt(i);
            if (observer) {
                observer->Update(message);
            }
        }
    }
};

class EmailObserver : public Observer {
public:
    void Update(const std::string& message) override {
        std::cout << "Email notification: " << message << std::endl;
    }
};

class LogObserver : public Observer {
public:
    void Update(const std::string& message) override {
        std::cout << "Log notification: " << message << std::endl;
    }
};

int main() {
    ExtensionWarningService warning_service;
    EmailObserver email_observer;
    LogObserver log_observer;

    warning_service.AddObserver(&email_observer);
    warning_service.AddObserver(&log_observer);

    warning_service.NotifyObservers("Critical security vulnerability detected!");

    warning_service.RemoveObserver(&email_observer);

    warning_service.NotifyObservers("System update available.");

    return 0;
}
