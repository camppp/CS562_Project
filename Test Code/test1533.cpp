#include <iostream>
#include <stack>
#include <unordered_map>

class ThreadGeneration {
public:
    using NameType = std::string;
    using IdType = std::pair<NameType, int>;

    ThreadGeneration() : cur_max_id(0) {}

    IdType generate() {
        IdType id;
        if (trash_bin.empty()) {
            id.second = cur_max_id++;
        } else {
            id.second = trash_bin.top();
            trash_bin.pop();
        }
        return id;
    }

    void finalize(const NameType& name) {
        // Mark the thread name as no longer in use
        // For example, perform any necessary cleanup or bookkeeping
        std::cout << "Finalizing thread name: " << name << std::endl;
    }

private:
    int cur_max_id;
    std::stack<int> trash_bin;
};

int main() {
    ThreadGeneration threadManager;
    ThreadGeneration::IdType threadId1 = threadManager.generate();
    ThreadGeneration::IdType threadId2 = threadManager.generate();

    std::cout << "Generated thread ID 1: " << threadId1.second << std::endl;
    std::cout << "Generated thread ID 2: " << threadId2.second << std::endl;

    threadManager.finalize(threadId1.first);
    threadManager.finalize(threadId2.first);

    return 0;
}
