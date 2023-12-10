#include <string>
#include <codecvt>
#include <locale>

std::string FromWideString(const std::u16string& str) {
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
    return converter.to_bytes(str);
}

std::u16string ToWideString(const std::string& str) {
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
    return converter.from_bytes(str);
}
