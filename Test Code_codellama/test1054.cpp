class AssetManager {
public:
    void set_asset_name(const std::string& parent_name) {
        // Set the asset name for the current asset object to the provided parent asset name
        asset_name = parent_name;
    }

private:
    std::string asset_name;
};
