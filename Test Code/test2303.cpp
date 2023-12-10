#include <vector>
#include <algorithm>

class StreamManager {
private:
    std::vector<bool> streamAvailability;
    std::vector<int> pendingItems;

public:
    StreamManager(size_t numStreams) : streamAvailability(numStreams, true), pendingItems(numStreams, -1) {}

    int acquire(size_t maxStreams) {
        auto it = std::find(streamAvailability.begin(), streamAvailability.end(), true);
        if (it != streamAvailability.end()) {
            size_t index = std::distance(streamAvailability.begin(), it);
            streamAvailability[index] = false;
            return static_cast<int>(index);
        }
        return -1;
    }

    bool get_pending_and_release(size_t index, int& item) {
        if (streamAvailability[index]) {
            return false;
        }
        item = pendingItems[index];
        streamAvailability[index] = true;
        pendingItems[index] = -1;
        return true;
    }

    void release(size_t index) {
        streamAvailability[index] = true;
    }
};
