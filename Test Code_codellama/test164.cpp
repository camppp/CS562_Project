int processItems(const std::vector<Item>& items) {
    int validIconCount = 0;
    for (const auto& item : items) {
        if (item.isIconLoaded && item.isIconValid) {
            validIconCount++;
        }
    }
    return validIconCount;
}
