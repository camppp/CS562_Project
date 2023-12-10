#include <iostream>
#include <vector>

// Observer interface
class Observer {
public:
    virtual void update() = 0;
};

// Subject class
class Subject {
private:
    std::vector<Observer*> observers_;

public:
    void addObserver(Observer* observer) {
        observers_.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        // Implement removal logic if needed
    }

    void notifyObservers() {
        for (auto observer : observers_) {
            observer->update();
        }
    }

    void workAreaChanged() {
        // Perform state change logic
        notifyObservers();
    }
};

// Concrete observer classes
class WorkAreaWatcherXObserver : public Observer {
public:
    void update() override {
        std::cout << "WorkAreaWatcherXObserver notified of work area change" << std::endl;
        // Implement specific update logic for WorkAreaWatcherXObserver
    }
};

int main() {
    Subject subject;
    WorkAreaWatcherXObserver observer1;
    WorkAreaWatcherXObserver observer2;

    subject.addObserver(&observer1);
    subject.addObserver(&observer2);

    // Simulate work area change
    subject.workAreaChanged();

    return 0;
}
