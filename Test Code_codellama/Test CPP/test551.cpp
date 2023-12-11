#include <string>
#include <vector>
#include <tuple>

class ArgumentList {
public:
    ArgumentList(const std::vector<std::string>& args);
    void addArgument(const std::string& arg);
    const std::vector<std::string>& getArguments() const;
};

std::tuple<std::string, std::string, ArgumentList> parseLine(const std::string& line) {
    // Split the input line into three parts using the '|' character as a delimiter
    std::vector<std::string> parts = split(line, '|');

    // Extract the first and second strings from the input line
    std::string firstString = parts[0];
    std::string secondString = parts[1];

    // Create a new ArgumentList object and add the remaining arguments to it
    ArgumentList args;
    for (int i = 2; i < parts.size(); i++) {
        args.addArgument(parts[i]);
    }

    // Return the extracted components as a tuple
    return std::make_tuple(firstString, secondString, args);
}
