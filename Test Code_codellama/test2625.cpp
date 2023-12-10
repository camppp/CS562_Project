#include <string>
#include <vector>
#include <twisted_works/cli_parser.h>

class validation_parameters {
public:
    validation_parameters(const twisted_works::cli_parser& parser) {
        // Check if there is at least one anonymous argument provided in the command line
        if (parser.anonymous_arguments().empty()) {
            throw std::invalid_argument("No file path provided");
        }

        // Store the first anonymous argument as the file path
        file_path = parser.anonymous_arguments().front();

        // Initialize the profile variable to 0
        profile = 0;

        // Retrieve the value of the "profile" argument from the command line and set the profile variable based on the value
        if (parser.has_option("profile")) {
            profile = std::stoi(parser.get_option("profile"));
        }
    }

private:
    std::string file_path;
    int profile;
};
