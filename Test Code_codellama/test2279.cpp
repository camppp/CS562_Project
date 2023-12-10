#include <iostream>
#include <string>
#include <sstream>

bool CompareVersions(const std::wstring& wsz_SAMPLE_FILEVER, const std::wstring& wsz_SAMPLE_PRODUCTVER)
{
    // Parse the version strings into integers
    std::wstringstream ss_FILEVER(wsz_SAMPLE_FILEVER);
    int file_major, file_minor;
    ss_FILEVER >> file_major >> file_minor;

    std::wstringstream ss_PRODUCTVER(wsz_SAMPLE_PRODUCTVER);
    int product_major, product_minor;
    ss_PRODUCTVER >> product_major >> product_minor;

    // Compare the major and minor versions
    if (product_major > file_major) {
        return true;
    } else if (product_major == file_major) {
        if (product_minor > file_minor) {
            return true;
        }
    }

    return false;
}

int main()
{
    std::wstring wsz_SAMPLE_FILEVER = L"v 1.0";
    std::wstring wsz_SAMPLE_PRODUCTVER = L"v 5.00";

    bool result = CompareVersions(wsz_SAMPLE_FILEVER, wsz_SAMPLE_PRODUCTVER);
    std::cout << "Product version is greater than file version: " << result << std::endl;

    return 0;
}
