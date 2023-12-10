#include <list>
#include <unordered_map>
#include <iostream>

class LRUCache {
private:
    int capacity;
    std::list<int> lruList;
    std::unordered_map<int, std::list<int>::iterator> cacheMap;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    void refer(int key) {
        if (cacheMap.find(key) != cacheMap.end()) {
            lruList.erase(cacheMap[key]);
            cacheMap.erase(key);
        } else if (lruList.size() >= capacity) {
            int leastRecent = lruList.back();
            lruList.pop_back();
            cacheMap.erase(leastRecent);
        }
        lruList.push_front(key);
        cacheMap[key] = lruList.begin();
    }

    void display() {
        for (auto it = lruList.begin(); it != lruList.end(); ++it) {
            std::cout << *it << " ";
        }
    }
};
