#include <sstream>
#include <string>

bool compare_streams(const std::stringstream& first, const std::stringstream& second) {
    // Get the content of the streams as strings
    std::string firstContent = first.str();
    std::string secondContent = second.str();

    // Compare the content of the streams
    return firstContent == secondContent;
}
