#include <iostream>
#include <vector>

// Observer interface or base class
class Observer {
public:
    virtual void WorkAreaChanged() = 0;
};

// Subject class that maintains a collection of observers and notifies them when its state changes
class Subject {
public:
    void Attach(Observer* observer) {
        observers.push_back(observer);
    }

    void Detach(Observer* observer) {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void Notify() {
        FOR_EACH_OBSERVER(WorkAreaChanged);
    }

private:
    std::vector<Observer*> observers;
};

// Concrete observer classes that implement the Observer interface or inherit from the base class
class WorkAreaObserver : public Observer {
public:
    void WorkAreaChanged() override {
        std::cout << "Work area changed!" << std::endl;
    }
};

class StatusBarObserver : public Observer {
public:
    void WorkAreaChanged() override {
        std::cout << "Status bar updated!" << std::endl;
    }
};

int main() {
    Subject subject;
    WorkAreaObserver workAreaObserver;
    StatusBarObserver statusBarObserver;

    subject.Attach(&workAreaObserver);
    subject.Attach(&statusBarObserver);

    // Notify observers when the subject's state changes
    subject.Notify();

    return 0;
}
