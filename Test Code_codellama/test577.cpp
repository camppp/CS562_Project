#include <iostream>
#include <vector>
#include <string>

class FriendList {
public:
    // Constructor
    FriendList(std::vector<std::string> friends) {
        this->friends = friends;
    }

    // Add a friend to the friend list
    void addFriend(std::string friendName) {
        this->friends.push_back(friendName);
    }

    // Remove a friend from the friend list
    void removeFriend(std::string friendName) {
        auto it = std::find(this->friends.begin(), this->friends.end(), friendName);
        if (it != this->friends.end()) {
            this->friends.erase(it);
        }
    }

    // Handle disconnection events by notifying observers
    void handleDisconnection(std::string friendName) {
        auto it = std::find(this->friends.begin(), this->friends.end(), friendName);
        if (it != this->friends.end()) {
            this->friends.erase(it);
            std::cout << "Friend " << friendName << " disconnected" << std::endl;
        }
    }

private:
    std::vector<std::string> friends;
};
