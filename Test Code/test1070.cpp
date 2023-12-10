#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, string> parsePeripheralConstants(const string& code) {
    map<string, string> peripherals;

    // Split the code into lines
    vector<string> lines = split(code, '\n');

    // Iterate over the lines
    for (const string& line : lines) {
        // Check if the line starts with "#if defined"
        if (line.find("#if defined") == 0) {
            // Extract the peripheral name and value from the line
            string peripheral = line.substr(12, line.find("=") - 12);
            string value = line.substr(line.find("=") + 1);

            // Add the peripheral and value to the map
            peripherals[peripheral] = value;
        }
    }

    return peripherals;
}

int main() {
    string code = "#if defined(STM32F405xx) || defined(STM32F415xx) || defined(STM32F407xx) || defined(STM32F417xx) || defined(STM32F401xC) || defined(STM32F401xE) || defined(STM32F411xE)\n"
                  "    PLLI2S     = 0x04,\n"
                  "#endif\n"
                  "#if defined(STM32F401xC) || defined(STM32F401xE) || defined(STM32F411xE)\n"
                  "    RTC        = 0x08,\n"
                  "#endif";

    map<string, string> peripherals = parsePeripheralConstants(code);

    for (const auto& p : peripherals) {
        cout << p.first << " = " << p.second << endl;
    }

    return 0;
}
