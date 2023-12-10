#include <QString>
#include <string>

// Predefined string to compare with
const char* stop_str = "exmpl";

bool compareConvertedString(QString input) {
    // Convert input string to specific format using toch function
    std::string converted_str = toch(input).toStdString();

    // Compare converted string with predefined string
    if (converted_str == stop_str) {
        return true;
    } else {
        return false;
    }
}
