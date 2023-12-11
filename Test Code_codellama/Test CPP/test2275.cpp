#include <vector>
#include <string>

// Given function to obtain the configuration enum value names
std::vector<std::string> determineConfigEnumValueNames(const char *stringizedMacroVarargs)
{
    // Implementation not provided
}

// Function to be completed
std::vector<char> determineConfigEnumValueNamesZeroSeparated(const char *stringizedMacroVarargs)
{
    std::vector<char> valueNames;

    // Complete the implementation using determineConfigEnumValueNames function
    std::vector<std::string> valueNameStrings = determineConfigEnumValueNames(stringizedMacroVarargs);
    for (const std::string& valueName : valueNameStrings)
    {
        valueNames.insert(valueNames.end(), valueName.begin(), valueName.end());
        valueNames.push_back('\0');
    }

    return valueNames;
}

int main()
{
    const char *macroVarargs = "VALUE1, VALUE2, VALUE3";
    std::vector<char> result = determineConfigEnumValueNamesZeroSeparated(macroVarargs);

    // Output the result
    for (char c : result)
    {
        if (c == '\0')
            std::cout << " ";
        else
            std::cout << c;
    }

    return 0;
}
