#include <iostream>
#include <string>
#include <locale>

class StringUtility {
public:
    static bool AreEqualCaseInsensitive(const std::wstring& str1, const std::wstring& str2) {
        return (str1.size() == str2.size() &&
                std::equal(str1.begin(), str1.end(), str2.begin(),
                           [](wchar_t c1, wchar_t c2) {
                               return std::tolower(c1, std::locale()) == std::tolower(c2, std::locale());
                           }));
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
    TraceKeywords result;
    if (StringUtility::AreEqualCaseInsensitive(testKeyword, L"Test1")) {
        result = TraceKeywords::Test1;
    } else if (StringUtility::AreEqualCaseInsensitive(testKeyword, L"Test2")) {
        result = TraceKeywords::Test2;
    } else if (StringUtility::AreEqualCaseInsensitive(testKeyword, L"Test3")) {
        result = TraceKeywords::Test3;
    } else {
        result = TraceKeywords::Unknown;
    }

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
