public void assignUniqueId() {
    // Generate a unique ID using a random number between 1 and 1000
    long randomId = (long) (Math.random() * 1000) + 1;

    // Check if the ID is already in use
    while (isIdInUse(randomId)) {
        // If the ID is already in use, generate a new one
        randomId = (long) (Math.random() * 1000) + 1;
    }

    // Assign the unique ID to the msgId field
    msgId = randomId;
}

// Check if the given ID is already in use
private boolean isIdInUse(long id) {
    // Check if the ID is already in the set of used IDs
    return usedIds.contains(id);
}

// Set of used IDs
private Set<Long> usedIds = new HashSet<>();