#include <iostream>
#include <vector>

struct Item {
    int32_t x, y;
    char ext[4];
    uint32_t off;
    bool isDir, isIconLoaded, isIconValid;

    void setOffset(uint32_t off) {
        if (off == this->off)
            return;

        isDir = false;
    }
};

int processItems(const std::vector<Item>& items) {
    int validIconCount = 0;
    for (const auto& item : items) {
        item.setOffset(item.off);
        if (item.isIconLoaded && item.isIconValid) {
            validIconCount++;
        }
    }
    return validIconCount;
}

int main() {
    // Example usage
    std::vector<Item> items = {/* Populate with items */};
    int validIcons = processItems(items);
    std::cout << "Valid Icons Count: " << validIcons << std::endl;
    return 0;
}
