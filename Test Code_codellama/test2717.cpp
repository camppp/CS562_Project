class MemoryCache {
public:
    MemoryCache(int size) : size_(size) {}

    Memory obtain() {
        if (cache_.empty()) {
            return Memory();
        }
        return cache_.front();
    }

    void evict(int n) {
        if (n > cache_.size()) {
            cache_.clear();
        } else {
            for (int i = 0; i < n; i++) {
                cache_.pop_front();
            }
        }
    }

private:
    int size_;
    std::deque<Memory> cache_;
};
