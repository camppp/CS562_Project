void updateRenderingSettings(const nlohmann::json& json, float& farClippingPlane, std::string& skyboxPath, Rendering::Skybox& skybox)
{
    // Parse the JSON object and extract the relevant fields
    auto farClippingPlaneValue = json["farClippingPlane"].get<float>();
    auto skyboxPathValue = json["skybox"].get<std::string>();

    // Update the far clipping plane
    farClippingPlane = farClippingPlaneValue;

    // Update the skybox path
    skyboxPath = skyboxPathValue;

    // Load the new skybox texture if the path has changed
    if (skyboxPath != skybox.getPath())
    {
        skybox.load(skyboxPath);
    }
}
