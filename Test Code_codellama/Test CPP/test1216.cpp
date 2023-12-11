std::string GetFabricType(int pageTypeCode) {
    switch (pageTypeCode) {
        case Application::GetPageTypeCode<ManCtrl_Light::TPage>():
            return "ManCtrl_Light::Fabric";
        case Application::GetPageTypeCode<ManCtrl_Pump::TPage>():
            return "ManCtrl_Pump::Fabric";
        default:
            return "Unknown";
    }
}
