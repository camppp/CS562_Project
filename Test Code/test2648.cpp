void User::removeFromFriends() {
    for (auto& friendId : friends) {
        User* friendUser = getUser(friendId);
        if (friendUser != nullptr) {
            friendUser->removeFriend(uuid);
        }
    }
}
