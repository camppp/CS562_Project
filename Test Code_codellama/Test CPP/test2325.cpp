#include <filesystem>

namespace file_util {

    uintmax_t getTotalFileSize(const std::string& directoryPath) {
        uintmax_t totalSize = 0;
        for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
            if (entry.is_regular_file()) {
                totalSize += entry.file_size();
            }
        }
        return totalSize;
    }

}  // namespace file_util
