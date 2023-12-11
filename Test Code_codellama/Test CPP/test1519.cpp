#include <iostream>

struct zGlobalSettings
{
    uint16 AnalogMin;
    // other configuration parameters
};

void initializeDefaultSettings(zGlobalSettings& settings)
{
    settings.AnalogMin = 0;
    // other default settings
}

void updateSetting(zGlobalSettings& settings, uint16 settingId, uint16 newValue)
{
    switch (settingId)
    {
        case 0:
            settings.AnalogMin = newValue;
            break;
        // other settings
        default:
            std::cout << "Invalid setting ID" << std::endl;
            break;
    }
}

int main()
{
    zGlobalSettings settings;
    initializeDefaultSettings(settings);
    std::cout << "Default settings:" << std::endl;
    std::cout << "AnalogMin: " << settings.AnalogMin << std::endl;
    // other default settings

    uint16 newAnalogMin = 100;
    updateSetting(settings, 0, newAnalogMin);
    std::cout << "Updated settings:" << std::endl;
    std::cout << "AnalogMin: " << settings.AnalogMin << std::endl;
    // other updated settings

    return 0;
}
