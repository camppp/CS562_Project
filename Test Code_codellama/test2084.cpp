class NativeBuffer {
public:
    // Constructor and other necessary methods can be assumed to be present

    // Writes a float value to the buffer
    bool writeFloat(const float c) {
        // Write the float value to the buffer
        append(reinterpret_cast<const char*>(&c), sizeof(c));
        return true;
    }

    // Writes a string with its length to the buffer
    bool writeString(const unsigned short len, const char *c) {
        // Write the string length to the buffer
        append(reinterpret_cast<const char*>(&len), sizeof(len));
        // Write the string to the buffer
        append(c, len);
        return true;
    }

    // Writes a string without its length to the buffer
    bool writeStringNoLen(const unsigned short len, const char *c) {
        // Write the string to the buffer
        append(c, len);
        return true;
    }

private:
    // The data buffer
    std::vector<char> data_;

    // Appends the given data to the buffer and returns the number of bytes appended
    int append(const char* data, size_t size) {
        // Check if there is enough space in the buffer
        if (data_.size() + size > data_.capacity()) {
            return -1;
        }

        // Append the data to the buffer
        std::copy(data, data + size, std::back_inserter(data_));
        return size;
    }
};
