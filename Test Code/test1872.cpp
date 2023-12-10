void updateRenderingSettings(const nlohmann::json& json, float& farClippingPlane, std::string& skyboxPath, Rendering::Skybox& skybox) {
    // Update far clipping plane
    if (json.find("farClippingPlane") != json.end()) {
        farClippingPlane = json["farClippingPlane"];
    }

    // Update skybox
    if (json.find("skybox") != json.end()) {
        const std::string newSkyVal = json["skybox"];
        if (newSkyVal != skyboxPath) {
            skybox = Rendering::RenderManager::getSkybox(newSkyVal);
            skyboxPath = newSkyVal;
        }
    }
}
