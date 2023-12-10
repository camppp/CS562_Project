#include <filesystem>

namespace file_util {

    uintmax_t getTotalFileSize(const std::string& directoryPath) {
        std::filesystem::path dirPath(directoryPath);
        uintmax_t totalSize = 0;

        if (std::filesystem::exists(dirPath) && std::filesystem::is_directory(dirPath)) {
            for (const auto& entry : std::filesystem::directory_iterator(dirPath)) {
                if (std::filesystem::is_regular_file(entry.path())) {
                    totalSize += std::filesystem::file_size(entry.path());
                }
            }
        }

        return totalSize;
    }

}  // namespace file_util
