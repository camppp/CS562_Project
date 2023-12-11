#include <string>
#include <unordered_map>

// Assume this function is provided by the database
uint32_t get_size_from_db(const std::string& key, uint64_t ts_us);

uint32_t get_size_by_time(const std::string& key, uint64_t ts_us, uint32_t subgroup_index, uint32_t shard_index) {
    // Here you would need to implement logic to determine the correct shard and subgroup index
    // based on the provided parameters. This could involve a hash function or some other logic.
    // For the purpose of this example, we'll just return the size from the database.

    return get_size_from_db(key, ts_us);
}