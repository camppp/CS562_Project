#include <chrono>
#include <cassert>

#define TIMING_ASSERT(time_point, message) \
do { \
    auto current_time = std::chrono::high_resolution_clock::now(); \
    if (!(current_time >= time_point)) { \
        assert(false && message); \
    } \
} while (0)
