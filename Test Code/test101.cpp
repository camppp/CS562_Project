#include <unordered_map>
#include <string>

// Assuming that the object sizes are stored in a map for each key
std::unordered_map<std::string, std::unordered_map<uint64_t, uint32_t>> objectSizes;

uint32_t get_size_by_time(const std::string& key, uint64_t ts_us, uint32_t subgroup_index, uint32_t shard_index) {
    // Assuming objectSizes is populated with object sizes for each key and timestamp
    if (objectSizes.find(key) != objectSizes.end()) {
        auto& sizeMap = objectSizes[key];
        if (sizeMap.find(ts_us) != sizeMap.end()) {
            return sizeMap[ts_us];
        } else {
            // Handle case when size for the given timestamp is not found
            // This could involve interpolation or returning a default value
            return 0; // Default value for size not found
        }
    } else {
        // Handle case when key is not found
        return 0; // Default value for key not found
    }
}
