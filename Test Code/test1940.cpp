#include <cstdio>

enum class ELoggerLevel
{
    INFO,
    WARNING,
    ERROR
};

using Char = char; // Assuming Char is a typedef for char

class ToolLogger
{
public:
    void log(ELoggerLevel _level, uint32_t _flag, uint32_t _color, const Char* _data, size_t _size)
    {
        // Ignoring the unused parameters
        (void)_level;
        (void)_flag;
        (void)_color;

        // Printing the log message data using printf
        printf("%.*s", static_cast<int>(_size), _data);
    }
};

int main()
{
    ToolLogger logger;
    const char* message = "This is a log message.";
    size_t messageSize = strlen(message);

    // Example usage
    logger.log(ELoggerLevel::INFO, 0, 0, message, messageSize);

    return 0;
}
