#include <mutex>
#include <vector>

class LegoI2C {
private:
    std::vector<uint8_t> m_rx_buff;
    std::mutex m_rx_mutex;

public:
    void write(uint8_t data) {
        std::lock_guard<std::mutex> guard(m_rx_mutex);
        m_rx_buff.push_back(data);
    }

    uint8_t read() {
        std::lock_guard<std::mutex> guard(m_rx_mutex);
        if (m_rx_buff.empty()) {
            // Handle empty buffer, e.g., throw an exception or return a default value
            return 0;
        }
        uint8_t data = m_rx_buff.front();
        m_rx_buff.erase(m_rx_buff.begin());
        return data;
    }
};
