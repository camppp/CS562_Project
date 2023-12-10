#include <iostream>

template <typename CharT>
struct custom_char_traits : public std::char_traits<CharT> {
    using char_type = CharT;

    static int compare(const char_type* s1, const char_type* s2, size_t n) {
        for (size_t i = 0; i < n; ++i) {
            if (s1[i] < s2[i]) return -1;
            if (s1[i] > s2[i]) return 1;
        }
        return 0;
    }

    static char_type* copy(char_type* dest, const char_type* src, size_t n) {
        for (size_t i = 0; i < n; ++i) {
            dest[i] = src[i];
        }
        return dest;
    }

    static char_type* assign(char_type* dest, size_t n, char_type a) {
        for (size_t i = 0; i < n; ++i) {
            dest[i] = a;
        }
        return dest;
    }

    static const char_type* find(const char_type* s, size_t n, const char_type& a) {
        for (size_t i = 0; i < n; ++i) {
            if (s[i] == a) return &s[i];
        }
        return nullptr;
    }
};

int main() {
    using traits = custom_char_traits<char>;
    char str1[] = "Hello";
    char str2[] = "World";
    
    std::cout << "Comparison: " << traits::compare(str1, str2, 3) << std::endl;
    
    char dest[6];
    traits::copy(dest, str1, 5);
    std::cout << "Copy: " << dest << std::endl;
    
    char assign_dest[6];
    traits::assign(assign_dest, 5, 'A');
    std::cout << "Assign: " << assign_dest << std::endl;
    
    const char* found = traits::find(str1, 5, 'l');
    if (found != nullptr) {
        std::cout << "Found: " << *found << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
    
    return 0;
}
