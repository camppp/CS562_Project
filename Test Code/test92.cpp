#include <iostream>
#include <atomic>

enum MessageType {
    kTestChainTrade,
    kTestWpingRequest
};

static uint64_t af_recv_start_time = 0;
static std::atomic<uint32_t> af_recv_count(0);

std::pair<uint32_t, uint64_t> trackMessageCount(MessageType type) {
    if (type == kTestChainTrade || type == kTestWpingRequest) {
        if (af_recv_start_time == 0) {
            af_recv_start_time = GetCurrentTimeMsec();
        }
        af_recv_count++;
    }
    uint64_t time_elapsed = (af_recv_start_time != 0) ? GetCurrentTimeMsec() - af_recv_start_time : 0;
    return std::make_pair(af_recv_count, time_elapsed);
}
