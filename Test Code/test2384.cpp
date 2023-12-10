#include <string>
#include <codecvt>
#include <locale>

// Function to retrieve the project path in UTF-8 encoding
EXPORT_API std::string GetProjectPathUtf8()
{
    // Retrieve the project path in UTF-16 encoding
    std::u16string utf16Path = Project::getInstance()->GetProjectPath();

    // Convert UTF-16 to UTF-8
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
    std::string utf8Path = converter.to_bytes(utf16Path);

    return utf8Path;
}
