class ThreadGeneration {
public:
    ThreadGeneration() : cur_max_id(0) {}

    string generate() {
        string name;
        if (!trash_bin.empty()) {
            name = trash_bin.top();
            trash_bin.pop();
        } else {
            name = "Thread" + to_string(++cur_max_id);
        }
        return name;
    }

    void finalize(string name) {
        trash_bin.push(name);
    }

private:
    int cur_max_id;
    stack<string> trash_bin;
};
