#include <iostream>
#include <cstring>

wchar_t* ReverseWideString(const wchar_t* data) {
    size_t length = wcslen(data);
    wchar_t* reversed = new wchar_t[length + 1];

    for (size_t i = 0; i < length; i++) {
        reversed[i] = data[length - 1 - i];
    }
    reversed[length] = L'\0';

    return reversed;
}
