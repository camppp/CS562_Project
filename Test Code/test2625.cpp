#include <iostream>
#include <string>
#include <cassert>
#include "twisted_works/cli_parser.h"
#include <GL/gl.h>

class validation_parameters {
public:
    validation_parameters(const twisted_works::cli_parser& CommandLine);
    std::string file_path;
    GLenum profile;
};

validation_parameters::validation_parameters(const twisted_works::cli_parser& CommandLine)
{
    assert(CommandLine.anonymous_argument_count() > 0); // Check if there is at least one anonymous argument
    file_path = CommandLine.anonymous_argument(0); // Store the first anonymous argument as the file path
    profile = 0; // Initialize profile to 0
    const std::string ProfileString = CommandLine.argument("profile"); // Retrieve the value of the "profile" argument
    if (ProfileString == "vertex") {
        profile = GL_VERTEX_SHADER; // Set profile to GL_VERTEX_SHADER if the "profile" argument value is "vertex"
    }
}

int main() {
    twisted_works::cli_parser commandLineParser; // Assume the existence of twisted_works::cli_parser and its usage
    commandLineParser.parse_arguments(argc, argv); // Assume argc and argv are passed to the program
    validation_parameters params(commandLineParser); // Create an instance of validation_parameters using the command line parser
    // Further processing using the extracted parameters
    return 0;
}
