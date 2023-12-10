#include <yaml-cpp/yaml.h>
#include <filesystem>

class SpecialFileDirGen {
public:
    SpecialFileDirGen(YAML::Node config) : config_(config) {}

    void RemoveExistingSFDir() {
        std::filesystem::path directoryPath = "/src.lib/kernel/specialFiles";
        for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
            if (entry.is_regular_file()) {
                std::filesystem::remove(entry.path());
            }
        }
    }

private:
    YAML::Node config_;
};

int main() {
    // Example usage
    YAML::Node config = YAML::LoadFile("config.yaml");
    SpecialFileDirGen specialFileDirGen(config);
    specialFileDirGen.RemoveExistingSFDir();
    return 0;
}
