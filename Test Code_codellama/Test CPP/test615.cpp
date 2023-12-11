#include <iostream>

template <typename CharType>
struct MyCharTraits {
    using char_type = CharType;

    static int compare(const char_type* s1, const char_type* s2, size_t n) {
        for (size_t i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                return s1[i] < s2[i] ? -1 : 1;
            }
        }
        return 0;
    }

    static char_type* copy(char_type* dest, const char_type* src, size_t n) {
        for (size_t i = 0; i < n; i++) {
            dest[i] = src[i];
        }
        return dest;
    }

    static char_type* assign(char_type* dest, size_t n, char_type a) {
        for (size_t i = 0; i < n; i++) {
            dest[i] = a;
        }
        return dest;
    }

    static const char_type* find(const char_type* s, size_t n, const char_type& a) {
        for (size_t i = 0; i < n; i++) {
            if (s[i] == a) {
                return &s[i];
            }
        }
        return nullptr;
    }
};

int main() {
    MyCharTraits<char> traits;

    char s1[] = "hello";
    char s2[] = "world";

    std::cout << traits.compare(s1, s2, 5) << std::endl;
    std::cout << traits.copy(s1, s2, 5) << std::endl;
    std::cout << traits.assign(s1, 5, 'a') << std::endl;
    std::cout << traits.find(s1, 5, 'l') << std::endl;

    return 0;
}
