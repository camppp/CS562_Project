class ResourcePoolHelper {
public:
    ResourcePoolHelper() {
        // Initialize the pool with a fixed number of objects
        pool.reserve(10);
    }

    AACFrame* obtainObj() {
        // If the pool is empty, create a new object
        if (pool.empty()) {
            return new AACFrame();
        }

        // Otherwise, return a previously used object
        AACFrame* obj = pool.back();
        pool.pop_back();
        return obj;
    }

    void releaseObj(AACFrame* obj) {
        // Add the object to the pool
        pool.push_back(obj);
    }

private:
    std::vector<AACFrame*> pool;
};
