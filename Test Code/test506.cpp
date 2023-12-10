const TrackedSet &ContextGhidra::getTrackedSet(const Address &addr) const {
    // Assuming trackedSets is a map that stores the tracked sets for each address
    auto it = trackedSets.find(addr);
    if (it != trackedSets.end()) {
        return it->second;
    } else {
        // Return an empty set if the address is not tracked
        static const TrackedSet emptySet;
        return emptySet;
    }
}
