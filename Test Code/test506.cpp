const TrackedSet &ContextGhidra::getTrackedSet(const Address &addr) const {
    auto it = trackedSets.find(addr);
    if (it != trackedSets.end()) {
        return it->second;
    } else {
        return emptySet;
    }
}
