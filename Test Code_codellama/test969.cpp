#include <chrono>
#include <cassert>

#define TIMING_ASSERT(tp, msg) \
    ASSERT(std::chrono::high_resolution_clock::now() >= tp) << msg
