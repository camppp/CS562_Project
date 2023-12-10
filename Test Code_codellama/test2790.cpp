std::string generateRoomID(const std::string& prefix, std::unordered_set<std::string>& usedRoomIDs) {
    std::string id;
    do {
        id = prefix + std::to_string(std::rand() % 10000);
    } while (usedRoomIDs.count(id) > 0);
    usedRoomIDs.insert(id);
    return id;
}
