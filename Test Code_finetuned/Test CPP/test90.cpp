#include <atomic>
#include <chrono>

enum class MessageType { kTestChainTrade, kTestWpingRequest };

static std::atomic<uint64_t> af_recv_start_time(0);
static std::atomic<uint32_t> af_recv_count(0);

std::pair<uint32_t, uint64_t> trackMessageCount(MessageType type) {
    if (type == MessageType::kTestChainTrade || type == MessageType::kTestWpingRequest) {
        if (af_recv_start_time == 0) {
            af_recv_start_time = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()
            ).count();
        }
        af_recv_count++;
    }
    return std::make_pair(af_recv_count, af_recv_start_time);
}