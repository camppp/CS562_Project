#include <cstdint>
#include <cstring>

class CircularBuffer : public Reader, public Writer {
  static const uint32_t BUFFER_SIZE = 1024;
  uint32_t last_sender_id_;
  uint32_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[BUFFER_SIZE];

public:
  CircularBuffer() : last_sender_id_(), n_callbacks_logged_(), dummy_wr_(), dummy_rd_(), dummy_buff_() {
    set_reader(this);
    set_writer(this);
  }

  s32 read(uint8_t *buf, const uint32_t n) override {
    uint32_t real_n = n;
    memcpy(buf, dummy_buff_ + dummy_rd_, real_n);
    // Your implementation here
  }

  void write(const uint8_t *buf, const uint32_t n) {
    if (n <= BUFFER_SIZE) {
      if (dummy_wr_ + n <= BUFFER_SIZE) {
        memcpy(dummy_buff_ + dummy_wr_, buf, n);
        dummy_wr_ = (dummy_wr_ + n) % BUFFER_SIZE;
      } else {
        uint32_t first_chunk = BUFFER_SIZE - dummy_wr_;
        memcpy(dummy_buff_ + dummy_wr_, buf, first_chunk);
        memcpy(dummy_buff_, buf + first_chunk, n - first_chunk);
        dummy_wr_ = n - first_chunk;
      }
    } else {
      // Handle error: buffer size exceeded
    }
  }

  bool is_full() {
    return (dummy_wr_ + 1) % BUFFER_SIZE == dummy_rd_;
  }

  bool is_empty() {
    return dummy_wr_ == dummy_rd_;
  }
};
