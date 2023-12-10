#include <unordered_map>
#include <string>
#include <iostream>

class BlockData {
public:
    BlockData() {}
    virtual ~BlockData() {}
};

class AssetManager {
public:
    AssetManager() = default;
    AssetManager(const AssetManager&) = delete;
    virtual ~AssetManager() {}

    static void LoadAssets() {
        // Load the necessary assets into the blockDatas map
        blockDatas["block1"] = BlockData();
        blockDatas["block2"] = BlockData();
        blockDatas["block3"] = BlockData();
    }

private:
    static std::unordered_map<std::string, BlockData> blockDatas;
};

std::unordered_map<std::string, BlockData> AssetManager::blockDatas;

int main() {
    AssetManager::LoadAssets();
    return 0;
}
