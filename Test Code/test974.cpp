#include <iostream>
#include <string>

std::wstring GetFileExtension(const std::wstring& filename) {
    size_t dotPos = filename.find_last_of(L".");
    if (dotPos != std::wstring::npos && dotPos < filename.length() - 1) {
        return filename.substr(dotPos + 1);
    }
    return L"";
}

int main() {
    std::wstring filename = L"document.txt";
    std::wstring extension = GetFileExtension(filename);
    std::wcout << L"File extension: " << extension << std::endl;
    return 0;
}
