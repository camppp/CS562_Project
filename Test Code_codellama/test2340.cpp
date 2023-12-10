#include <string>
#include <cstring>

bool match_file_type(const std::string& file_path, const std::string& file_type_pattern) {
    // Check if the file type pattern contains a wildcard
    if (file_type_pattern.find('*') == std::string::npos) {
        // If not, compare the file type pattern with the file path
        return file_path.compare(file_type_pattern) == 0;
    } else {
        // If the file type pattern contains a wildcard, extract the file extension
        size_t pos = file_path.find_last_of('.');
        if (pos == std::string::npos) {
            // If the file path does not have an extension, return false
            return false;
        }
        std::string file_extension = file_path.substr(pos + 1);

        // Compare the file extension with the file type pattern
        return file_extension.compare(file_type_pattern.substr(1)) == 0;
    }
}
