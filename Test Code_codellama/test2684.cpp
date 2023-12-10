#include <iostream>
#include <string>

void extract_condition(const std::string& header_file_snippet) {
    // Find the #ifndef directive
    size_t ifndef_pos = header_file_snippet.find("#ifndef");
    if (ifndef_pos != std::string::npos) {
        // Extract the condition from the #ifndef directive
        size_t condition_pos = ifndef_pos + sizeof("#ifndef") - 1;
        std::string condition = header_file_snippet.substr(condition_pos, header_file_snippet.find(" ", condition_pos) - condition_pos);
        std::cout << "Condition used in #ifndef directive: " << condition << std::endl;
    }

    // Find the #define directive
    size_t define_pos = header_file_snippet.find("#define");
    if (define_pos != std::string::npos) {
        // Extract the condition from the #define directive
        size_t condition_pos = define_pos + sizeof("#define") - 1;
        std::string condition = header_file_snippet.substr(condition_pos, header_file_snippet.find(" ", condition_pos) - condition_pos);
        std::cout << "Condition used in #define directive: " << condition << std::endl;
    }
}

int main() {
    std::string header_file_snippet = "#ifndef TrackerConditions_Mu2eDetector_hh\n"
                                      "#define TrackerConditions_Mu2eDetector_hh\n"
                                      "// ... other code\n"
                                      "#endif /* TrackerConditions_Mu2eDetector_hh */";
    extract_condition(header_file_snippet);
    return 0;
}
