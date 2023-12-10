#include <string_view>
#include <fmt/format.h>

class Logger {
public:
    explicit Logger(std::string_view ctx) : context(ctx) {}

    void info(std::string_view message) {
        log("INFO", message);
    }

    void warning(std::string_view message) {
        log("WARNING", message);
    }

    void error(std::string_view message) {
        log("ERROR", message);
    }

private:
    std::string_view context;

    void log(std::string_view level, std::string_view message) {
        fmt::print("[{}] [{}] {}\n", context, level, message);
    }
};

int main() {
    Logger logger("Main");
    logger.info("This is an informational message.");
    logger.warning("This is a warning message.");
    logger.error("This is an error message.");
    return 0;
}
