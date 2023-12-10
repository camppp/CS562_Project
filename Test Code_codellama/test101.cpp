c
uint32_t get_size_by_time(const std::string& key, uint64_t ts_us, uint32_t subgroup_index, uint32_t shard_index) {
    // Retrieve the object with the given key from the CascadeType
    auto object = CascadeType::get_object(key, subgroup_index, shard_index);

    // Check if the object exists and has a size
    if (object && object.size() > 0) {
        // Retrieve the size of the object at the specified wall clock time
        uint32_t size = object.get_size_at_time(ts_us);

        // Return the size of the object
        return size;
    }

    // If the object does not exist or has no size, return 0
    return 0;
}
