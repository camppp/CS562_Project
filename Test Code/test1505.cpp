class CircularBuffer {
public:
    static const uint32_t BUFFER_SIZE = 1024;

    CircularBuffer() : last_sender_id_(0), n_callbacks_logged_(0), dummy_wr_(0), dummy_rd_(0) {
        set_reader(this);
        set_writer(this);
    }

    s32 read(uint8_t *buf, const uint32_t n) override {
        uint32_t real_n = n;
        memcpy(buf, dummy_buff_ + dummy_rd_, real_n);
        // Your implementation here
    }

    void write(const uint8_t *buf, const uint32_t n) {
        if (is_full()) {
            // Overwrite the oldest data
            uint32_t oldest_data_index = (dummy_wr_ + BUFFER_SIZE - 1) % BUFFER_SIZE;
            memcpy(dummy_buff_ + oldest_data_index, buf, n);
        } else {
            // Write the data to the next available index
            uint32_t next_available_index = (dummy_wr_ + n) % BUFFER_SIZE;
            memcpy(dummy_buff_ + next_available_index, buf, n);
        }
        dummy_wr_ = (dummy_wr_ + n) % BUFFER_SIZE;
    }

    bool is_full() {
        return (dummy_wr_ + n_callbacks_logged_) % BUFFER_SIZE == dummy_rd_;
    }

    bool is_empty() {
        return dummy_rd_ == dummy_wr_;
    }

private:
    uint32_t last_sender_id_;
    uint32_t n_callbacks_logged_;
    uint32_t dummy_wr_;
    uint32_t dummy_rd_;
    uint8_t dummy_buff_[BUFFER_SIZE];
};
