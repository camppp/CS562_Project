class MyString {
public:
    MyString(const char* str) {
        // Initialize the string with the given character array
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    ~MyString() {
        // Free the memory allocated for the string
        delete[] data;
    }

    int length() const {
        // Return the length of the string
        return length;
    }

    MyString concatenate(const MyString& other) const {
        // Concatenate two strings
        MyString result(data);
        result.append(other.data);
        return result;
    }

    MyString substring(int start, int length) const {
        // Return a substring of the string based on the start index and length provided
        MyString result(data + start, length);
        return result;
    }

private:
    int length;
    char* data;
};
