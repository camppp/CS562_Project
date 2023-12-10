#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache {
private:
    int capacity;
    std::list<int> lruList;
    std::unordered_map<int, std::list<int>::iterator> keyMap;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    void refer(int key) {
        if (keyMap.find(key) != keyMap.end()) {
            // Key already exists, move it to the front of the LRU list
            lruList.splice(lruList.begin(), lruList, keyMap[key]);
        } else {
            // Key does not exist, add it to the LRU list
            lruList.push_front(key);
            keyMap[key] = lruList.begin();
        }

        // Evict the least recently used item if the cache is full
        if (lruList.size() > capacity) {
            int evictedKey = lruList.back();
            lruList.pop_back();
            keyMap.erase(evictedKey);
        }
    }

    void display() {
        for (auto it = lruList.begin(); it != lruList.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
};
