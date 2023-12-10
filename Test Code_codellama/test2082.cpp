std::vector<Material> filterStaticProps(const std::vector<Material>& materials) {
    std::vector<Material> filteredMaterials;
    for (const Material& material : materials) {
        if (std::string(material.getTextureGroupName()).find("StaticProp") == std::string::npos) {
            filteredMaterials.push_back(material);
        }
    }
    return filteredMaterials;
}
