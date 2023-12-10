#include <iostream>
#include <fstream>
#include <yaml-cpp/yaml.h>

class SpecialFileDirGen {
public:
    SpecialFileDirGen(YAML::Node config) {
        // Read the configuration file and perform various checks and formatting operations
        // ...
    }

    void RemoveExistingSFDir() {
        // Remove all files inside the '/src.lib/kernel/specialFiles' directory
        std::string dir = "/src.lib/kernel/specialFiles";
        for (auto& file : std::filesystem::directory_iterator(dir)) {
            std::cout << "Removing file: " << file.path() << std::endl;
            std::filesystem::remove(file.path());
        }
    }
};
