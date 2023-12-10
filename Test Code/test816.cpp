#include <iostream>
#include <string>
#include <unordered_map>

// Define a custom type for the configuration object
using xconfiguration = std::unordered_map<std::string, std::unordered_map<std::string, std::string>>;

std::string extract_language_info(const xconfiguration& config)
{
    std::string language_info;

    // Extract language information from the configuration object
    std::string language_name = "Custom Language";  // Replace with actual language name
    std::string version = config.at("language_info").at("version");
    std::string mimetype = config.at("language_info").at("mimetype");
    std::string file_extension = config.at("language_info").at("file_extension");

    // Format the extracted language information
    language_info = "Language: " + language_name + "\n"
                    + "Version: " + version + "\n"
                    + "Mimetype: " + mimetype + "\n"
                    + "File Extension: " + file_extension;

    return language_info;
}

int main()
{
    // Sample usage of the extract_language_info function
    xconfiguration sample_config = {
        {"language_info", {
            {"version", "2018"},
            {"mimetype", "text/x-fortran"},
            {"file_extension", ".f90"}
        }}
    };

    std::string language_info = extract_language_info(sample_config);
    std::cout << language_info << std::endl;

    return 0;
}
