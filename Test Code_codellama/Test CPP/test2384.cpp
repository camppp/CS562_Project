#include <string>
#include <cstdlib>
#include <cstring>

EXPORT_API std::string GetProjectPathUtf8()
{
    // Get the project path in UTF-16 encoding
    std::wstring projectPathUtf16 = GetProjectPathUtf16();

    // Convert the project path from UTF-16 to UTF-8
    std::string projectPathUtf8;
    if (projectPathUtf16.empty())
    {
        projectPathUtf8 = "";
    }
    else
    {
        projectPathUtf8 = std::string(projectPathUtf16.begin(), projectPathUtf16.end());
    }

    return projectPathUtf8;
}
