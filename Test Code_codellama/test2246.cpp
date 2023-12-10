class StatusTracker {
public:
    // Predefined statuses
    static const int kStatusIdx = 1;
    static const int kStatusLoaded = 2;
    static const int kStatusResolving = 3;

    // Current status
    int status;

    // Constructor
    StatusTracker() {
        status = kStatusIdx;
    }

    // Set status
    void setStatus(int newStatus) {
        status = newStatus;
    }

    // Get status
    int getStatus() {
        return status;
    }

    // Check if in status
    bool isInStatus(int status) {
        return this->status == status;
    }

    // Reset to default status
    void reset() {
        status = kStatusIdx;
    }
};
