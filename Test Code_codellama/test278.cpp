#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

void LoadPluginsInFolderName(const std::string& folderName, const std::string& filter)
{
    // Check if the folder exists
    if (!std::filesystem::exists(folderName))
    {
        std::cerr << "Folder " << folderName << " does not exist" << std::endl;
        return;
    }

    // Get the list of files in the folder
    std::vector<std::string> files;
    for (const auto& entry : std::filesystem::directory_iterator(folderName))
    {
        files.push_back(entry.path().string());
    }

    // Filter the files based on the filter string
    std::vector<std::string> filteredFiles;
    for (const auto& file : files)
    {
        if (file.find(filter) != std::string::npos)
        {
            filteredFiles.push_back(file);
        }
    }

    // Load the plugins
    for (const auto& file : filteredFiles)
    {
        // Load the plugin
        // ...
    }
}
