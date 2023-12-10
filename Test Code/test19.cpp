void Ask::populateNPF(const json& entry) {
    // Parse the "blocks" field of the JSON object
    const auto& blocks = entry["blocks"];

    // Iterate over the blocks and populate the data structure
    for (const auto& block : blocks) {
        // Extract the information from the block
        const auto& block_id = block["id"];
        const auto& block_name = block["name"];
        const auto& block_type = block["type"];

        // Populate the data structure with the information
        data_structure.push_back({block_id, block_name, block_type});
    }
}
