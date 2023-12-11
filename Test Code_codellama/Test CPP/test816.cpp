#include <string>
#include <iostream>

using namespace std;

struct Configuration {
    string language_name;
    string version_number;
    string mimetype_value;
    string file_extension_value;
};

string extract_language_info(const Configuration& config) {
    string language_info;
    language_info += "Language: " + config.language_name + "\n";
    language_info += "Version: " + config.version_number + "\n";
    language_info += "Mimetype: " + config.mimetype_value + "\n";
    language_info += "File Extension: " + config.file_extension_value + "\n";
    return language_info;
}

int main() {
    Configuration config;
    config.language_name = "C++";
    config.version_number = "14";
    config.mimetype_value = "text/x-c++src";
    config.file_extension_value = "cpp";

    string language_info = extract_language_info(config);
    cout << language_info << endl;

    return 0;
}
