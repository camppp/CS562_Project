class CustomString {
public:
    CustomString() {
        // Default constructor
        str = "";
    }

    CustomString(const char* s) {
        // Parameterized constructor
        str = s;
    }

    int length() {
        // Method to return the length of the string
        return str.length();
    }

    void append(const CustomString& other) {
        // Method to append a CustomString to the end of the current CustomString
        str += other.str;
    }

    const char* c_str() {
        // Method to return a pointer to a null-terminated character array representing the CustomString
        return str.c_str();
    }

private:
    std::string str;
};
