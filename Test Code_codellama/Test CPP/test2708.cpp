bool PageTable::contains(Page* page) {
    // Acquire the spin lock to ensure thread safety
    spinLock.lock();

    // Calculate the hash code for the given page
    size_t hashCode = page->hashCode();

    // Check if the hash code is present in the hash table
    for (auto& set : hashTable) {
        if (set.find(hashCode) != set.end()) {
            // The page is present in the hash table
            spinLock.unlock();
            return true;
        }
    }

    // The page is not present in the hash table
    spinLock.unlock();
    return false;
}
