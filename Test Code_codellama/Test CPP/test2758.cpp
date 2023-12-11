#include <iostream>
#include <string_view>
#include <fmt/format.h>

class Logger {
public:
    Logger(std::string_view context) : context_(context) {}

    void info(std::string_view message) {
        log(fmt::format("{}: {}", context_, message));
    }

    void warning(std::string_view message) {
        log(fmt::format("{}: {}", context_, message));
    }

    void error(std::string_view message) {
        log(fmt::format("{}: {}", context_, message));
    }

private:
    void log(std::string_view message) {
        std::cout << message << std::endl;
    }

    std::string_view context_;
};
