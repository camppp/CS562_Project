class MyString {
public:
    MyString() {}
    MyString(const char* str) {
        // Copy the contents of the C-style string into the MyString object
        for (int i = 0; i < strlen(str); i++) {
            this->str[i] = str[i];
        }
        this->str[strlen(str)] = '\0';
    }
    MyString(const MyString& other) {
        // Copy the contents of the other MyString object into this one
        for (int i = 0; i < other.length(); i++) {
            this->str[i] = other.str[i];
        }
        this->str[other.length()] = '\0';
    }
    MyString& operator=(const MyString& other) {
        // Copy the contents of the other MyString object into this one
        for (int i = 0; i < other.length(); i++) {
            this->str[i] = other.str[i];
        }
        this->str[other.length()] = '\0';
        return *this;
    }
    MyString operator+(const MyString& other) {
        // Concatenate the contents of the two MyString objects
        MyString result;
        for (int i = 0; i < this->length(); i++) {
            result.str[i] = this->str[i];
        }
        for (int i = 0; i < other.length(); i++) {
            result.str[i + this->length()] = other.str[i];
        }
        result.str[this->length() + other.length()] = '\0';
        return result;
    }
    bool operator==(const MyString& other) {
        // Compare the contents of the two MyString objects
        if (this->length() != other.length()) {
            return false;
        }
        for (int i = 0; i < this->length(); i++) {
            if (this->str[i] != other.str[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator!=(const MyString& other) {
        return !(*this == other);
    }
    char operator[](int index) {
        // Return the character at the specified index
        return this->str[index];
    }
private:
    char str[100];
};
