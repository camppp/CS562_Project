void removeFromFriends() {
    for (auto& friendId : friends) {
        // Access the friend object and remove this->uuid from its friend list
        // Assuming there is a global unordered_map<std::string, User*> users; that stores all users
        if (users.find(friendId) != users.end()) {
            users[friendId]->removeFriend(this->uuid);
        }
    }
}
