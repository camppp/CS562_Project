#include <iostream>
#include <string>
#include <unordered_set>

std::string generateRoomID(const std::string& prefix, std::unordered_set<std::string>& usedRoomIDs) {
    std::string id;
    do {
        id = prefix + std::to_string(std::rand() % 10000);
    } while (usedRoomIDs.count(id) > 0);
    usedRoomIDs.insert(id);
    return id;
}

int main() {
    std::unordered_set<std::string> usedRoomIDs;

    // Generate and print 5 unique room IDs with the prefix "ROOM-"
    for (int i = 0; i < 5; ++i) {
        std::string roomID = generateRoomID("ROOM-", usedRoomIDs);
        std::cout << "Generated Room ID: " << roomID << std::endl;
    }

    return 0;
}
