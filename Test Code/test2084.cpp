#include <string>

class NativeBuffer {
private:
    std::string data_;

public:
    // Constructor and other necessary methods can be assumed to be present

    bool writeFloat(const float c) {
        // Assuming writeType method is implemented to write the float value
        return writeType(c);
    }

    bool writeString(const unsigned short len, const char *c) {
        if (writeType(len))  // Assuming writeType method is implemented to write the length
            return data_.append(c, len) >= 0;  // Append the string to the buffer and check for success
        else
            return false;
    }

    bool writeStringNoLen(const unsigned short len, const char *c) {
        return data_.append(c, len) > 0;  // Append the string to the buffer and check for success
    }
};
