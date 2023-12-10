#include <vector>
#include <string>

// Given function to obtain the configuration enum value names
std::vector<std::string> determineConfigEnumValueNames(const char *stringizedMacroVarags)
{
    // Implementation not provided
}

// Function to be completed
std::vector<char> determineConfigEnumValueNamesZeroSeparated(const char *stringizedMacroVarags)
{
    std::vector<char> valueNames;

    // Obtain the configuration enum value names using determineConfigEnumValueNames function
    std::vector<std::string> enumValueNames = determineConfigEnumValueNames(stringizedMacroVarags);

    // Separate the value names with null characters and store in valueNames vector
    for (const std::string& name : enumValueNames)
    {
        for (char c : name)
        {
            valueNames.push_back(c);
        }
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
