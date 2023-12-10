#include <cstdint>

class GLES_Vertex_Buffer {
private:
    bool m_isLocked;
    uint8_t* m_lockedBuffer;

public:
    GLES_Vertex_Buffer() : m_isLocked(false), m_lockedBuffer(nullptr) {}

    bool is_locked_for_reading() {
        return m_isLocked;
    }

    uint8_t const* lock_for_reading() {
        if (!m_isLocked) {
            // Simulating the locking process
            m_isLocked = true;
            m_lockedBuffer = new uint8_t[/* buffer size */];  // Replace with actual buffer size
            return m_lockedBuffer;
        } else {
            // Buffer is already locked
            return nullptr;
        }
    }

    void unlock_for_reading() {
        if (m_isLocked) {
            // Simulating the unlocking process
            m_isLocked = false;
            delete[] m_lockedBuffer;
            m_lockedBuffer = nullptr;
        }
    }

    ~GLES_Vertex_Buffer() {
        if (m_isLocked) {
            // Ensure buffer is unlocked before destruction
            unlock_for_reading();
        }
    }
};
