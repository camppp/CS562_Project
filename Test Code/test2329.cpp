#include <iostream>
#include <string>
#include <vector>

enum class ModelType { Corpse, Weapon, Armor, Potion };

class Item {
public:
    virtual ModelType getType() const = 0;
    virtual std::string getName() const = 0;
};

class Mud {
public:
    static Mud& instance() {
        static Mud mudInstance;
        return mudInstance;
    }

    bool remItem(Item* item) {
        // Implement the logic to remove the item from the game world
        // Return true if the item is successfully removed, false otherwise
        // For simplicity, assume the item is always successfully removed
        return true;
    }
};

enum class LogLevel { Debug, Info, Warning, Error };

class Logger {
public:
    static void log(LogLevel level, const char* format, const std::string& itemName) {
        // Implement the logging logic based on the provided log level and item name
        // For simplicity, print the log message to the console
        std::cout << "Logging " << LogLevelToString(level) << ": " << format << " " << itemName << std::endl;
    }

private:
    static std::string LogLevelToString(LogLevel level) {
        switch (level) {
            case LogLevel::Debug:
                return "Debug";
            case LogLevel::Info:
                return "Info";
            case LogLevel::Warning:
                return "Warning";
            case LogLevel::Error:
                return "Error";
            default:
                return "Unknown";
        }
    }
};
