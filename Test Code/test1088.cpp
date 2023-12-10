bool isInstanceIdUsable(int instance, std::unordered_set<int>* seen_instance_ids, bool* usable) {
  // Check if the instance ID is already in the set of seen instance IDs
  if (seen_instance_ids->find(instance) != seen_instance_ids->end()) {
    // Instance ID already seen, reject it.
    *usable = false;
  } else {
    // This instance ID is new, mark it as seen and return that it's usable
    seen_instance_ids->insert(instance);
    *usable = true;
  }
  return *usable;
}
