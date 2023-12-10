void Ask::populateNPF(JSON_OBJECT entry) {
    // Extract the "blocks" array from the JSON object
    JSON_ARRAY blocksArray = entry["blocks"].GetArray();

    // Iterate through the "blocks" array and populate the data structure
    for (const auto& block : blocksArray) {
        // Extract information from the current block JSON object and populate the data structure
        populateBlocks(block);
    }
}

void Ask::populateBlocks(JSON_OBJECT block) {
    // Populate the data structure with information from the current block JSON object
    // Implementation specific to the data structure population from the block JSON object
    // ...
}
