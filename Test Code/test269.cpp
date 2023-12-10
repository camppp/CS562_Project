#include <vector>
#include <memory>

// Define the modernized Cable class
class Cable {
public:
    // Define the cable segment type
    using SegmentPtr = std::shared_ptr<CableSegment>;

    // Constructor and other member functions can be added as per requirements

    // Return a pointer to a cable segment given an index
    SegmentPtr getSegment(index_type index) const {
        if (index >= 0 && index < segments_.size()) {
            return segments_[index];
        } else {
            return nullptr; // Index is not valid, return null pointer
        }
    }

    // Return a vector of segment pointers
    std::vector<SegmentPtr> getAllSegments() const {
        return segments_;
    }

private:
    std::vector<SegmentPtr> segments_;
};

// Define the cable segment class
class CableSegment {
    // Define the cable segment properties and methods
};

// Usage example
int main() {
    Cable cable;
    // Populate cable segments
    // ...

    // Access cable segments using modernized member functions
    Cable::SegmentPtr segment = cable.getSegment(2);
    if (segment) {
        // Valid segment, perform operations
    } else {
        // Invalid index, handle accordingly
    }

    std::vector<Cable::SegmentPtr> allSegments = cable.getAllSegments();
    // Process all segments
    return 0;
}
