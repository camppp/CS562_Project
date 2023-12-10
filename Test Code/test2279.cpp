#include <iostream>
#include <string>
#include <sstream>

bool CompareVersions(const std::wstring& fileVersion, const std::wstring& productVersion) {
    // Extract version numbers from the strings
    int fileMajor, fileMinor, productMajor, productMinor;
    wchar_t v;
    std::wistringstream fileStream(fileVersion), productStream(productVersion);
    fileStream >> v >> fileMajor >> v >> fileMinor;
    productStream >> v >> productMajor >> v >> productMinor;

    // Compare the versions
    if (productMajor > fileMajor) {
        return true;
    } else if (productMajor == fileMajor && productMinor > fileMinor) {
        return true;
    }
    return false;
}

int main() {
    std::wstring wsz_SAMPLE_FILEVER = L"v 1.0";
    std::wstring wsz_SAMPLE_PRODUCTVER = L"v 5.00";
    if (CompareVersions(wsz_SAMPLE_FILEVER, wsz_SAMPLE_PRODUCTVER)) {
        std::wcout << L"The product version is greater than the file version." << std::endl;
    } else {
        std::wcout << L"The product version is not greater than the file version." << std::endl;
    }
    return 0;
}
