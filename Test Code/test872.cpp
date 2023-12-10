#include <iostream>
#include <string>

class StringUtility {
public:
    static bool AreEqualCaseInsensitive(const std::wstring& str1, const std::wstring& str2) {
        return std::equal(str1.begin(), str1.end(), str2.begin(), str2.end(), [](wchar_t c1, wchar_t c2) {
            return std::toupper(c1) == std::toupper(c2);
        });
    }
};

enum class TraceKeywords {
    Test1,
    Test2,
    Test3,
    Unknown
};

int main() {
    std::wstring testKeyword = L"test1";
    TraceKeywords result = StringUtility::AreEqualCaseInsensitive(testKeyword, L"Test1");
    switch (result) {
        case TraceKeywords::Test1:
            std::cout << "Matched Test1" << std::endl;
            break;
        case TraceKeywords::Test2:
            std::cout << "Matched Test2" << std::endl;
            break;
        case TraceKeywords::Test3:
            std::cout << "Matched Test3" << std::endl;
            break;
        case TraceKeywords::Unknown:
            std::cout << "Unknown keyword" << std::endl;
            break;
    }
    return 0;
}
