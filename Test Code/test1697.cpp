#include <cstring>

class CustomString {
public:
    CustomString() : length_(0), data_(nullptr) {}

    CustomString(const char* s) : length_(strlen(s)), data_(new char[length_ + 1]) {
        std::strcpy(data_, s);
    }

    ~CustomString() {
        delete[] data_;
    }

    size_t length() const {
        return length_;
    }

    char& operator[](size_t index) {
        return data_[index];
    }

    CustomString& operator+=(const CustomString& other) {
        size_t new_length = length_ + other.length_;
        char* new_data = new char[new_length + 1];
        std::strcpy(new_data, data_);
        std::strcat(new_data, other.data_);
        delete[] data_;
        data_ = new_data;
        length_ = new_length;
        return *this;
    }

    bool operator==(const CustomString& other) const {
        return std::strcmp(data_, other.data_) == 0;
    }

private:
    size_t length_;
    char* data_;
};
