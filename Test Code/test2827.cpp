#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class clang {
public:
    clang() {}

    void push_args(const std::vector<std::string>& args) {
        for (const auto& arg : args) {
            if (arg.substr(0, 2) == "--") {
                parse_long_option(arg);
            } else if (arg[0] == '-') {
                parse_short_option(arg);
            } else {
                // Handle non-option arguments
                non_option_args.push_back(arg);
            }
        }
    }

    void parse_long_option(const std::string& arg) {
        size_t equals_pos = arg.find('=');
        std::string option, value;
        if (equals_pos != std::string::npos) {
            option = arg.substr(2, equals_pos - 2);
            value = arg.substr(equals_pos + 1);
        } else {
            option = arg.substr(2);
        }
        long_options[option] = value;
    }

    void parse_short_option(const std::string& arg) {
        for (size_t i = 1; i < arg.length(); ++i) {
            if (i + 1 < arg.length() && arg[i + 1] == '=') {
                short_options[arg[i]] = arg.substr(i + 2);
                break;
            } else {
                short_options[arg[i]] = "";
            }
        }
    }

    const std::unordered_map<std::string, std::string>& get_long_options() const {
        return long_options;
    }

    const std::unordered_map<char, std::string>& get_short_options() const {
        return short_options;
    }

    const std::vector<std::string>& get_non_option_args() const {
        return non_option_args;
    }

private:
    std::unordered_map<std::string, std::string> long_options;
    std::unordered_map<char, std::string> short_options;
    std::vector<std::string> non_option_args;
};

int main() {
    clang scanner_;
    scanner_.push_args({ "-w", "--file=output.txt", "input.txt" });

    const auto& long_options = scanner_.get_long_options();
    const auto& short_options = scanner_.get_short_options();
    const auto& non_option_args = scanner_.get_non_option_args();

    std::cout << "Long Options:" << std::endl;
    for (const auto& option : long_options) {
        std::cout << option.first << " : " << option.second << std::endl;
    }

    std::cout << "Short Options:" << std::endl;
    for (const auto& option : short_options) {
        std::cout << option.first << " : " << option.second << std::endl;
    }

    std::cout << "Non-option Arguments:" << std::endl;
    for (const auto& arg : non_option_args) {
        std::cout << arg << std::endl;
    }

    return 0;
}
