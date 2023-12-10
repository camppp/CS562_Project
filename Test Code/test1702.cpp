#include <iostream>
#include <string>
#include <vector>
#include <mutex>

class CLog {
public:
    CLog(const std::string& log_level) : log_level_(log_level) {}

    void Warn(const std::string& message, ...) {
        // Format the log message with variable arguments
        va_list args;
        va_start(args, message);
        std::string formatted_message = format_message(message, args);
        va_end(args);

        // Log the message
        std::lock_guard<std::mutex> lock(mutex_);
        std::cout << "[" << log_level_ << "] " << formatted_message << std::endl;
    }

private:
    std::string log_level_;
    std::mutex mutex_;

    std::string format_message(const std::string& message, va_list args) {
        // Format the log message with variable arguments
        std::string formatted_message = message;
        for (int i = 0; i < 10; i++) {
            formatted_message = formatted_message.replace(i, 1, std::to_string(va_arg(args, int)));
        }
        return formatted_message;
    }
};
