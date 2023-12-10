#include <iostream>
#include <string>

template<typename S, typename ... Strings>
std::string concatenate_strings(S s, Strings... strings) {
    std::string result = s;
    (result += ... += strings);
    return result;
}

int main() {
    std::string result = concatenate_strings("Hello, ", "world", "!", " This is a variadic template function.");
    std::cout << result << std::endl;  // Output: Hello, world! This is a variadic template function.
    return 0;
}
