#include <cstdint>

class GLES_Vertex_Buffer {
public:
    GLES_Vertex_Buffer(uint8_t* buffer, size_t size) : buffer_(buffer), size_(size) {}

    bool is_locked_for_reading() {
        return locked_for_reading_;
    }

    uint8_t const* lock_for_reading() {
        if (locked_for_reading_) {
            return nullptr;
        }

        locked_for_reading_ = true;
        return buffer_;
    }

    void unlock_for_reading() {
        if (!locked_for_reading_) {
            return;
        }

        locked_for_reading_ = false;
    }

private:
    uint8_t* buffer_;
    size_t size_;
    bool locked_for_reading_ = false;
};
