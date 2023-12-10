bool isInstanceIdUsable(int instance, std::unordered_set<int>* seen_instance_ids, bool* usable) {
    // Check if the instance ID has already been seen
    if (seen_instance_ids->find(instance) != seen_instance_ids->end()) {
        // Instance ID already seen, reject it
        *usable = false;
        return false;
    }

    // This instance ID is new, so mark it as seen and return that it's usable
    seen_instance_ids->insert(instance);
    *usable = true;
    return true;
}
