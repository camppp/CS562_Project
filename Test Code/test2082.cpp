std::vector<Material> filterStaticProps(const std::vector<Material>& materials) {
    std::vector<Material> filteredMaterials;
    for (const auto& material : materials) {
        if (strstr(material.getTextureGroupName(), "StaticProp") == nullptr) {
            filteredMaterials.push_back(material);
        }
    }
    return filteredMaterials;
}
