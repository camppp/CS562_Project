#include <iostream>
#include <cstdint>

namespace duckdb {
    const uint64_t VERSION_NUMBER = 31;

    uint64_t incrementVersion(uint64_t currentVersion) {
        return currentVersion + 1;
    }
}

int main() {
    uint64_t currentVersion = duckdb::VERSION_NUMBER;
    uint64_t updatedVersion = duckdb::incrementVersion(currentVersion);
    std::cout << "Updated version number: " << updatedVersion << std::endl;
    return 0;
}
