class StreamManager {
public:
    StreamManager(int num_streams) {
        // Initialize the data structures for managing the streams
        streams_ = new int[num_streams];
        pending_items_ = new int[num_streams];
        for (int i = 0; i < num_streams; i++) {
            streams_[i] = -1;
            pending_items_[i] = -1;
        }
    }

    ~StreamManager() {
        delete[] streams_;
        delete[] pending_items_;
    }

    int acquire(int max_streams) {
        // Find the first available stream
        for (int i = 0; i < max_streams; i++) {
            if (streams_[i] == -1) {
                return i;
            }
        }
        return -1;
    }

    bool get_pending_and_release(int index, int& item) {
        // Check if there is a pending item in the stream
        if (pending_items_[index] != -1) {
            item = pending_items_[index];
            pending_items_[index] = -1;
            return true;
        }
        return false;
    }

    void release(int index) {
        // Make the released stream available for acquisition again
        streams_[index] = -1;
    }

private:
    int* streams_;
    int* pending_items_;
};
