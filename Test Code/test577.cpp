#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

// Observer pattern for handling disconnection events
class Observer {
public:
    virtual void onDisconnect(const std::string& friendName) = 0;
};

class Subject {
    std::vector<Observer*> observers_;
    std::string disconnectEvent_;

public:
    Subject(const std::string& event) : disconnectEvent_(event) {}

    void addObserver(Observer* observer) {
        observers_.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
    }

    void notifyDisconnect(const std::string& friendName) {
        for (auto observer : observers_) {
            observer->onDisconnect(friendName);
        }
    }
};

class FriendList : public Observer {
    std::vector<std::string> friends_;
    Subject* disconnectEvent_;

public:
    FriendList(Subject& disconnectEvent) : disconnectEvent_(&disconnectEvent) {
        disconnectEvent_->addObserver(this);
    }

    void addFriend(const std::string& friendName) {
        friends_.push_back(friendName);
    }

    void removeFriend(const std::string& friendName) {
        friends_.erase(std::remove(friends_.begin(), friends_.end(), friendName), friends_.end());
    }

    void onDisconnect(const std::string& friendName) override {
        removeFriend(friendName);
    }
};

int main() {
    Subject disconnectEvent("goodbye");
    FriendList friendList(disconnectEvent);

    friendList.addFriend("Alice");
    friendList.addFriend("Bob");
    friendList.addFriend("Charlie");

    friendList.removeFriend("Bob");

    // Simulate disconnection event
    disconnectEvent.notifyDisconnect("Alice");

    return 0;
}
