#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>

class ArgError : public std::runtime_error {
public:
    ArgError(const std::string& message) : std::runtime_error(message) {}
};

std::map<std::string, std::string> parseArgs(const std::vector<std::string>& args) {
    std::map<std::string, std::string> options;
    for (size_t i = 0; i < args.size(); ++i) {
        if (args[i] == "--search") {
            if (i == args.size() - 1) {
                throw ArgError("missing argument after --search");
            }
            options[args[i]] = args[i + 1];
            ++i;
        } else if (args[i] == "--file") {
            if (i == args.size() - 1) {
                throw ArgError("missing argument after --file");
            }
            options[args[i]] = args[i + 1];
            ++i;
        } else if (args[i] == "--help") {
            // Display help message and usage instructions
            std::cout << "Usage: program_name [options]\n"
                         "Options:\n"
                         "  --search <query>  Perform a search with the specified query\n"
                         "  --file <filename> Specify the file to be processed\n"
                         "  --help            Display this help message\n";
            // No further processing needed for --help option
            return options;
        } else {
            throw ArgError("unknown option: " + args[i]);
        }
    }
    return options;
}

int main() {
    try {
        std::vector<std::string> arguments = { "--search", "keyword", "--file", "example.txt" };
        std::map<std::string, std::string> parsedArgs = parseArgs(arguments);
        for (const auto& pair : parsedArgs) {
            std::cout << pair.first << " : " << pair.second << std::endl;
        }
    } catch (const ArgError& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
