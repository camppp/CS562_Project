#include <iostream>
#include <unordered_map>

class Application {
public:
    template <typename T>
    static int GetPageTypeCode() {
        // Implementation of GetPageTypeCode for specific control page types
        // ...
    }
};

class ManCtrl_Light {
public:
    using TPage = /* type definition for ManCtrl_Light control page */;
    static const std::string Fabric;
};

class ManCtrl_Pump {
public:
    using TPage = /* type definition for ManCtrl_Pump control page */;
    static const std::string Fabric;
};

const std::string ManCtrl_Light::Fabric = "ManCtrl_Light::Fabric";
const std::string ManCtrl_Pump::Fabric = "ManCtrl_Pump::Fabric";

std::string GetFabricType(int pageTypeCode) {
    std::unordered_map<int, std::string> fabricTypeMap = {
        {Application::GetPageTypeCode<ManCtrl_Light::TPage>(), ManCtrl_Light::Fabric},
        {Application::GetPageTypeCode<ManCtrl_Pump::TPage>(), ManCtrl_Pump::Fabric},
        {0, "Start flooding"}
    };

    auto it = fabricTypeMap.find(pageTypeCode);
    if (it != fabricTypeMap.end()) {
        return it->second;
    } else {
        return "Unknown";
    }
}

int main() {
    // Example usage
    std::cout << GetFabricType(Application::GetPageTypeCode<ManCtrl_Light::TPage>()) << std::endl; // Output: ManCtrl_Light::Fabric
    std::cout << GetFabricType(Application::GetPageTypeCode<ManCtrl_Pump::TPage>()) << std::endl; // Output: ManCtrl_Pump::Fabric
    std::cout << GetFabricType(123) << std::endl; // Output: Unknown
    return 0;
}
