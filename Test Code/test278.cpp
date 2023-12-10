#include <iostream>
#include <filesystem>
#include <regex>

void LoadPluginsInFolderName(const std::string& folderName, const std::string& filter)
{
    std::filesystem::path folderPath(folderName);

    if (std::filesystem::exists(folderPath) && std::filesystem::is_directory(folderPath))
    {
        std::regex pluginFilter(filter);

        for (const auto& entry : std::filesystem::directory_iterator(folderPath))
        {
            if (std::regex_match(entry.path().filename().string(), pluginFilter))
            {
                // Load the plugin from the entry.path()
                std::cout << "Loading plugin: " << entry.path().filename() << std::endl;
            }
        }
    }
    else
    {
        std::cerr << "Error: Folder does not exist or is not a directory" << std::endl;
    }
}
