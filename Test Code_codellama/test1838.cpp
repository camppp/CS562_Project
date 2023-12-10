#include <iostream>
#include <cstdint>

namespace duckdb {
    const uint64_t VERSION_NUMBER = 31;

    uint64_t incrementVersion(uint64_t currentVersion) {
        return currentVersion + 1;
    }
}
