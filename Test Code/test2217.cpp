#include <cstring>

class SimpleString {
  private:
    const char* p_;

  public:
    // Constructor
    SimpleString(const char* str) : p_(str) {}

    // Method to return the length of the string
    size_t length() const {
        return strlen(p_);
    }

    // Method to return the character at a specified index in the string
    char charAt(size_t index) const {
        if (index < length()) {
            return p_[index];
        } else {
            // Handle out-of-bounds index
            return '\0';
        }
    }

    // Method to concatenate another string to the current string and return a new string object
    SimpleString concatenate(const char* str) const {
        size_t totalLength = length() + strlen(str);
        char* newString = new char[totalLength + 1];
        strcpy(newString, p_);
        strcat(newString, str);
        SimpleString result(newString);
        delete[] newString;
        return result;
    }
};
