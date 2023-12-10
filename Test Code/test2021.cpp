#include <string>
#include <cstdio>

template <typename T>
std::string to_string(T Val) {
    char buf[32]; // Assuming a maximum of 32 characters for the string representation
    if constexpr (std::is_same_v<T, int>) {
        sprintf_s(buf, sizeof(buf), "%i", Val);
    } else if constexpr (std::is_same_v<T, unsigned int>) {
        sprintf_s(buf, sizeof(buf), "%u", Val);
    } else if constexpr (std::is_same_v<T, long>) {
        sprintf_s(buf, sizeof(buf), "%li", Val);
    } else if constexpr (std::is_same_v<T, short>) {
        sprintf_s(buf, sizeof(buf), "%hi", Val);
    } else if constexpr (std::is_same_v<T, unsigned short>) {
        sprintf_s(buf, sizeof(buf), "%hu", Val);
    } else if constexpr (std::is_same_v<T, long long>) {
        sprintf_s(buf, sizeof(buf), "%lli", Val);
    } else if constexpr (std::is_same_v<T, unsigned long>) {
        sprintf_s(buf, sizeof(buf), "%lu", Val);
    } else if constexpr (std::is_same_v<T, unsigned long long>) {
        sprintf_s(buf, sizeof(buf), "%llu", Val);
    }
    return buf;
}
