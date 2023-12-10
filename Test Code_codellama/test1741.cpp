void processTransactionTags(int tag, bool tx, std::vector<std::string>& tags) {
    if (tag & MC_MTX_TAG_ASSET_TRANSFER) {
        if (tag & MC_MTX_TAG_LICENSE_TOKEN) {
            tags.push_back(tx ? "transfer-license" : "license");
        } else {
            tags.push_back(tx ? "transfer-asset" : "asset");
        }
    } else if (tag & MC_MTX_TAG_MULTIPLE_ASSETS) {
        // Additional processing for multiple assets
    }
}
