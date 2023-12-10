#include <iostream>
#include <string>

class AssetManager {
private:
    std::string asset_name;

public:
    void set_asset_name(const std::string& parent_name) {
        asset_name = parent_name;
    }

    const std::string& get_asset_name() const {
        return asset_name;
    }
};

int main() {
    AssetManager asset;
    std::string parent_name = "parent_asset";
    asset.set_asset_name(parent_name);
    std::cout << "Asset name set to: " << asset.get_asset_name() << std::endl;
    return 0;
}
