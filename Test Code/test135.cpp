#include <string>

class StringInputStream {
private:
    const std::string& input;
    size_t position;

public:
    // Constructor to initialize the input string and position
    StringInputStream(const std::string& str) : input(str), position(0) {}

    // Function to read the next character from the input string
    char get() {
        if (position < input.size()) {
            return input[position++];
        }
        return '\0';  // Return null character if end of string is reached
    }

    // Function to check if the end of the input string has been reached
    bool isEnd() {
        return position >= input.size();
    }
};
