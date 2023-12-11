#include <mutex>
#include <set>

class IdManager {
public:
    using id_type = int; // Define the type for IDs

    id_type acquireId() {
        std::lock_guard<std::mutex> lock(protect_);
        if (freeIds_.empty()) {
            increment_++;
            return increment_;
        }
        id_type id = *freeIds_.begin();
        freeIds_.erase(id);
        return id;
    }

    void freeId(id_type id) {
        std::lock_guard<std::mutex> lock(protect_);
        freeIds_.insert(id);
    }

    std::size_t usedIdCount() const {
        std::lock_guard<std::mutex> lock(protect_);
        return freeIds_.size();
    }

private:
    std::mutex protect_; // Mutex to ensure thread safety
    std::set<id_type> freeIds_; // Set to store the free IDs
    id_type increment_ = 1; // Initial value for the next ID
};
