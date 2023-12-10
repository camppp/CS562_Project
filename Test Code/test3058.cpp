void unlock(int k, vector<vector<int>>& rooms, vector<int>& locked) {
    if (locked[k] == 0) {
        return;  // Room is already unlocked
    }
    locked[k] = 0;  // Unlock the current room

    for (int i = 0; i < rooms[k].size(); ++i) {
        unlock(rooms[k][i], rooms, locked);  // Recursively unlock rooms accessible from the current room
    }
}
