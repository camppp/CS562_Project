template <typename TagStore>
class Cache {
public:
    // Constructor
    Cache(size_t capacity) : capacity_(capacity) {}

    // Store data in the cache based on a tag
    void store(const TagStore& tag, const Data& data) {
        // Check if the cache is full
        if (size() >= capacity_) {
            // Evict the oldest item from the cache
            evict();
        }

        // Add the new item to the cache
        cache_.push_back(std::make_pair(tag, data));
    }

    // Retrieve data from the cache based on a tag
    Data retrieve(const TagStore& tag) {
        // Find the item in the cache with the given tag
        auto it = std::find_if(cache_.begin(), cache_.end(),
                               [&](const auto& pair) { return pair.first == tag; });

        // Return the data if found
        if (it != cache_.end()) {
            return it->second;
        }

        // Return an empty data object if not found
        return Data();
    }

    // Maintain a queue of side packets associated with the cache
    typedef std::queue<std::pair<TagStore, Data>> MemSidePacketQueue;
    MemSidePacketQueue side_packets_;

private:
    // Evict the oldest item from the cache
    void evict() {
        // Remove the oldest item from the cache
        cache_.pop_front();
    }

    // Return the size of the cache
    size_t size() {
        return cache_.size();
    }

    // The capacity of the cache
    size_t capacity_;

    // The cache data structure
    std::deque<std::pair<TagStore, Data>> cache_;
};
