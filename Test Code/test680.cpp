#include <mutex>
#include <set>

class IdManager {
public:
    using id_type = int; // Define the type for IDs

    id_type acquireId() {
        std::lock_guard<std::mutex> lock(protect_); // Lock the mutex
        if (freeIds_.empty()) {
            return increment_++; // If no free IDs, return the next incrementing ID
        } else {
            id_type id = *freeIds_.begin(); // Get the first free ID
            freeIds_.erase(id); // Remove the ID from the free set
            return id;
        }
    }

    void freeId(id_type id) {
        std::lock_guard<std::mutex> lock(protect_); // Lock the mutex
        freeIds_.insert(id); // Add the freed ID to the free set
    }

    std::size_t usedIdCount() const {
        std::lock_guard<std::mutex> lock(protect_); // Lock the mutex
        return increment_ - freeIds_.size(); // Calculate the count of used IDs
    }

private:
    std::mutex protect_; // Mutex to ensure thread safety
    std::set<id_type> freeIds_; // Set to store the free IDs
    id_type increment_ = 1; // Initial value for the next ID
};
