void unlock(int k, vector<vector<int>>& rooms, vector<int>& locked) {
    queue<int> q;
    q.push(k);
    while (!q.empty()) {
        int room = q.front();
        q.pop();
        if (locked[room] == 1) {
            locked[room] = 0;
            for (int key : rooms[room]) {
                if (locked[key] == 1) {
                    q.push(key);
                }
            }
        }
    }
}
