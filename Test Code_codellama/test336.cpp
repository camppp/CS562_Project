#include <cstddef>
#include <string>

class CustomStringView {
public:
    CustomStringView(const char* str) : str_(str) {}

    size_t length() const { return strlen(str_); }

    const char* data() const { return str_; }

    bool operator==(const CustomStringView& other) const {
        return strcmp(str_, other.str_) == 0;
    }

    CustomStringView substr(size_t pos, size_t len) const {
        return CustomStringView(str_ + pos, len);
    }

    size_t find(const char* substr) const {
        return strstr(str_, substr) - str_;
    }

private:
    const char* str_;
};
