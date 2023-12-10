#include <string>

std::string extractHeaderFileName(const std::string& fileContent) {
    std::string endIfDirective = "#endif";
    size_t pos = fileContent.rfind(endIfDirective);
    if (pos != std::string::npos) {
        size_t start = fileContent.rfind('/', pos);
        size_t end = fileContent.rfind("hpp", pos);
        if (start != std::string::npos && end != std::string::npos) {
            return fileContent.substr(start + 1, end - start - 1);
        }
    }
    return "";  // Handle invalid input or missing file name
}
